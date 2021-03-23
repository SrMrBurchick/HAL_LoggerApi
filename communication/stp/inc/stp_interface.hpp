/**@file stp_interface.hpp
 *
 * @desrc Serial Transport Protocol interface declaration
 *
 * @authors	
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef _STP_INTERFACE_HPP__
#define _STP_INTERFACE_HPP__

#include "communicaton_interface.hpp"

class StpInterface : public CommunicationInterface{
public:
    result_t putMessage(message_st_t &message);
    result_t getMessage(message_st_t &message);
    CommunicationInterface *getInterface();
    ~CommunicationInterface() = default;
private:
    CommunicationInterface() = default;
    static StpInterface *m_stpInstance_p = nullptr;
};

#endif  // _STP_INTERFACE_HPP__
