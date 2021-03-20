/**@file	communication_interface.hpp
 *
 * @desrc Communication interface declaration
 *
 * @authors	
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef _COMMUNICATION_INTERFACE_HPP__
#define _COMMUNICATION_INTERFACE_HPP__

#include "common.h"
#include "message.hpp"

class CommunicationInterface {
public:
    result_t putMessage(message_st_t &message) = 0;
    result_t getMessage(message_st_t &message) = 0;
    CommunicationInterface *getInterface() = 0;
    ~CommunicationInterface() = default;
protected:
    CommunicationInterface() = default;
};

#endif  // _COMMUNICATION_INTERFACE_HPP__
