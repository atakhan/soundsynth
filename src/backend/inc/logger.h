#ifndef SOUNDSYNTH_SRC_BACKEND_INC_LOGGER_H
#define SOUNDSYNTH_SRC_BACKEND_INC_LOGGER_H

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <stdbool.h>

#define LOG_FILE "debug.log"

typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_DEBUG,
    LOG_TRACE,
    LOG_ACTION
} log_level_t;

void log_message(log_level_t level, const char *format, ...);

#endif // SOUNDSYNTH_SRC_BACKEND_INC_LOGGER_H