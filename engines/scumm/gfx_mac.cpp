/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "common/system.h"

#include "graphics/macega.h"
#include "graphics/fonts/macfont.h"
#include "graphics/macgui/macfontmanager.h"

#include "scumm/actor.h"
#include "scumm/charset.h"
#include "scumm/gfx_mac.h"
#include "scumm/usage_bits.h"
#include "scumm/verbs.h"

namespace Scumm {

void ScummEngine::mac_markScreenAsDirty(int x, int y, int w, int h) {
	// Mark the virtual screen as dirty. The top and left coordinates are
	// rounded down, while the bottom and right ones are rounded up.

	VirtScreen *vs = &_virtscr[kMainVirtScreen];

	int vsTop = y / 2 - vs->topline;
	int vsBottom = (y + h) / 2 - vs->topline;
	int vsLeft = x / 2;
	int vsRight = (x + w) / 2;

	if ((y + h) & 1)
		vsBottom++;

	if ((x + w) & 1)
		vsRight++;

	markRectAsDirty(kMainVirtScreen, vsLeft, vsRight, vsTop, vsBottom);
}

void ScummEngine::mac_drawStripToScreen(VirtScreen *vs, int top, int x, int y, int width, int height) {
	// The verb screen is completely replaced with a custom GUI
	if (vs->number == kVerbVirtScreen && VAR(VAR_VERB_SCRIPT) == 4)
		return;

	const byte *pixels = vs->getPixels(x, top);
	const byte *ts = (byte *)_textSurface.getBasePtr(x * 2, y * 2);
	byte *mac = (byte *)_macScreen->getBasePtr(x * 2, y * 2);

	int pixelsPitch = vs->pitch;
	int tsPitch = _textSurface.pitch;
	int macPitch = _macScreen->pitch;

	// In b/w Mac rendering mode, the shadow palette is implemented here,
	// and not as a palette manipulation. See special cases in o5_roomOps()
	// and updatePalette().
	//
	// This is used at the very least for the lightning flashes at Castle
	// Brunwald in Indy 3, as well as the scene where the dragon finds
	// Rusty in Loom.
	//
	// Interestingly, the original Mac interpreter does not seem to do
	// this, and instead just renders the scene as if the palette was
	// unmodified. At least, that's what Mini vMac did when I tried it.

	if (_renderMode == Common::kRenderMacintoshBW) {
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				int color = _enableEnhancements ? _shadowPalette[pixels[w]] : pixels[w];
				if (ts[2 * w] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w] = Graphics::macEGADither[color][0];
				if (ts[2 * w + 1] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + 1] = Graphics::macEGADither[color][1];
				if (ts[2 * w + tsPitch] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + macPitch] = Graphics::macEGADither[color][2];
				if (ts[2 * w + tsPitch + 1] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + macPitch + 1] = Graphics::macEGADither[color][3];
			}

			pixels += pixelsPitch;
			ts += tsPitch * 2;
			mac += macPitch * 2;
		}
	} else {
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				if (ts[2 * w] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w] = pixels[w];
				if (ts[2 * w + 1] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + 1] = pixels[w];
				if (ts[2 * w + tsPitch] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + macPitch] = pixels[w];
				if (ts[2 * w + tsPitch + 1] == CHARSET_MASK_TRANSPARENCY)
					mac[2 * w + macPitch + 1] = pixels[w];
			}

			pixels += pixelsPitch;
			ts += tsPitch * 2;
			mac += macPitch * 2;
		}
	}


	_system->copyRectToScreen(_macScreen->getBasePtr(x * 2, y * 2), _macScreen->pitch, x * 2, y * 2, width * 2, height * 2);
}

void ScummEngine::mac_drawLoomPracticeMode() {
	// In practice mode, the game shows the notes as they are being played.
	// In the DOS version, this is drawn by script 27 but the Mac version
	// just sets variables 50 and 54. The box is actually a verb, and it
	// seems that setting variable 50 is pretty much equal to turning verb
	// 53 on or off. I'm not sure what the purpose of variable 54 is.

	int x = 216;
	int y = 377;
	int width = 62;
	int height = 22;
	int var = 50;

	byte *ptr = (byte *)_macScreen->getBasePtr(x,  y);
	int pitch = _macScreen->pitch;

	int slot = getVerbSlot(53, 0);
	VerbSlot *vs = &_verbs[slot];

	vs->curmode = (VAR(var) != 0);
	vs->curRect.left = x / 2;
	vs->curRect.right = (x + width) / 2;
	vs->curRect.top = y / 22;
	vs->curRect.bottom = (y + height) / 2;

	_macScreen->fillRect(Common::Rect(x, y, x + width, y + height), 0);

	if (VAR(var)) {
		for (int w = 1; w < width - 1; w++) {
			ptr[w] = 7;
			ptr[w + pitch * (height - 1)] = 7;
		}

		for (int h = 1; h < height - 1; h++) {
			ptr[h * pitch] = 7;
			ptr[h * pitch + width - 1] = 7;
		}

		// Draw the notes
		int colors[] = { 4, 12, 14, 10, 11, 3, 9, 15 };

		for (int i = 0; i < 4; i++) {
			int note = (VAR(var) >> (4 * i)) & 0x0F;

			if (note >= 2 && note <= 9) {
				_charset->setColor(colors[note - 2]);
				_charset->drawChar(14 + note, *_macScreen, i * 13 + x + 8, y + 4);
			}
		}
	}

	_system->copyRectToScreen(ptr, pitch, x, y, width, height);
}

void ScummEngine::mac_createIndy3TextBox(Actor *a) {
	int width = _macIndy3TextBox->w;
	int height = _macIndy3TextBox->h;

	_macIndy3TextBox->fillRect(Common::Rect(width, height), 0);

	int nameWidth = 0;

	if (a) {
		int oldID = _charset->getCurID();
		_charset->setCurID(2 | 0x80);

		const char *name = (const char *)a->getActorName();
		int charX = 25;

		for (int i = 0; name[i] && nameWidth < width - 50; i++) {
			_charset->drawChar(name[i], *_macIndy3TextBox, charX, 0);
			nameWidth += _charset->getCharWidth(name[i]);
			charX += _charset->getCharWidth(name[i]);
		}

		_charset->drawChar(':', *_macIndy3TextBox, charX, 0);
		_charset->setCurID(oldID);
	}

	if (nameWidth) {
		_macIndy3TextBox->hLine(2, 3, 20, 15);
		_macIndy3TextBox->hLine(32 + nameWidth, 3, width - 3, 15);
	} else
		_macIndy3TextBox->hLine(2, 3, width - 3, 15);

	_macIndy3TextBox->vLine(1, 4, height - 3, 15);
	_macIndy3TextBox->vLine(width - 2, 4, height - 3, 15);
	_macIndy3TextBox->hLine(2, height - 2, width - 3, 15);
}

void ScummEngine::mac_drawIndy3TextBox() {
	// The first two rows of the text box are padding for font rendering.
	// They are not drawn to the screen.

	int x = 96;
	int y = 32;
	int w = _macIndy3TextBox->w;
	int h = _macIndy3TextBox->h - 2;

	// The text box is drawn to the Mac screen and text surface, as if it
	// had been one giant glyph. Note that it will be drawn on the main
	// virtual screen, but we still pretend it's on the text one.

	byte *ptr = (byte *)_macIndy3TextBox->getBasePtr(0, 2);
	int pitch = _macIndy3TextBox->pitch;

	_macScreen->copyRectToSurface(ptr, pitch, x, y, w, h);
	_textSurface.fillRect(Common::Rect(x, y, x + w, y + h), 0);

	mac_markScreenAsDirty(x, y, w, h);
}

void ScummEngine::mac_undrawIndy3TextBox() {
	int x = 96;
	int y = 32;
	int w = _macIndy3TextBox->w;
	int h = _macIndy3TextBox->h - 2;

	_macScreen->fillRect(Common::Rect(x, y, x + w, y + h), 0);
	_textSurface.fillRect(Common::Rect(x, y, x + w, y + h), CHARSET_MASK_TRANSPARENCY);

	mac_markScreenAsDirty(x, y, w, h);
}

void ScummEngine::mac_undrawIndy3CreditsText() {
	if (_macScreen) {
		// Set _masMask to make the text clear, and _textScreenID to
		// ensure that it's the main area that's cleared. Note that
		// this only works with the high-resolution font.
		_charset->_hasMask = true;
		_charset->_textScreenID = kMainVirtScreen;
		restoreCharsetBg();
	} else {
		// The DOS VGA version clear the text by using the putState
		// opcode. I would have been more comfortable if I could have
		// compared it to the EGA version, but I don't have that.
		// Judging by the size and position of the object, they should
		// be the same.
		putState(946, 0);
		markObjectRectAsDirty(946);
		if (_bgNeedsRedraw)
			clearDrawObjectQueue();
	}
}

void ScummEngine::mac_drawBorder(int x, int y, int w, int h, byte color) {
	_macScreen->hLine(x + 2, y, x + w - 2, 0);
	_macScreen->hLine(x + 2, y + h - 1, x + w - 2, 0);
	_macScreen->vLine(x, y + 2, y + h - 3, 0);
	_macScreen->vLine(x + w, y + 2, y + h - 3, 0);
	_macScreen->setPixel(x + 1, y + 1, 0);
	_macScreen->setPixel(x + w - 1, y + 1, 0);
	_macScreen->setPixel(x + 1, y + h - 2, 0);
	_macScreen->setPixel(x + w - 1, y + h - 2, 0);
}

Common::KeyState ScummEngine::mac_showOldStyleBannerAndPause(const char *msg, int32 waitTime) {
	char bannerMsg[512];

	_messageBannerActive = true;

	// Fetch the translated string for the message...
	convertMessageToString((const byte *)msg, (byte *)bannerMsg, sizeof(bannerMsg));

	// Backup the surfaces...
	int x = 70;
	int y = 189;
	int w = 499;
	int h = 22;

	Graphics::Surface backupTextSurface;
	Graphics::Surface backupMacScreen;

	backupTextSurface.create(w + 1, h, Graphics::PixelFormat::createFormatCLUT8());
	backupMacScreen.create(w + 1, h, Graphics::PixelFormat::createFormatCLUT8());

	backupTextSurface.copyRectToSurface(_textSurface, 0, 0, Common::Rect(x, y, x + w + 1, y + h));
	backupMacScreen.copyRectToSurface(*_macScreen, 0, 0, Common::Rect(x, y, x + w + 1, y + h));

	// Pause shake effect
	_shakeTempSavedState = _shakeEnabled;
	setShake(0);

	// Pause the engine
	PauseToken pt = pauseEngine();

	// Backup the current charsetId...
	int oldId = _charset->getCurID();
	_charset->setCurID(1 | 0x80);
	_charset->setColor(0);

	_textSurface.fillRect(Common::Rect(x, y, x + w + 1, y + h), 0);
	_macScreen->fillRect(Common::Rect(x + 1, y + 1, x + w, y + h - 1), 15);
	mac_drawBorder(x, y, w, h, 0);
	mac_drawBorder(x + 2, y + 2, w - 4, h - 4, 0);

	int stringWidth = 0;

	for (int i = 0; msg[i]; i++)
		stringWidth += _charset->getCharWidth(msg[i]);

	int stringX = 1 + x + (w - stringWidth) / 2;

	for (int i = 0; msg[i]; i++) {
		_charset->drawChar(msg[i], *_macScreen, stringX, y + 4);
		stringX += _charset->getCharWidth(msg[i]);
	}

	mac_markScreenAsDirty(x, y, w, h);
	ScummEngine::drawDirtyScreenParts();

	Common::KeyState ks = Common::KEYCODE_INVALID;
	bool leftBtnPressed = false, rightBtnPressed = false;
	if (waitTime) {
		waitForBannerInput(waitTime, ks, leftBtnPressed, rightBtnPressed);
	}

	// Restore the surfaces...
	_textSurface.copyRectToSurface(backupTextSurface, x, y, Common::Rect(0, 0, w + 1, h));
	_macScreen->copyRectToSurface(backupMacScreen, x, y, Common::Rect(0, 0, w + 1, h));

	backupTextSurface.free();
	backupMacScreen.free();

	// Notify the gfx system that we restored the surfaces...
	mac_markScreenAsDirty(x, y, w + 1, h);
	ScummEngine::drawDirtyScreenParts();

	// Finally, resume the engine, clear the input state, and restore the charset.
	pt.clear();
	clearClickedStatus();

	_charset->setCurID(oldId);

	_messageBannerActive = false;

	return ks;
}

MacIndy3Gui::MacIndy3Gui(OSystem *system, ScummEngine *vm) :
	_system(system), _vm(vm), _macScreen(vm->_macScreen) {
	Graphics::MacFontManager *mfm = _vm->_macFontManager;

	_fonts[0] = mfm->getFont(Graphics::MacFont(Graphics::kMacFontGeneva, 9));
	_fonts[1] = mfm->getFont(Graphics::MacFont(Graphics::kMacFontGeneva, 9, Graphics::kMacFontBold));
	_fonts[2] = mfm->getFont(Graphics::MacFont(Graphics::kMacFontGeneva, 9, Graphics::kMacFontBold | Graphics::kMacFontOutline | Graphics::kMacFontCondense));
}

MacIndy3Gui::~MacIndy3Gui() {
}

void MacIndy3Gui::handleEvent(Common::Event &event) {
	if (event.type != Common::EVENT_LBUTTONDOWN)
		return;

	debug("Handle Indy 3 click at %d, %d", event.mouse.x, event.mouse.y);
}

void MacIndy3Gui::clear() {
	_macScreen->fillRect(Common::Rect(0, 288, 640, 289), 0);
	_macScreen->fillRect(Common::Rect(0, 290, 640, 373), 7);

	byte corner[] = {
		0, 0, 0, 0,
		0, 0, 7, 7,
		0, 7, 7, 7,
		0, 7, 7, 7
	};

	byte *ul = (byte *)_macScreen->getBasePtr(0, 290);
	byte *ur = (byte *)_macScreen->getBasePtr(636, 290);
	byte *ll = (byte *)_macScreen->getBasePtr(0, 369);
	byte *lr = (byte *)_macScreen->getBasePtr(636, 369);

	int pitch = _macScreen->pitch;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			*(ul + y * pitch + x) = corner[y * 4 + x];
			*(ur + y * pitch + x) = corner[y * 4 + (3 - x)];
			*(ll + y * pitch + x) = corner[(3 - y) * 4 + x];
			*(lr + y * pitch + x) = corner[(3 - y) * 4 + (3 - x)];
		}
	}

	for (int i = 0; i < 15; i++)
		drawButton(i, false);

	_system->copyRectToScreen(_macScreen->getBasePtr(0, 288), _macScreen->pitch, 0, 288, 640, 112);
}

void MacIndy3Gui::drawButton(int n, bool pressed) {
	int x = _buttons[n].x;
	int y = _buttons[n].y;
	int w = _buttons[n].w;
	int h = _buttons[n].h;

	_macScreen->fillRect(Common::Rect(x + 1, y + 1, x + w, y + h), 15);

	_macScreen->hLine(x, y, x + w, 0);
	_macScreen->hLine(x, y + h, x + w, 0);
	_macScreen->vLine(x, y, y + h, 0);
	_macScreen->vLine(x + w, y, y + h, 0);
}

} // End of namespace Scumm
