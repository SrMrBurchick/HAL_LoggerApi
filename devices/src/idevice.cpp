/**@file idevice.cpp
 *
 * @desrc Base device impelemantation
 *
 * @authors
 *      Serhii Bura <serhiibura@gmail.com>
 */

#include "logger_api.h"

#include "idevice.hpp"

static std::uint16_t st_last_id = 0;

IDevice::IDevice(device_type_t type) {
        m_id = st_last_id++;
        m_type = type;

        logDebugMsg("New device registered: %d", m_id);
}
