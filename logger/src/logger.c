#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "logger_api.h"

#define TRACE   "Trace"
#define DEBUG   "Debug"
#define INFO    "Info"
#define WARNING "Warning"
#define ERROR   "Error"

#define NEXT_LINE "\n\r"
#define MSECONDS_PRESCALER  (1000)
#define SECONDS_PRESCALER   (60)
#define MINUTES_PRESCALER   (60)
#define MSG_SIZE            (285)

#ifdef __cplusplus
extern "C" {
#endif

static const char* st_logPrefix = "[%02d:%02d:%02d:%04d] [%s]: ";
static uint8_t st_loggerBuffer[MSG_SIZE] = {0};
static logLevel_t st_logLevel = eLogLevelInfo;

logger_ops_st_t g_logger;

static void st_log_msg(const char* log, const char* fmt, va_list vargs) {
    uint32_t hours = 0;
    uint32_t minutes = 0;
    uint32_t seconds = 0;
    uint32_t mseconds = 0;
    uint32_t currentTime = 0;

    if (NULL != g_logger.get_sys_time) {
        currentTime = g_logger.get_sys_time();
    }

    mseconds = currentTime;
    seconds = mseconds / MSECONDS_PRESCALER;
    minutes = seconds / SECONDS_PRESCALER;
    hours = minutes / MINUTES_PRESCALER;

    if (minutes >= MINUTES_PRESCALER) {
        minutes = minutes % MINUTES_PRESCALER;
    }

    if (seconds >= SECONDS_PRESCALER) {
        seconds = seconds % SECONDS_PRESCALER;
    }

    if (mseconds >= MSECONDS_PRESCALER) {
        mseconds = mseconds % MSECONDS_PRESCALER;
    }

    memset(st_loggerBuffer, 0, MSG_SIZE);

    sprintf((char *)st_loggerBuffer, st_logPrefix, hours, minutes, seconds,
            mseconds, log);

    vsprintf((char *)(st_loggerBuffer + strlen((char *)st_loggerBuffer)),
             (char*)fmt, vargs);

    g_logger.send_msg((const char *)st_loggerBuffer,
                      (uint16_t)strlen((char *)st_loggerBuffer));
}


result_t loggerInit(logger_ops_st_t *logger_ops) {

    if (NULL == logger_ops ||
        NULL == logger_ops->init ||
        NULL == logger_ops->get_sys_time ||
        NULL == logger_ops->send_msg ||
        NULL == logger_ops->start) {

        return eResultInvalidParam;
    }

    memcpy(&g_logger, logger_ops, sizeof(logger_ops_st_t));

    return g_logger.init();
}

result_t loggerSetLogLevel(logLevel_t level) {
    if (eLogLevelsCount <= level) {

        return eResultFailed;
    }

    st_logLevel = level;

    return eResultSucces;
}

void logDebugMsg(const char* fmt, ...) {
    va_list valist;

    if (eLogLevelDebug <= st_logLevel) {
        va_start(valist, fmt);
        st_log_msg(DEBUG, fmt, valist);
        va_end(valist);
    }
}

void logInfoMsg(const char* fmt, ...) {
    va_list valist;

    if (eLogLevelInfo <= st_logLevel) {
        va_start(valist, fmt);
        st_log_msg(INFO, fmt, valist);
        va_end(valist);
    }
}

void logErrorMsg(const char* fmt, ...) {
    va_list valist;
    va_start(valist, fmt);
    st_log_msg(ERROR, fmt, valist);
    va_end(valist);
}

void logTraceMsg(const char* fmt, ...) {
    va_list valist;

    if (eLogLevelTrace <= st_logLevel) {
        va_start(valist, fmt);
        st_log_msg(TRACE, fmt, valist);
        va_end(valist);
    }
}

void loggerStart(const char* fmt, ...) {
    va_list valist;

    if(NULL == g_logger.start) {
        return;
    }

    va_start(valist, fmt);
    g_logger.start(fmt, valist);
    va_end(valist);
}

#ifdef __cplusplus
}
#endif

