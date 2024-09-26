// MIT License
//
// Copyright 2024 Eurofurence e.V. 
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the “Software”),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

/**
 * @author Honigeintopf
 */
 
#include <Arduino.h>

#ifdef MESHTASTIC
#include <modules/ef28/src/util.h>
#else
#include <util.h>
#endif

const char* toString(EFBoardPowerState state) {
    switch (state) {
        case EFBoardPowerState::UNKNOWN:            return "Unknown";
        case EFBoardPowerState::USB:                return "USB";
        case EFBoardPowerState::BAT_NORMAL:         return "Battery";
        case EFBoardPowerState::BAT_BROWN_OUT_SOFT: return "Brown-out (soft)";
        case EFBoardPowerState::BAT_BROWN_OUT_HARD: return "Brown-out (hard)";
        default: return "INVALID";
    }
}

const char* toString(EFTouchZone zone) {
    switch (zone) {
        case EFTouchZone::Fingerprint: return "Fingerprint";
        case EFTouchZone::Nose:        return "Nose";
        default: return "INVALID";
    }
}

/**
 * @brief Calculates a wave animation. Used by bootupAnimation()
 */
const float wave_function(float x, float start, float end, float amplitude) {
    if (x < start || x > end) {
        return 0;
    }
    double normalized_x = (x - start) / (end - start) * M_PI;
    return amplitude * std::sin(normalized_x);
}

