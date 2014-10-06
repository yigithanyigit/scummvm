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

 /*
 * This code is based on Labyrinth of Time code with assistance of
 *
 * Copyright (c) 1993 Terra Nova Development
 * Copyright (c) 2004 The Wyrmkeep Entertainment Co.
 *
 */

#include "common/debug-channels.h"
#include "common/scummsys.h"
#include "common/error.h"
#include "common/fs.h"
#include "common/rect.h"

#include "engines/util.h"

#include "lab/lab.h"
#include "lab/labfun.h"

namespace Lab {

bool LabEngine::hasFeature(EngineFeature f) const {
	return (f == kSupportsRTL) ? true : false;
}

LabEngine::LabEngine(OSystem *syst)
 : Engine(syst) {
}

LabEngine::~LabEngine() {
	// Remove all of our debug levels here
	DebugMan.clearAllDebugChannels();
}

Common::Error LabEngine::run() {
	// Initialize graphics using following:
	initGraphics(320, 200, false);

	g_music = new Music();

	inner_main();

	return Common::kNoError;
}

} // End of namespace Lab
