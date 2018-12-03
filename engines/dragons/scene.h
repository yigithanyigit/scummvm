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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#ifndef SCUMMVM_SCENE_H
#define SCUMMVM_SCENE_H

#include "common/rect.h"
#include "common/system.h"

namespace Dragons {

class ActorManager;
class Background;
class DragonRMS;
class BackgroundResourceLoader;
class DragonINIResource;
class BigfileArchive;
class Screen;

class Scene {
private:
	Screen *_screen;
	ActorManager *_actorManager;
	Background *_stage;
	BigfileArchive *_bigfileArchive;
	DragonRMS *_dragonRMS;
	DragonINIResource *_dragonINIResource;
	BackgroundResourceLoader *_backgroundLoader;

	uint16 _currentSceneId;
	Common::Point _camera;

public:
	Scene(Screen *screen, BigfileArchive *bigfileArchive, ActorManager *actorManager, DragonRMS *_dragonRMS, DragonINIResource *_dragonINIResource);

	void loadScene(uint32 sceneId, uint32 cameraPointId);

	void draw();
};

} // End of namespace Dragons

#endif //SCUMMVM_SCENE_H
