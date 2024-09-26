#ifndef EFLOGGING_H_
#define EFLOGGING_H_

#include "configuration.h"

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

#include "configuration.h"

#undef LOG
#undef LOG_DEBUG
#undef LOG_INFO
#undef LOG_WARNING
#undef LOG_ERROR
#undef LOG_FATAL

#ifdef USE_SEGGER
// #undef DEBUG_PORT
#define LOG(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#define LOG_DEBUG(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#define LOG_INFO(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#define LOG_WARNING(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#define LOG_ERROR(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#define LOG_FATAL(...) SEGGER_RTT_printf(0, __VA_ARGS__)
#else
#if defined(DEBUG_PORT) && !defined(DEBUG_MUTE) && !defined(PIO_UNIT_TESTING)
#define LOG(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_INFO, __VA_ARGS__); }
#define LOG_DEBUG(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_DEBUG, __VA_ARGS__); }
#define LOG_INFO(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_INFO, __VA_ARGS__); }
#define LOG_WARNING(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_WARN, __VA_ARGS__); }
#define LOG_ERROR(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_ERROR, __VA_ARGS__); }
#define LOG_FATAL(...) { DEBUG_PORT.log(MESHTASTIC_LOG_LEVEL_CRIT, __VA_ARGS__); }
#else
#define LOG(...)
#define LOG_DEBUG(...)
#define LOG_INFO(...)
#define LOG_WARNING(...)
#define LOG_ERROR(...)
#define LOG_FATAL(...)
#endif

#define LOGF(msg, format, ...) LOG(msg, format, ##__VA_ARGS__)
#define LOGF_DEBUG(msg, format, ...) LOG_DEBUG(msg, format, ##__VA_ARGS__)
#define LOGF_INFO(msg, format, ...) LOG_INFO(msg, format, ##__VA_ARGS__)
#define LOGF_WARNING(msg, format, ...) LOG_WARN(msg, format, ##__VA_ARGS__)
#define LOGF_ERROR(msg, format, ...) LOG_ERROR(msg, format, ##__VA_ARGS__)
#define LOGF_FATAL(msg, format, ...) LOG_FATAL(msg, format, ##__VA_ARGS__)
#endif

#endif /* EFLOGGING_H_ */
