/**@file	message.hpp
 *
 * @desrc Communication interface message
 *
 * @authors	
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include <cstdint>

typedef enum : std::uint8_t {
    eCommandMessage     = 0,
    eRequestMessage     = 1,
    eResponceMessage    = 2,
    eAcknowledgeMessage = 3
} message_type_t;

typedef enum : std::uint8_t {
    eResponceSuccess       = 0,
    eResponceCRCError      = 1,
    eResponceSequenceError = 2,
    eResponceUnknownError  = 0xF
} message_reponce_code_t;

#pragma pack(push, 1)

typedef struct message_header {
    std::uint8_t msg_id;
    std::uint8_t src_id;
    std::uint8_t dst_id;
    std::uint8_t msg_type : 2;
    std::uint8_t retry : 1;
    std::uint8_t sequence : 1;
    std::uint8_t resp_code : 4;
    std::uint16_t data_length;
} message_header_st_t;

typedef struct message {
    message_header_st_t header;
    std::uint8_t *data_p;
    std::uint32_t crc;
} message_st_t;

typedef struct empty_message {
    message_header_st_t header;
    std::uint32_t crc;
} empty_message_st_t;

#pragma pack(pop)

#endif /*_MESSAGE_HPP_*/
