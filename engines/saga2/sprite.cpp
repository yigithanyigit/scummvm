/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * aint32 with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 * Based on the original sources
 *   Faery Tale II -- The Halls of the Dead
 *   (c) 1993-1996 The Wyrmkeep Entertainment Co.
 */

#define FORBIDDEN_SYMBOL_ALLOW_ALL // FIXME: Remove

#include "saga2/std.h"
#include "saga2/blitters.h"
#include "saga2/sprite.h"
#include "saga2/tcoords.h"
#include "saga2/input.h"
#include "saga2/cmisc.h"

namespace Saga2 {

const int           maxWeaponSpriteSets = 40;

const uint32        spriteGroupID   = RES_ID('S', 'P', 'R', 'I'),
                    frameGroupID    = RES_ID('F', 'R', 'M', 'L'),
                    poseGroupID     = RES_ID('P', 'O', 'S', 'E'),
                    schemeGroupID   = RES_ID('S', 'C', 'H', 'M'),
                    objectSpriteID  = RES_ID('O', 'B', 'J', 'S'),
                    mentalSpriteID  = RES_ID('M', 'E', 'N', 'T'),
                    weaponSpriteBaseID  = RES_ID('W', 'P', 'N', 0),
                    missileSpriteID = RES_ID('M', 'I', 'S', 'S');

/* ===================================================================== *
   Prototypes
 * ===================================================================== */

#ifndef FTAASM_H
extern void unpackSprite(gPixelMap *map, uint8 *sprData);
extern void compositePixels(
    gPixelMap       *compMap,
    gPixelMap       *sprMap,
    int32           xpos,
    int32           ypos,
    uint8           *lookup);
extern void compositePixelsRvs(
    gPixelMap       *compMap,
    gPixelMap       *sprMap,
    int32           xpos,
    int32           ypos,
    uint8           *lookup);
#endif

extern uint16 rippedRoofID;
extern void drawTileMask(
    const Point16 &sPos,
    gPixelMap &map,
    TilePoint loc,
    uint16 roofID = rippedRoofID);

/* ===================================================================== *
   Imports
 * ===================================================================== */

extern gPixelMap    tileDrawMap;
extern Point16      fineScroll;             // current scroll pos

//  Color map ranges
extern uint8        *ColorMapRanges;

extern gPort        backPort;

/* ===================================================================== *
   Exports
 * ===================================================================== */

/* ===================================================================== *
   Locals
 * ===================================================================== */

//  Remap table for colors which are not remapped.

extern uint8 fixedColors[] = {
	0, 10, 12, 14, 16, 18, 21, 24,
	101, 104, 130, 132, 197, 199, 228, 230
};

SpriteSet           **objectSprites,    // object sprites
                    * *mentalSprites,   // intangible object sprites
                    * *weaponSprites[maxWeaponSpriteSets], // weapon sprites
                    * *missileSprites;  // missile sprites

hResContext         *spriteRes,         // sprite resource handle
                    *frameRes,          // framelist resource handle
                    *poseRes,           // poselist resource handle
                    *schemeRes;         // schemelist resource handle

//  An array of 32 actor appearances
static ActorAppearance appearanceTable[32];

//  A least-recently-used list of actor appearances
static DList        appearanceLRU;

/* ===================================================================== *
   Quick memory routines
 * ===================================================================== */

static uint8        *quickMemBase,
       *quickMemPtr;

int32               quickMemSize;

void initQuickMem(int32 size) {
	quickMemBase = (uint8 *)RNewPtr(size, NULL, "Quickmem heap");
	if (quickMemBase == NULL)
		error("Error: Memory allocation size %d failed!", size);
	quickMemSize = size;
	quickMemPtr = quickMemBase;
}

void cleanupQuickMem(void) {
	RDisposePtr(quickMemBase);
}

void *getQuickMem(int32 size) {
	if (quickMemPtr + size > quickMemBase + quickMemSize) {
		error("Error: QuickMem allocation failed, size %d", size);
	}
	quickMemPtr += size;
	return quickMemPtr - size;
}

void freeQuickMem(void *ptr) {
	quickMemPtr = ptr ? (uint8 *)ptr : quickMemBase;
}

/* ===================================================================== *
   Sprite rendering routines
 * ===================================================================== */

void DrawCompositeMaskedSprite(
    gPort           &port,                  // destination gPort
    SpriteComponent *scList,                // list of components
    int16           numParts,               // number of components
    const Point16   &destPoint,             // where to render to
    const TilePoint &loc,                   // location on map
    int16           effects,                // effects flags
    bool            *obscured) {            // set if object obscured by terrain
	SpriteComponent *sc;                    // sprite component
	int             i;
	int16           xMax,                   // extent of composite
	                xMin,
	                yMax,
	                yMin;
	Rect16          clip;                   // clip rect of port
	gPixelMap       compMap,                // pixel map for composite
	                sprMap;                 // sprite map
	Point16         org;
	int             x, y;

	port.getClip(clip);

	//  First, determine the enclosing rectangle which
	//  surrounds all of the sprites.

	for (i = 0, sc = scList; i < numParts; i++, sc++) {
		Sprite      *sp = sc->sp;
		int16       left,
		            right,
		            bottom,
		            top;

		//  Compute the rectangle of the sprites

		if (sc->flipped)
			left = destPoint.x + sc->offset.x - sp->size.x - sp->offset.x;
		else left = destPoint.x + sc->offset.x + sp->offset.x;

		top    = destPoint.y + sc->offset.y + sp->offset.y;
		right  = left + sp->size.x;
		bottom = top + sp->size.y;

		if (i == 0) {
			xMin = left;
			xMax = right;
			yMin = top;
			yMax = bottom;
		} else {
			if (left   < xMin) xMin = left;
			if (right  > xMax) xMax = right;
			if (top    < yMin) yMin = top;
			if (bottom > yMax) yMax = bottom;
		}
	}

	//  If the composite area is outside the screen rect, then
	//  nothing needs to be done.

	if (xMax <= clip.x
	        || yMax <= clip.y
	        || xMin >= clip.x + clip.width
	        || yMin >= clip.y + clip.height)
		return;

	//  Justify the x coords to the nearest tile boundary

	xMin = xMin & ~31;
	xMax = (xMax + 31) & ~31;

	//  Build a temporary bitmap to composite the sprite within

	compMap.size.x = xMax - xMin;
	compMap.size.y = yMax - yMin;
	compMap.data = (uint8 *)getQuickMem(compMap.bytes());
	memset(compMap.data, 0, compMap.bytes());

	//  Calculate the offset from the upper-left corner of
	//  our composite map to the origin point where the sprites
	//  should be drawn.

	org.x = destPoint.x - xMin;
	org.y = destPoint.y - yMin;

	//  First, determine the enclosing rectangle which
	//  surrounds all of the sprites.

	for (i = 0, sc = scList; i < numParts; i++, sc++) {
		Sprite      *sp = sc->sp;

		//  Create a temp map for the sprite to unpack in

		sprMap.size = sp->size;
		if (sprMap.size.x <= 0 || sprMap.size.y <= 0) continue;
		sprMap.data = (uint8 *)getQuickMem(compMap.bytes());

		//  Unpack the sprite into the temp map

		unpackSprite(&sprMap, (uint8 *)(sp + 1));

		//  Blit the temp map onto the composite map

		if (sc->flipped) {
			compositePixelsRvs(
			    &compMap,
			    &sprMap,
			    org.x + sc->offset.x - sp->offset.x,
			    org.y + sc->offset.y + sp->offset.y,
			    sc->colorTable);
		} else {
			compositePixels(
			    &compMap,
			    &sprMap,
			    org.x + sc->offset.x + sp->offset.x,
			    org.y + sc->offset.y + sp->offset.y,
			    sc->colorTable);
		}
		freeQuickMem(sprMap.data);
	}

	//  do terrain masking
	if (effects & sprFXTerrainMask) {
		if (!(effects & sprFXGhostIfObscured)) {
			drawTileMask(
			    Point16(xMin, yMin),
			    compMap,
			    loc);
		} else {
			gPixelMap       tempMap;
			int32           compMapBytes = compMap.bytes(),
			                i,
			                visiblePixels;
			bool            isObscured;

			tempMap.size = compMap.size;
			tempMap.data = (uint8 *)getQuickMem(compMapBytes);

			memcpy(tempMap.data, compMap.data, compMapBytes);

			drawTileMask(
			    Point16(xMin, yMin),
			    compMap,
			    loc);

			visiblePixels = 0;
			for (i = 0; i < compMapBytes; i++) {
				if (compMap.data[i] != 0) {
					visiblePixels++;
					if (visiblePixels > 10) break;
				}
			}

			isObscured = visiblePixels <= 10;
			if (isObscured) {
				memcpy(compMap.data, tempMap.data, compMapBytes);
				effects |= sprFXGhosted;
			}

			if (obscured != NULL) *obscured = isObscured;

			freeQuickMem(tempMap.data);
		}
	}

	//  Check if location is underwater
	if (loc.z < 0) {
		uint8   *submergedArea = &compMap.data[(-loc.z < compMap.size.y ?
		                                        (compMap.size.y + loc.z)
		                                        * compMap.size.x :
		                                        0)];

		uint16  submergedSize = &compMap.data[compMap.bytes()] -
		                        submergedArea;

		memset(submergedArea, 0, submergedSize);
	}

	//  Add in "ghost" effects
	if (effects & sprFXGhosted) {
		uint32  *dstRow = (uint32 *)compMap.data;

		uint32  mask = (yMin & 1) ? 0xff00ff00 : 0x00ff00ff;

		for (y = 0; y < compMap.size.y; y++) {
			for (x = 0; x < compMap.size.x; x += 4) {
				*dstRow++ &= mask;
			}
			mask = ~mask;
		}
	}

	//  Blit to the port

	TBlit(port.map, &compMap, xMin, yMin);

	freeQuickMem(compMap.data);
}

void DrawSprite(
    gPort           &port,                  // destination gPort
    const Point16   &destPoint,             // where to render to
    Sprite          *sp) {                  // sprite pointer
	gPixelMap       sprMap;                 // sprite map

	//  Create a temp map for the sprite to unpack in
	sprMap.size = sp->size;
	sprMap.data = (uint8 *)getQuickMem(sprMap.bytes());

	//  Unpack the sprite into the temp map
	unpackSprite(&sprMap, (uint8 *)(sp + 1));

	//  Blit to the port
	port.setMode(drawModeMatte);
	port.bltPixels(sprMap,
	               0, 0,
	               destPoint.x + sp->offset.x,
	               destPoint.y + sp->offset.y,
	               sprMap.size.x, sprMap.size.y);

	freeQuickMem(sprMap.data);
}

//  Draw a single sprite with no masking, but with color mapping.

void DrawColorMappedSprite(
    gPort           &port,                  // destination gPort
    const Point16   &destPoint,             // where to render to
    Sprite          *sp,                    // sprite pointer
    uint8           *colorTable) {          // color remapping table
	gPixelMap       sprMap,                 // sprite map
	                sprReMap;               // remapped sprite map

	//  Create a temp map for the sprite to unpack in
	sprMap.size = sp->size;
	sprMap.data = (uint8 *)getQuickMem(sprMap.bytes());
	sprReMap.size = sp->size;
	sprReMap.data = (uint8 *)getQuickMem(sprReMap.bytes());

	//  Unpack the sprite into the temp map
	unpackSprite(&sprMap, (uint8 *)(sp + 1));

	memset(sprReMap.data, 0, sprReMap.bytes());

	//  remap the sprite to the color table given
	compositePixels(
	    &sprReMap,
	    &sprMap,
	    0,
	    0,
	    colorTable);

	//  Blit to the port
	port.setMode(drawModeMatte);
	port.bltPixels(sprReMap,
	               0, 0,
	               destPoint.x + sp->offset.x,
	               destPoint.y + sp->offset.y,
	               sprReMap.size.x, sprReMap.size.y);

	freeQuickMem(sprReMap.data);
	freeQuickMem(sprMap.data);
}

//  Draw a single sprite with no masking, but with color mapping.

void ExpandColorMappedSprite(
    gPixelMap       &map,                   // destination gPixelMap
    Sprite          *sp,                    // sprite pointer
    uint8           *colorTable) {          // color remapping table
	gPixelMap       sprMap,                 // sprite map
	                sprReMap;               // remapped sprite map

	//  Create a temp map for the sprite to unpack in
	sprMap.size = sp->size;
	sprMap.data = (uint8 *)getQuickMem(sprMap.bytes());

	//  Unpack the sprite into the temp map
	unpackSprite(&sprMap, (uint8 *)(sp + 1));

	//  remap the sprite to the color table given
	compositePixels(
	    &map,
	    &sprMap,
	    0,
	    0,
	    colorTable);

	freeQuickMem(sprMap.data);
}

//  Unpacks a sprite for a moment and returns the value of a
//  specific pixel in the sprite. This is used to do hit testing
//  against sprites.

uint8 GetSpritePixel(
    Sprite          *sp,                    // sprite pointer
    int16           flipped,                // TRUE if sprite was flipped
    const Point16   &testPoint) {           // where to render to
	gPixelMap       sprMap;                 // sprite map
	uint8           result;

	//  Create a temp map for the sprite to unpack in
	sprMap.size = sp->size;
	sprMap.data = (uint8 *)getQuickMem(sprMap.bytes());

	//  Unpack the sprite into the temp map
	unpackSprite(&sprMap, (uint8 *)(sp + 1));

	//  Map the coords to the bitmap and return the pixel
	if (flipped) {
		result = sprMap.data[testPoint.y * sprMap.size.x
		                                  + sprMap.size.x - testPoint.x];
	} else {
		result = sprMap.data[testPoint.y * sprMap.size.x + testPoint.x];
	}
	freeQuickMem(sprMap.data);

	return result;
}


//  Return the number of visible pixels in a sprite after terrain masking
uint16 visiblePixelsInSprite(
    Sprite          *sp,                    // sprite pointer
    bool            flipped,                // is sprite flipped
    ColorTable      colors,                 // sprite's color table
    Point16         drawPos,                // XY position of sprite
    TilePoint       loc,                    // UVZ coordinates of sprite
    uint16          roofID) {               // ID of ripped roof

	Point16     org;
	int16       xMin,                   // extent of sprite
	            xMax,
	            yMin,
	            yMax;
	gPixelMap   sprMap,                 // sprite map
	            compMap;
	uint16      compBytes,
	            i,
	            visiblePixels;

	//  Determine the extent of the sprite
	xMin = drawPos.x + sp->offset.x;
	yMin = drawPos.y + sp->offset.y;
	xMax = xMin + sp->size.x;
	yMax = yMin + sp->size.y;

	//  Justify the x coords to the nearest tile boundary
	xMin &= ~31;
	xMax = (xMax + 31) & ~31;

	//  Build a temporary bitmap to composite the sprite within
	compMap.size.x = xMax - xMin;
	compMap.size.y = yMax - yMin;
	compMap.data = (uint8 *)getQuickMem(compBytes = compMap.bytes());
	memset(compMap.data, 0, compBytes);

	//  Build bitmap in which to unpack the sprite
	sprMap.size = sp->size;
	sprMap.data = (uint8 *)getQuickMem(sprMap.bytes());

	unpackSprite(&sprMap, (uint8 *)(sp + 1));

	org.x = drawPos.x - xMin;
	org.y = drawPos.y - yMin;

	//  Blit the sprite onto the composite map
	if (!flipped) {
		compositePixels(
		    &compMap,
		    &sprMap,
		    org.x + sp->offset.x,
		    org.y + sp->offset.y,
		    colors);
	} else {
		compositePixelsRvs(
		    &compMap,
		    &sprMap,
		    org.x - sp->offset.x,
		    org.y + sp->offset.y,
		    colors);
	}

	//  do terrain masking
	drawTileMask(
	    Point16(xMin, yMin),
	    compMap,
	    loc,
	    roofID);

	//  count the visible pixels in the composite map
	for (i = 0, visiblePixels = 0; i < compBytes; i++)
		if (compMap.data[i]) visiblePixels++;

#if DEBUG*0
	WriteStatusF(8, "Visible pixels = %u", visiblePixels);
#endif

	freeQuickMem(sprMap.data);

	freeQuickMem(compMap.data);

	return visiblePixels;
}

/* ===================================================================== *
   Color table assembly
 * ===================================================================== */

void buildColorTable(
    uint8           *colorTable,            // color table to build
    uint8           *colorOptions,          // colors ranges chosen
    int16           numOptions) {
	uint32           *src,
	                 *dst;

	memcpy(colorTable, fixedColors, sizeof fixedColors);
	dst = (uint32 *)(colorTable + sizeof fixedColors);

	while (numOptions--) {
		src = (uint32 *)ColorMapRanges[*colorOptions * 8];
		colorOptions++;
		*dst++ = *src++;
		*dst++ = *src++;
	}
}

/* ===================================================================== *
   Load actor appearance
 * ===================================================================== */

#if DEBUG
char *idname(long s) {
	static char     t[8];
	char            *p = (char *)&s;

	t[0] = *p++;
	t[1] = *p++;
	t[2] = *p++;
	if (*p > ' ') {
		t[3] = *p;
		t[4] = 0;
	} else {
		sprintf(&t[3], ":%d", *p);
	}
	return t;
}
#endif

void ActorAppearance::loadSpriteBanks(int16 banksNeeded) {
	int16           bank;

	WriteStatusF(2, "Loading Banks: %x", banksNeeded);

	//  Make this one the most recently used entry
	remove();
	appearanceLRU.addTail(*this);

	//  Load in additional sprite banks if requested...
	for (bank = 0; bank < elementsof(spriteBanks); bank++) {
		//  Wash the sprite banks...i.e. clear out dead handles
		//  which have been purged.
		washHandle((RHANDLE &)(spriteBanks[bank]));

		//  Load the sprite handle...
		if (spriteBanks[bank] == NULL && (banksNeeded & (1 << bank))) {
			spriteBanks[bank] = (SpriteSet **)spriteRes->load(id + RES_ID(0, 0, 0, bank), "sprite bank", FALSE);

#if DEBUG
			if (spriteBanks[bank] == NULL)
				fatal("Sprite '%s' bank %d failed to load!\n",
				      idname(id),
				      bank);
#endif

			//  Since the sprites are so big, we'll keep them unlocked
			//  so that they can be purged as needed.
			RUnlockHandle((RHANDLE) spriteBanks[bank]);
		}
	}
}

ActorAppearance *LoadActorAppearance(uint32 id, int16 banksNeeded) {
	ActorAppearance *aa;
	int16           bank;

#if DEBUG
	WriteStatusF(2, "Load App: %s", idname(id));
#endif

	//  Search the table for either a matching appearance,
	//  or for an empty one.
	for (aa = (ActorAppearance *)appearanceLRU.first();
	        aa != NULL;
	        aa = (ActorAppearance *)aa->next()) {
		if (aa->id == id                    // If has same ID
		        && aa->poseList != NULL) {      // and frames not dumped
			// then use this one!
			aa->useCount++;
			aa->loadSpriteBanks(banksNeeded);
			return aa;
		}
	}

	//  If we couldn't find an extact match, search for an
	//  empty one.
	if (aa == NULL) {
		//  Search from LRU end of list.
		for (aa = (ActorAppearance *)appearanceLRU.first();
		        aa != NULL;
		        aa = (ActorAppearance *)aa->next()) {
			if (aa->useCount == 0)              // If not in use
				break;                          // then use this one!
		}

		//  If none available, that's fatal...
		if (aa == NULL) {
			error("All ActorAppearance records are in use!");
		}
	}

	//  Dump the sprites being stored
	for (bank = 0; bank < elementsof(aa->spriteBanks); bank++) {
		if (aa->spriteBanks[bank])
			spriteRes->release((RHANDLE) aa->spriteBanks[bank]);
		aa->spriteBanks[bank] = NULL;
	}

	if (aa->poseList)  poseRes->release((RHANDLE) aa->poseList);
	aa->poseList = NULL;

	if (aa->schemeList)  schemeRes->release((RHANDLE) aa->schemeList);
	aa->schemeList = NULL;

	//  Set ID and use count
	aa->id = id;
	aa->useCount = 1;

	//  Load in new frame lists and sprite banks
	aa->loadSpriteBanks(banksNeeded);
	aa->poseList    = (ActorAnimSet **)poseRes->load(id, "pose list", FALSE, FALSE);
// I just added these - dispnode may have to lock & unlock the handle now - EO
	if (aa->poseList)  RUnlockHandle((RHANDLE) aa->poseList);
#if DEBUG
	if (aa->poseList == NULL)
		fatal("PoseList '%s' failed to load!\n", idname(id));
#endif
	//  REM: It's OK if schemelist fails to load...
	aa->schemeList  = (ColorScheme **)schemeRes->load(id, "scheme list", FALSE, FALSE);
// I just added these - dispnode may have to lock & unlock the handle now - EO
	if (aa->schemeList)  RUnlockHandle((RHANDLE) aa->schemeList);

	return aa;
}

void ReleaseActorAppearance(ActorAppearance *aa) {
	if (--aa->useCount == 0) {
	}

#ifndef WINKLUDGE       // jeffkludge -- causes crash
#if DEBUG
	WriteStatusF(2, "Release");
#endif
#endif
}

/* ===================================================================== *
   Sprite initialization routines
 * ===================================================================== */

void initSprites(void) {
	int     i;

	spriteRes = resFile->newContext(spriteGroupID, "sprite resources");
	if (!spriteRes->_valid)
		error("Error accessing sprite resource group.");

	frameRes = resFile->newContext(frameGroupID, "frame resources");
	assert(frameRes && frameRes->_valid);

	poseRes = resFile->newContext(poseGroupID, "pose resources");
	assert(poseRes && poseRes->_valid);

	schemeRes = resFile->newContext(schemeGroupID, "scheme resources");
	assert(schemeRes && schemeRes->_valid);

	// object sprites
	objectSprites = (SpriteSet **)spriteRes->load(objectSpriteID, "object sprites");
	assert(objectSprites);

	// intagible object sprites
	mentalSprites = (SpriteSet **)spriteRes->load(mentalSpriteID, "mental sprites");
	assert(mentalSprites);

	for (i = 0; i < maxWeaponSpriteSets; i++) {
		hResID      weaponSpriteID;

		weaponSpriteID = weaponSpriteBaseID + RES_ID(0, 0, 0, i);

		if (spriteRes->size(weaponSpriteID) == 0) {
			weaponSprites[i] = NULL;
			continue;
		}

		weaponSprites[i] = (SpriteSet **)spriteRes->load(
		                         weaponSpriteID,
		                         "weapon sprite set");
	}

	missileSprites = (SpriteSet **)spriteRes->load(missileSpriteID, "missle sprites");

	initQuickMem(0x10000);

	//  Initialize actor appearance table
	for (i = 0; i < elementsof(appearanceTable); i++) {
		ActorAppearance *aa = &appearanceTable[i];

		aa->useCount = 0;
		appearanceLRU.addHead(*aa);
	}
}

void cleanupSprites(void) {
	int         i;

	cleanupQuickMem();

	if (objectSprites) spriteRes->release((RHANDLE) objectSprites);
	objectSprites = NULL;

	if (mentalSprites) spriteRes->release((RHANDLE) mentalSprites);
	mentalSprites = NULL;

	for (i = 0; i < maxWeaponSpriteSets; i++) {
		if (weaponSprites[i]) {
			spriteRes->release((RHANDLE) weaponSprites[i]);
			weaponSprites[i] = NULL;
		}
	}

	if (schemeRes) resFile->disposeContext(schemeRes);
	schemeRes = NULL;

	if (poseRes) resFile->disposeContext(poseRes);
	poseRes = NULL;

	if (frameRes) resFile->disposeContext(frameRes);
	frameRes = NULL;

	if (spriteRes) resFile->disposeContext(spriteRes);
	spriteRes = NULL;
}

} // end of namespace Saga2
