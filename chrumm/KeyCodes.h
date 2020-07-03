#pragma once

#include "HID-Project.h"


// Shorter type name

using KeyCode = KeyboardKeycode;


// Shorter key names

constexpr KeyCode kNone = 0x00;

constexpr KeyCode kErrorRollOver  = 0x01;
constexpr KeyCode kErrorPostFail  = 0x02;
constexpr KeyCode kErrorUndefined = 0x03;

constexpr KeyCode kA = 0x04;
constexpr KeyCode kB = 0x05;
constexpr KeyCode kC = 0x06;
constexpr KeyCode kD = 0x07;
constexpr KeyCode kE = 0x08;
constexpr KeyCode kF = 0x09;
constexpr KeyCode kG = 0x0A;
constexpr KeyCode kH = 0x0B;
constexpr KeyCode kI = 0x0C;
constexpr KeyCode kJ = 0x0D;
constexpr KeyCode kK = 0x0E;
constexpr KeyCode kL = 0x0F;
constexpr KeyCode kM = 0x10;
constexpr KeyCode kN = 0x11;
constexpr KeyCode kO = 0x12;
constexpr KeyCode kP = 0x13;
constexpr KeyCode kQ = 0x14;
constexpr KeyCode kR = 0x15;
constexpr KeyCode kS = 0x16;
constexpr KeyCode kT = 0x17;
constexpr KeyCode kU = 0x18;
constexpr KeyCode kV = 0x19;
constexpr KeyCode kW = 0x1A;
constexpr KeyCode kX = 0x1B;
constexpr KeyCode kY = 0x1C;
constexpr KeyCode kZ = 0x1D;

constexpr KeyCode k1 = 0x1E;
constexpr KeyCode k2 = 0x1F;
constexpr KeyCode k3 = 0x20;
constexpr KeyCode k4 = 0x21;
constexpr KeyCode k5 = 0x22;
constexpr KeyCode k6 = 0x23;
constexpr KeyCode k7 = 0x24;
constexpr KeyCode k8 = 0x25;
constexpr KeyCode k9 = 0x26;
constexpr KeyCode k0 = 0x27;

constexpr KeyCode kEnter  = 0x28;
constexpr KeyCode kEsc    = 0x29;
constexpr KeyCode kBSpace = 0x2A;
constexpr KeyCode kTab    = 0x2B;
constexpr KeyCode kSpace  = 0x2C;
constexpr KeyCode kMinus  = 0x2D;
constexpr KeyCode kEqual  = 0x2E;
constexpr KeyCode kLBrace = 0x2F;
constexpr KeyCode kRBrace = 0x30;
constexpr KeyCode kBSlash = 0x31;
constexpr KeyCode kIntNum = 0x32;
constexpr KeyCode kColon  = 0x33;
constexpr KeyCode kQuote  = 0x34;
constexpr KeyCode kTilde  = 0x35;
constexpr KeyCode kComma  = 0x36;
constexpr KeyCode kPeriod = 0x37;
constexpr KeyCode kSlash  = 0x38;
constexpr KeyCode kCapsLk = 0x39;

constexpr KeyCode kF1  = 0x3A;
constexpr KeyCode kF2  = 0x3B;
constexpr KeyCode kF3  = 0x3C;
constexpr KeyCode kF4  = 0x3D;
constexpr KeyCode kF5  = 0x3E;
constexpr KeyCode kF6  = 0x3F;
constexpr KeyCode kF7  = 0x40;
constexpr KeyCode kF8  = 0x41;
constexpr KeyCode kF9  = 0x42;
constexpr KeyCode kF10 = 0x43;
constexpr KeyCode kF11 = 0x44;
constexpr KeyCode kF12 = 0x45;

constexpr KeyCode kPrint  = 0x46;
constexpr KeyCode kScrLk  = 0x47;
constexpr KeyCode kPause  = 0x48;
constexpr KeyCode kInsert = 0x49;
constexpr KeyCode kHome   = 0x4A;
constexpr KeyCode kPgUp   = 0x4B;
constexpr KeyCode kDelete = 0x4C;
constexpr KeyCode kEnd    = 0x4D;
constexpr KeyCode kPgDn   = 0x4E;
constexpr KeyCode kRight  = 0x4F;
constexpr KeyCode kLeft   = 0x50;
constexpr KeyCode kDown   = 0x51;
constexpr KeyCode kUp     = 0x52;

constexpr KeyCode kNumLk  = 0x53;
constexpr KeyCode kpDiv   = 0x54;
constexpr KeyCode kpMul   = 0x55;
constexpr KeyCode kpSub   = 0x56;
constexpr KeyCode kpAdd   = 0x57;
constexpr KeyCode kpEnter = 0x58;
constexpr KeyCode kp1     = 0x59;
constexpr KeyCode kp2     = 0x5A;
constexpr KeyCode kp3     = 0x5B;
constexpr KeyCode kp4     = 0x5C;
constexpr KeyCode kp5     = 0x5D;
constexpr KeyCode kp6     = 0x5E;
constexpr KeyCode kp7     = 0x5F;
constexpr KeyCode kp8     = 0x60;
constexpr KeyCode kp9     = 0x61;
constexpr KeyCode kp0     = 0x62;
constexpr KeyCode kpDot   = 0x63;

constexpr KeyCode kIntBSlash = 0x64;

constexpr KeyCode kApp    = 0x65;
constexpr KeyCode kPower  = 0x66;
constexpr KeyCode kpEqual = 0x67;

constexpr KeyCode kF13 = 0x68;
constexpr KeyCode kF14 = 0x69;
constexpr KeyCode kF15 = 0x6A;
constexpr KeyCode kF16 = 0x6B;
constexpr KeyCode kF17 = 0x6C;
constexpr KeyCode kF18 = 0x6D;
constexpr KeyCode kF19 = 0x6E;
constexpr KeyCode kF20 = 0x6F;
constexpr KeyCode kF21 = 0x70;
constexpr KeyCode kF22 = 0x71;
constexpr KeyCode kF23 = 0x72;
constexpr KeyCode kF24 = 0x73;

constexpr KeyCode kExec   = 0x74;
constexpr KeyCode kHelp   = 0x75;
constexpr KeyCode kMenu   = 0x76;
constexpr KeyCode kSelect = 0x77;
constexpr KeyCode kStop   = 0x78;
constexpr KeyCode kAgain  = 0x79;
constexpr KeyCode kUndo   = 0x7A;
constexpr KeyCode kCut    = 0x7B;
constexpr KeyCode kCopy   = 0x7C;
constexpr KeyCode kPaste  = 0x7D;
constexpr KeyCode kFind   = 0x7E;
constexpr KeyCode kMute   = 0x7F;
constexpr KeyCode kVolUp  = 0x80;
constexpr KeyCode kVolDn  = 0x81;

constexpr KeyCode kLockingCapsLk = 0x82;
constexpr KeyCode kLockingNumLk  = 0x83;
constexpr KeyCode kLockingScrLk  = 0x84;

constexpr KeyCode kpComma  = 0x85;
constexpr KeyCode kpEqual2 = 0x86;

constexpr KeyCode kInt1 = 0x87;
constexpr KeyCode kInt2 = 0x88;
constexpr KeyCode kInt3 = 0x89;
constexpr KeyCode kInt4 = 0x8A;
constexpr KeyCode kInt5 = 0x8B;
constexpr KeyCode kInt6 = 0x8C;
constexpr KeyCode kInt7 = 0x8D;
constexpr KeyCode kInt8 = 0x8E;
constexpr KeyCode kInt9 = 0x8F;

constexpr KeyCode kLang1 = 0x90;
constexpr KeyCode kLang2 = 0x91;
constexpr KeyCode kLang3 = 0x92;
constexpr KeyCode kLang4 = 0x93;
constexpr KeyCode kLang5 = 0x94;
constexpr KeyCode kLang6 = 0x95;
constexpr KeyCode kLang7 = 0x96;
constexpr KeyCode kLang8 = 0x97;
constexpr KeyCode kLang9 = 0x98;

constexpr KeyCode kErase   = 0x99;
constexpr KeyCode kSysReq  = 0x9A;
constexpr KeyCode kCancel  = 0x9B;
constexpr KeyCode kClear   = 0x9C;
constexpr KeyCode kPrior   = 0x9D;
constexpr KeyCode kReturn2 = 0x9E;
constexpr KeyCode kSep     = 0x9F;
constexpr KeyCode kOut     = 0xA0;
constexpr KeyCode kOper    = 0xA1;
constexpr KeyCode kClear2  = 0xA2;
constexpr KeyCode kCrSel   = 0xA3;
constexpr KeyCode kExSel   = 0xA4;

constexpr KeyCode kp00         = 0xB0;
constexpr KeyCode kp000        = 0xB1;
constexpr KeyCode kThousandSep = 0xB2;
constexpr KeyCode kDecimalSep  = 0xB3;
constexpr KeyCode kCurrency    = 0xB4;
constexpr KeyCode kSubCurrency = 0xB5;
constexpr KeyCode kpLParen     = 0xB6;
constexpr KeyCode kpRParen     = 0xB7;
constexpr KeyCode kpLBrace     = 0xB8;
constexpr KeyCode kpRBrace     = 0xB9;
constexpr KeyCode kpTab        = 0xBA;
constexpr KeyCode kpBSpace     = 0xBB;
constexpr KeyCode kpA          = 0xBC;
constexpr KeyCode kpB          = 0xBD;
constexpr KeyCode kpC          = 0xBE;
constexpr KeyCode kpD          = 0xBF;
constexpr KeyCode kpE          = 0xC0;
constexpr KeyCode kpF          = 0xC1;
constexpr KeyCode kpXor        = 0xC2;
constexpr KeyCode kpCaret      = 0xC3;
constexpr KeyCode kpPercent    = 0xC4;
constexpr KeyCode kpLess       = 0xC5;
constexpr KeyCode kpGreater    = 0xC6;
constexpr KeyCode kpAnd        = 0xC7;
constexpr KeyCode kpLogicAnd   = 0xC8;
constexpr KeyCode kpOr         = 0xC9;
constexpr KeyCode kpLogicOr    = 0xCA;
constexpr KeyCode kpColon      = 0xCB;
constexpr KeyCode kpPound      = 0xCC;
constexpr KeyCode kpSpace      = 0xCD;
constexpr KeyCode kpAt         = 0xCE;
constexpr KeyCode kpExclam     = 0xCF;
constexpr KeyCode kpMemStore   = 0xD0;
constexpr KeyCode kpMemRecall  = 0xD1;
constexpr KeyCode kpMemClear   = 0xD2;
constexpr KeyCode kpMemAdd     = 0xD3;
constexpr KeyCode kpMemSub     = 0xD4;
constexpr KeyCode kpMemMul     = 0xD5;
constexpr KeyCode kpMemDiv     = 0xD6;
constexpr KeyCode kpPlusMinus  = 0xD7;
constexpr KeyCode kpClear      = 0xD8;
constexpr KeyCode kpClearEntry = 0xD9;
constexpr KeyCode kpBin        = 0xDA;
constexpr KeyCode kpOct        = 0xDB;
constexpr KeyCode kpDec        = 0xDC;
constexpr KeyCode kpHex        = 0xDD;

constexpr KeyCode kLCtrl  = 0xE0;
constexpr KeyCode kLShift = 0xE1;
constexpr KeyCode kLAlt   = 0xE2;
constexpr KeyCode kLGui   = 0xE3;
constexpr KeyCode kRCtrl  = 0xE4;
constexpr KeyCode kRShift = 0xE5;
constexpr KeyCode kRAlt   = 0xE6;
constexpr KeyCode kRGui   = 0xE7;
