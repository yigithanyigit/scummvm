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

#ifndef MM1_VIEWS_ENH_GAME_VIEW_H
#define MM1_VIEWS_ENH_GAME_VIEW_H

#include "mm/mm1/views/game_view.h"
#include "mm/shared/xeen/sprites.h"

namespace MM {
namespace MM1 {
namespace ViewsEnh {

namespace Animations {

class ViewAnimation {
protected:
	Common::Array<Shared::Xeen::SpriteResource> _backgrounds;
	uint _frameIndex = 0;
	uint _frameCount = 0;
public:
	ViewAnimation(const char *prefix, uint count, uint frameCount);
	virtual ~ViewAnimation() {}

	virtual void enter() {}
	void tick();
	void draw(Graphics::ManagedSurface &s);
	virtual void leave() {}
};

} // namespace Animations

class GameView : public Views::GameView {
private:
	Animations::ViewAnimation *_anim = nullptr;
	uint _timerCtr = 0;

	/**
	 * Start location animation
	 */
	void showLocation(int locationId);

public:
	GameView(UIElement *owner) : Views::GameView(owner) {}
	virtual ~GameView() {
		delete _anim;
	}

	void draw() override;
	bool msgGame(const GameMessage &msg) override;
	bool tick() override;
};

} // namespace ViewsEnh
} // namespace MM1
} // namespace MM

#endif
