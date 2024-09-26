#ifndef EFLED_H_
#define EFLED_H_

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

#define FASTLED_ALL_PINS_HARDWARE_SPI
#define FASTLED_ESP32_SPI_BUS HSPI

#include <FastLED.h>

#define EFLED_PIN_LED_DATA 21
#define EFLED_PIN_5VBOOST_ENABLE 9

/**
 * @brief Initial value for global maximum for the LED brightness, 0–255
 * Has a huge impact on battery life.
 *
 * WARNING: The 5V boost converter is unable to power all LEDs on a high brightness level! Max brightness of 255 works
 * only, if only a few LEDs are used at the same time. When using all LEDs even in a single color, values over 60 can
 * overwhelm it and cause the colors to glitch. To be safe, choose a value below 50!
 */
#define EFLED_MAX_BRIGHTNESS_DEFAULT 50

#define EFLED_TOTAL_NUM 17
#define EFLED_DRAGON_NUM 6
#define EFLED_EFBAR_NUM 11

#define EFLED_DARGON_OFFSET 0
#define EFLED_EFBAR_OFFSET 6

#define EFLED_DRAGON_NOSE_IDX 0
#define EFLED_DRAGON_MUZZLE_IDX 1
#define EFLED_DRAGON_EYE_IDX 2
#define EFLED_DRAGON_CHEEK_IDX 3
#define EFLED_DRAGON_EAR_BOTTOM_IDX 4
#define EFLED_DRAGON_EAR_TOP_IDX 5


/**
 * @brief Driver for badge LEDs
 */
class EFLedClass {

    protected:

        CRGB led_data[EFLED_TOTAL_NUM];  //!< Internal LED data structure
        uint8_t max_brightness;  //!< Maximum raw brightness (0-255)


    public:

        /**
        * @brief Structure to hold x and y coordinates in millimeters
        */
        struct LEDPosition {
          int x; // X coordinate in millimeters
          int y; // Y coordinate in millimeters
        };

        /**
         * @brief Constructs a new EFLed instance.
         */
        EFLedClass();

        /**
         * @brief Initializes this EFLed instance. Creates internal data structures,
         * resets FastLED library and initializes power circuit. Maximum brightness
         * for LEDs will be set to a sensible default.
         */
        void init();

        /**
         * @brief Initializes this EFLed instance. Creates internal data structures,
         * resets FastLED library and initializes power circuit.
         *
         * @param absolute_max_brightness Maximum raw brightness (0-255) the LEDs will
         * be allowed to be set to.
         */
        void init(const uint8_t absolute_max_brightness);

        /**
         * @brief Enables the +5V power domain
         */
        static void enablePower();

        /**
         * @brief Disabled the +5V power domain
         */
        static void disablePower();

        /**
         * @brief Disables all LEDs
         */
        void clear();

        /**
         * @brief Sets the global brightness for all LEDs in percent, relative to max brightness
         *
         * @param brightness Value between 0 (off) and 100 (high)
         */
        void setBrightnessPercent(const uint8_t brightness);

        /**
         * @brief Retrieves the current global brightness value
         *
         * @return Value between 0 (off) and 100 (high)
         */
        uint8_t getBrightnessPercent() const;

        /**
         * @brief Sets all LEDs according to the given color array
         *
         * @param color Array of colors for each LED
         */
        void setAll(const CRGB color[EFLED_TOTAL_NUM]);

        /**
         * @brief Sets all LEDs to the given color
         *
         * @param color Color to set
         */
        void setAllSolid(const CRGB color);

        /**
         * @brief Sets the dragons nose LED to the given color
         *
         * @param color Color to set
         */
        void setDragonNose(const CRGB color);

        /**
         * @brief Sets the dragons muzzle LED to the given color
         *
         * @param color Color to set
         */
        void setDragonMuzzle(const CRGB color);

        /**
         * @brief Sets the dragons eye LED to the given color
         *
         * @param color Color to set
         */
        void setDragonEye(const CRGB color);

        /**
         * @brief Sets the dragons cheek LED to the given color
         *
         * @param color Color to set
         */
        void setDragonCheek(const CRGB color);

        /**
         * @brief Sets the dragons bottom ear LED to the given color
         *
         * @param color Color to set
         */
        void setDragonEarBottom(const CRGB color);

        /**
         * @brief Sets the dragons top ear LED to the given color
         *
         * @param color Color to set
         */
        void setDragonEarTop(const CRGB color);

        /**
         * @brief Sets all the dragon LEDs to the given colors
         *
         * @param color Array of colors to set
         */
        void setDragon(const CRGB color[EFLED_DRAGON_NUM]);

        /**
         * @brief Sets all the EF bar LEDs to the given colors
         *
         * @param color Array of colors to set
         */
        void setEFBar(const CRGB color[EFLED_EFBAR_NUM]);

        /**
         * @brief Sets one of the EF bar LEDs to the given color
         *
         * @param idx Number of the led to set (from top to bottom)
         * @param color Color to set
         */
        void setEFBar(uint8_t idx, const CRGB color);

        /**
         * @brief Sets a single LED of the EFBar to one color and the remaining LEDs
         * to another color
         *
         * @param idx Number of the LED to set active (from top to bottom)
         * @param color_on Color to use for active LEDs
         * @param color_off Color to use for inactive LEDs
         */
        void setEFBarCursor(uint8_t idx, const CRGB color_on, const CRGB color_off);

        /**
         * @brief Fills the whole EF LED bar according to the given percentage.
         *
         * @param percent Value between 0 - 100 indicating the amount of the
         * EF LED bar to be filled (0: none, 50: half, 100: all)
         * @param color_on Color to use for active LEDs
         * @param color_off Color to use for inactive LEDs
         */
        void fillEFBarProportionally(uint8_t percent, const CRGB color_on, const CRGB color_off);

        /**
         * @brief Gets the position of the LED in millimeters relative to the upper left corner of the badge
         *
         * @param idx Number of the LED
         */
        static LEDPosition getLEDPosition(uint8_t idx);
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_EFLED)
extern EFLedClass EFLed;
#endif

#endif /* EFLED_H_ */

