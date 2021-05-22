#ifndef _LOGGER_API_H_
#define _LOGGER_API_H_

#include <stdint.h>
#include <stdarg.h>

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    eLogLevelError = 0,
    eLogLevelInfo,
    eLogLevelDebug,
    eLogLevelTrace,
    eLogLevelsCount
}logLevel_t;

typedef struct logger_ops{
    result_t (*init)();
    void     (*send_msg)(const char* fmt, uint16_t length);
    uint32_t (*get_sys_time)();
    void     (*start)(const char* fmt, va_list args);
} logger_ops_st_t;

result_t loggerInit(logger_ops_st_t *);
result_t loggerSetLogLevel(logLevel_t loglevel);
void logDebugMsg(const char* fmt, ...);
void logInfoMsg(const char* fmt, ...);
void logErrorMsg(const char* fmt, ...);
void logWarningMsg(const char* fmt, ...);
void logTraceMsg(const char* fmt, ...);
void loggerStart(const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /*_LOGGER_API_H_*/
