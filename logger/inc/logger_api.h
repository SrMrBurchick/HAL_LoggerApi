#ifndef _LOGGER_API_H_
#define _LOGGER_API_H_

#include "common.h"

typedef enum {
    eLogLevelError = 0,
    eLogLevelInfo,
    eLogLevelDebug,
    eLogLevelTrace,
    eLogLevelsCount
}logLevel_t;

typedef struct logger_st{
    result_t (*init)();
    void     (*send_msg)(const char* fmt, uint16_t length);
    uint32_t (*get_sys_time)();
    void     (*start)(const char* fmt, ...);
} logger_st_t;

result_t loggerInit();
result_t loggerSetLogLevel(logLevel_t loglevel);
void logDebugMsg(const char* fmt, ...);
void logInfoMsg(const char* fmt, ...);
void logErrorMsg(const char* fmt, ...);
void logWarningMsg(const char* fmt, ...);
void logTraceMsg(const char* fmt, ...);
void loggerStart(const char* fmt, ...);

extern logger_st_t g_logger;

#endif /*_LOGGER_API_H_*/
