#ifndef _UART_CONSOLE_API_H_
#define _UART_CONSOLE_API_H_

#include "main.h"
#include "common_result.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct console_handle *console_handle_t;

result_t initConsole(UART_HandleTypeDef* uartHandle_p);
result_t writeToConsole(const char* msg, uint16_t len);
result_t redFromConsole(char* msg, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /*_CONSOLE_API_H_*/