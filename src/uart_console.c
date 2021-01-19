#include <stdint.h>
#include "uart_console_api.h"

#define DEFAULT_TIMEOUT (10000)

struct console_handle {
	UART_HandleTypeDef *uartHandle_p;
	uint8_t isInit : 1;
};

static struct console_handle st_consoleController = {
	.uartHandle_p = NULL,
	.isInit = 0
};

result_t initConsole(UART_HandleTypeDef *uartHandle_p) {
	if (NULL == uartHandle_p) {
		return eResultFailed;
	}
	st_consoleController.uartHandle_p = uartHandle_p;
	st_consoleController.isInit = 1;
	return eResultSucces;
}

result_t writeToConsole(const char *msg, uint16_t len) {
	if (0 == st_consoleController.isInit) {
		return eResultNotInitialized;
	}
	if(NULL == msg) {
		return eResultFailed;
	}
	if (HAL_OK != HAL_UART_Transmit(st_consoleController.uartHandle_p, (uint8_t *)msg, len, DEFAULT_TIMEOUT)) {
		return eResultFailed;
	}
	return eResultSucces;
}

result_t redFromConsole(char* msg, uint16_t len) {
	if (0 == st_consoleController.isInit) {
		return eResultNotInitialized;
	}
	if(NULL == msg) {
		return eResultFailed;
	}
	if (HAL_OK != HAL_UART_Receive(st_consoleController.uartHandle_p, (uint8_t *)msg, len, DEFAULT_TIMEOUT)) {
		return eResultFailed;
	}
	return eResultSucces;
}