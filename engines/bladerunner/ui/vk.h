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

#ifndef BLADERUNNER_VK_H
#define BLADERUNNER_VK_H

#include "common/array.h"
#include "common/str.h"

#include "graphics/surface.h"

namespace BladeRunner {

class BladeRunnerEngine;
class VKScript;
class Shape;
class UIImagePicker;
class VQAPlayer;

class VK {
	struct Question {
		bool isPresent;
		bool wasAsked;
		int sentenceId;
		int relatedSentenceId;
	};

	BladeRunnerEngine *_vm;

	VKScript *_script;

	UIImagePicker *_buttons;
	Common::Array<Shape *> _shapes;

	VQAPlayer *_vqaPlayerMain;
	VQAPlayer *_vqaPlayerEye;
	int _vqaFrameMain;
	bool _vqaLoopEnded;

	Graphics::Surface _surfaceEye;

	bool _isOpen;
	int _actorId;
	bool _calibrationStarted;
	bool _testStarted;

	Common::Array<Common::Array<Question> > _questions;

	int _volumeAmbient;
	int _volumeMusic;
	int _soundTrackId1;
	int _soundTrackId2;
	int _soundTrackId3;

	int _calibration;
	int _calibrationRatio;
	int _calibrationCounter;

	int _humanProbability;
	int _humanGauge;
	int _humanGaugeTarget;
	int _humanGaugeDelta;
	int _timeNextHumanGaugeStep;

	int _replicantProbability;
	int _replicantGauge;
	int _replicantGaugeTarget;
	int _replicantGaugeDelta;
	int _timeNextReplicantGaugeStep;

	int _anxiety;

	int _needleValue;
	int _needleValueMax;
	int _needleValueTarget;
	int _needleValueDelta;
	int _timeNextNeedleStep;
	int _timeNextNeedleOscillate;
	int _timeNeedleReturn;

	bool _isClosing;
	int _timeClose;

	int _blinkState;
	int _timeNextBlink;
	int _timeNextGaugesBlink;

	bool _isAdjusting;
	int _adjustment;
	int _adjustmentTarget;
	int _adjustmentDelta;
	int _timeNextAdjustementStep;

	int _eyeLineSelected;
	int _eyeLineX;
	int _eyeLineXLast;
	int _eyeLineY;
	int _eyeLineYLast;
	int _eyeLineXDelta;
	int _eyeLineYDelta;
	int _timeNextEyeLineStep;
	int _timeNextEyeLineStart;

public:
	VK(BladeRunnerEngine *vm);
	~VK();

	void open(int actorId, int calibrationRatio);
	bool isOpen() const;
	void close();

	void tick();

	void resume();

	void handleMouseDown(int mouseX, int mouseY, bool mainButton);
	void handleMouseUp(int mouseX, int mouseY, bool mainButton);

	void playSpeechLine(int actorId, int sentenceId, float duration);
	void addQuestion(int intensity, int sentenceId, int relatedSentenceId);
	void subjectReacts(int intensity, int humanResponse, int replicantResponse, int anxiety);
	void eyeAnimates(int loopId);

private:
	static void mouseDownCallback(int buttonId, void *callbackData);
	static void mouseUpCallback(int buttonId, void *callbackData);
	static void loopEnded(void *callbackData, int frame, int loopId);

	void reset();
	void init();

	void draw();

	void drawNeedle(Graphics::Surface &surface);
	void drawEye(Graphics::Surface &surface);
	void drawEyeCrosshair(Graphics::Surface &surface, int timeNow);
	void drawMouse(Graphics::Surface &surface);
	void drawGauge(Graphics::Surface &surface, int value, int x, int y, int width);
	void drawHumanGauge(Graphics::Surface &surface);
	void drawReplicantGauge(Graphics::Surface &surface);

	void calibrate();
	void beginTest();

	void startAdjustement();
	void stopAdjustement();
	void animateAdjustment(int target);
	void setAdjustment(int x);
	void setAdjustmentFromMouse();

	void findRelatedQuestionBySentenceId(int inSentenceId, int &outRelatedQuestionId, int &outRelatedIntensity);
	void askQuestion(int intensity);
};

} // End of namespace BladeRunner
#endif
