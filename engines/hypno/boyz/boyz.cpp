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

#include "hypno/grammar.h"
#include "hypno/hypno.h"

#include "common/events.h"

namespace Hypno {

BoyzEngine::BoyzEngine(OSystem *syst, const ADGameDescription *gd) : HypnoEngine(syst, gd) {
	_screenW = 320;
	_screenH = 200;
	_lives = 2;
}

void BoyzEngine::loadAssets() {
	LibFile *missions = loadLib("", "preload/missions.lib", true);
	Common::ArchiveMemberList files;
	if (missions->listMembers(files) == 0)
		error("Failed to load any files from missions.lib");
	loadArcadeLevel("c11.mi_", "", "", "");
	loadLib("sound/", "misc/sound.lib", true);
	_nextLevel = "c11.mi_";
}

void BoyzEngine::runBeforeArcade(ArcadeShooting *arc) {
	_checkpoint = _currentLevel;
	assert(!arc->player.empty());
	_playerFrames = decodeFrames(arc->player);
	_playerFrameSep = 0;

	for (Frames::iterator it =_playerFrames.begin(); it != _playerFrames.end(); ++it) {
		if ((*it)->getPixel(0, 0) == 255)
			break;
		if ((*it)->getPixel(0, 0) == 252)
			break;

		_playerFrameSep++;
	}
	_playerFrameIdx = -1;
}

void BoyzEngine::drawPlayer() {
	drawImage(*_playerFrames[0], 0, 0, true);
}
void BoyzEngine::drawHealth() {}
void BoyzEngine::hitPlayer() {}
void BoyzEngine::drawShoot(const Common::Point &target) {}

Common::String BoyzEngine::findNextLevel(const Common::String &level) { return level; }

void BoyzEngine::initSegment(ArcadeShooting *arc) {
	_segmentShootSequenceOffset = 0;
	_segmentShootSequenceMax = 0;

	uint32 randomSegmentShootSequence = _segmentShootSequenceOffset + _rnd->getRandomNumber(_segmentShootSequenceMax);
	SegmentShoots segmentShoots = arc->shootSequence[randomSegmentShootSequence];
	_shootSequence = segmentShoots.shootSequence;
	_segmentRepetitionMax = segmentShoots.segmentRepetition; // Usually zero
	_segmentRepetition = 0;
	_segmentOffset = 0;
	_segmentIdx = _segmentOffset;
}

void BoyzEngine::findNextSegment(ArcadeShooting *arc) {
	_segmentIdx = _segmentIdx + 1;
}

int BoyzEngine::detectTarget(const Common::Point &mousePos) {
	Common::Point target = computeTargetPosition(mousePos);
	assert(_shoots.size() <= 1);
	for (Shoots::iterator it = _shoots.begin(); it != _shoots.end(); ++it) {
		if (_mask->getPixel(target.x, target.y) == 1)
			return 0;
	}
	return -1;
}

void BoyzEngine::shoot(const Common::Point &mousePos, ArcadeShooting *arc, MVideo &background) {
	incShotsFired();
	int i = detectTarget(mousePos);
	if (i < 0) {
		missNoTarget(arc, background);
	} else {
		if (!_shoots[i].hitSound.empty())
			playSound(_soundPath + _shoots[i].hitSound, 1);

		incEnemyHits();
		if (!_shoots[i].deathSound.empty())
			playSound(_soundPath + _shoots[i].deathSound, 1);

		incTargetsDestroyed();
		incScore(_shoots[i].pointsToShoot);
		incBonus(_shoots[i].pointsToShoot);
		_shoots[i].destroyed = true;
		background.decoder->forceSeekToFrame(_shoots[i].explosionFrames[0].start - 3);
		_masks->decoder->forceSeekToFrame(_shoots[i].explosionFrames[0].start - 3);
		_shoots.clear();
	}
}

void BoyzEngine::missedTarget(Shoot *s, ArcadeShooting *arc, MVideo &background) {
	if (s->missedAnimation == uint32(-1)) {
		uint32 last = background.decoder->getFrameCount()-1;
		background.decoder->forceSeekToFrame(last);
		_masks->decoder->forceSeekToFrame(last);
		return;
	}

	s->missedAnimation = s->missedAnimation + 3;
	background.decoder->forceSeekToFrame(s->missedAnimation);
	_masks->decoder->forceSeekToFrame(s->missedAnimation);
}


} // namespace Hypno
