/**@file board_config.h
 *
 * @desrc Boards common
 *
 * @authors	
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

#include "common.h"
#include "logger_api.h"

typedef struct ops {
        result_t (*delay)(uint32_t);
} ops_st_t;

typedef struct board {
        logger_ops_st_t logger_ops;
        ops_st_t        board_ops;
} board_st_t;

#endif  // __BOARD_CONFIG_H__
