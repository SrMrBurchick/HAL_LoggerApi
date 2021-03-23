/**@file stp_interface.cpp
 *
 * @desrc Serial Transport Protocol interface definition
 *
 * @authors	
 *      Serhii Bura <serhiibura@gmail.com>
 */

#include "stp_interface.hpp"

static StpInterface *StpInterface::m_stpInstance_p = nullptr;

result_t putMessage(message_st_t &message) {
    result_t result = eResultSucces;

    // TODO: Implement funtional
    //      Put message to the queue

    return result;
}

result_t getMessage(message_st_t &message) {
    result_t result = eResultSucces;

    // TODO: Implement funtional
    //      Get message from the queue

    return result;
}

CommunicationInterface *getInterface() {
    //TODO: Impement functional
    //      Allocate STP interface at the memory pool usin

    return m_stpInstance_p;
}

