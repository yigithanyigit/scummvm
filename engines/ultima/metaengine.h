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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA_METAENGINE_H
#define ULTIMA_METAENGINE_H

#include "engines/advancedDetector.h"
#include "common/system.h"

#define MAX_SAVES 99

class UltimaMetaEngine : public AdvancedMetaEngine {
private:
	/**
	 * Gets the game Id given a target string
	 */
	static Common::String getGameId(const Common::String& target);
public:
	const char *getName() const override;

	Common::Error createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const override;
	int getMaximumSaveSlot() const override;

	/**
	 * Return a list of all save states associated with the given target.
	 */
	SaveStateList listSaves(const char *target) const override;

	/**
	 * Initialize keymaps
	 */
	Common::KeymapArray initKeymaps(const char *target) const override;

	/**
	* Return the extra GUI options used by the target.
	*/
	const ExtraGuiOptions getExtraGuiOptions(const Common::String &target) const override;

};

#endif
