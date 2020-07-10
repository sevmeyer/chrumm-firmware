// Chrumm keyboard firmware 0.1.1
// https://github.com/sevmeyer/chrumm-firmware
//   ____ _   _ ____  _   _ _    _ _    _
//  / ___| |_| |  _ \| | | | \  / | \  / |
// | |   |  _  | |_) | | | |  \/  |  \/  |
// | |___| | | |  _ <| |_| | |\/| | |\/| |
//  \____|_| |_|_| \_\\___/|_|  |_|_|  |_|
//
// Copyright 2020 Severin Meyer
// Distributed under the Boost Software License 1.0
// See LICENSE.txt or https://www.boost.org/LICENSE_1_0.txt


#include "HID-Project.h"
#include "KeyCodes.h"


// Layout
// ------

const byte rowCount = 6;
const byte colCount = 14;

const byte rowPins[rowCount] = {A5, A4, A3, A2, A1, A0};
const byte colPins[colCount] = {12, 11, 10, 9, 7, 5, 3, 2, 1, 0, 4, 6, 8, 14};

const byte layerKeyIndex = 3*colCount + 0;
const KeyCode keys[2][rowCount*colCount] = {
{
	// Primary layer
	kEsc   ,kF1  ,kF2   ,kF3    ,kF4   ,kF5   ,kNone,kF6   ,kF7   ,kF8   ,kF9    ,kF10   ,kF11   ,kF12   ,
	kTilde ,k1   ,k2    ,k3     ,k4    ,k5    ,kF20 ,k6    ,k7    ,k8    ,k9     ,k0     ,kMinus ,kEqual ,
	kTab   ,kQ   ,kW    ,kE     ,kR    ,kT    ,kF21 ,kY    ,kU    ,kI    ,kO     ,kP     ,kLBrace,kRBrace,
	kNone  ,kA   ,kS    ,kD     ,kF    ,kG    ,kF22 ,kH    ,kJ    ,kK    ,kL     ,kColon ,kQuote ,kBSlash,
	kLShift,kZ   ,kX    ,kC     ,kV    ,kB    ,kUp  ,kN    ,kM    ,kComma,kPeriod,kSlash ,kRShift,kNone  ,
	kNone  ,kLAlt,kSpace,kBSpace,kLCtrl,kLeft ,kDown,kRight,kRCtrl,kEnter,kSpace ,kRAlt  ,kNone  ,kNone
},
{
	// Secondary layer
	kNone  ,kF13 ,kF14  ,kF15   ,kF16  ,kF17  ,kNone,kF18  ,kF19  ,kpDiv ,kpMul  ,kpSub  ,kF23   ,kF24 ,
	kNone  ,kNone,kNone ,kPrint ,kScrLk,kPause,kNone,kNone ,kp7   ,kp8   ,kp9    ,kpAdd  ,kNone  ,kNone,
	kNone  ,kNone,kNone ,kNone  ,kNone ,kNone ,kNone,kNone ,kp4   ,kp5   ,kp6    ,kpAdd  ,kNone  ,kNone,
	kNone  ,kNone,kNone ,kInsert,kHome ,kPgUp ,kNone,kNone ,kp1   ,kp2   ,kp3    ,kpEnter,kNone  ,kNone,
	kNone  ,kNone,kNone ,kDelete,kEnd  ,kPgDn ,kUp  ,kNone ,kp0   ,kp0   ,kpDot  ,kpEnter,kNone  ,kNone,
	kNone  ,kNone,kSpace,kBSpace,kNone ,kLeft ,kDown,kRight,kNone ,kEnter,kSpace ,kNone  ,kNone  ,kNone
}};


// Events
// ------

byte activeLayer = 0;

void press(byte index)
{
	if (index == layerKeyIndex)
		activeLayer = 1;
	else {
		BootKeyboard.add(keys[activeLayer][index]);
		BootKeyboard.send();
	}
}

void release(byte index)
{
	if (index == layerKeyIndex)
		activeLayer = 0;
	else {
		BootKeyboard.remove(keys[0][index]);
		BootKeyboard.remove(keys[1][index]);
		BootKeyboard.send();
	}
}


// Debounce
// --------

// Using the pingpong debounce algorithm
// https://sev.dev/hardware/better-debounce-algorithms/

const byte debounceFlip = 5;
const byte debounceMax  = 10;

byte debounceCounts[rowCount*colCount];

void debounce(byte index, byte signal)
{
	byte& count = debounceCounts[index];

	if (signal == 0) {
		if (count > 0) {
			if (--count == debounceFlip) {
				count = 0;
				press(index);
			}
		}
	}
	else {
		if (count < debounceMax) {
			if (++count == debounceFlip) {
				count = debounceMax;
				release(index);
			}
		}
	}
}


// Setup
// -----

void setup()
{
	for (byte row = 0; row < rowCount; ++row)
		pinMode(rowPins[row], INPUT_PULLUP);

	for (byte col = 0; col < colCount; ++col)
		pinMode(colPins[col], OUTPUT);

	for (byte col = 0; col < colCount; ++col)
		digitalWrite(colPins[col], HIGH);

	for (byte index = 0; index < rowCount*colCount; ++index)
		debounceCounts[index] = debounceMax;

	BootKeyboard.begin();
}


// Loop
// ----

unsigned long time = 0;

void loop()
{
	// Scan the matrix at most once per millisecond.
	// Because we simply test for equality, this works
	// correctly even when the time wraps around to 0.

	while (millis() == time)
		yield();

	time = millis();

	// The rows are set to INPUT_PULLUP and therefore read HIGH
	// by default. The columns are set to HIGH. During the scan,
	// one column at a time is set to LOW. If a switch is pressed,
	// the connected row is grounded and reads LOW as well.

	for (byte col = 0; col < colCount; ++col) {
		digitalWrite(colPins[col], LOW);

		for (byte row = 0; row < rowCount; ++row)
			debounce(row*colCount + col, digitalRead(rowPins[row]));

		digitalWrite(colPins[col], HIGH);
	}
}
