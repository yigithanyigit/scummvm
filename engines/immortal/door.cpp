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

/* [Alternate Name: Door Processing]
 * --- What is a Door ---
 */

#include "immortal/immortal.h"

namespace Immortal {

enum DoorMask {
    kDoorXMask = 0x1f,
    kDoorYMask = 0x1f,
    kDoorFullMask = 0x40,
    kDoorOnMask = 0x60
};

enum DoorIs {
    kDoorIsRight  = 0x80,
    kDoorIsBusy   = 0x40,
    kDoorIsLocked = 0x20
};

enum DoorSide {
    kDoorTopPriority = 64,
    kDoorPriority    = 85 - kDoorTopPriority,
    kDoorLeftTop     = 24,              // To left of this enters door
    kDoorRightTop    = 8,               // To right of this enters door
    kDoorLeftBottom  = 10,
    kDoorRightBottom = 22,
    kDoorTopBottom   = 20
};

void ImmortalEngine::doorOpenSecret() {}
void ImmortalEngine::doorCloseSecret() {}
void ImmortalEngine::doorInit() {}
void ImmortalEngine::doorClrLock() {}
void ImmortalEngine::doorNew() {}
void ImmortalEngine::doorDrawAll() {}
void ImmortalEngine::doorOnDoorMat() {}
 int ImmortalEngine::findDoorTop(int x, int y) {
    return 0;
 }
 int ImmortalEngine::findDoor(int x, int y) {
    return 0;
 }
bool ImmortalEngine::doLockStuff(int d, MonsterID m, int top) {
    return true;
}
bool ImmortalEngine::inDoorTop(int x, int y, MonsterID m) {
    return true;
}
bool ImmortalEngine::inDoor(int x, int y, MonsterID m) {
    return true;
}
 int ImmortalEngine::doorDoStep(MonsterID m, int d, int index) {
    return 0;
 }
 int ImmortalEngine::doorSetOn(int d) {
    return 0;
 }
 int ImmortalEngine::doorComeOut(MonsterID m) {
    return 0;
 }
void ImmortalEngine::doorSetLadders(MonsterID m) {}

} // namespace immortal