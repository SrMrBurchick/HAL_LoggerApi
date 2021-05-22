/**@file isensor.cpp
 *
 * @desrc Base sesnor device impelemantation
 *
 * @authors
 *      Serhii Bura <serhiibura@gmail.com>
 */

#include "logger_api.h"

#include "isensor.hpp"

ISensor::ISensor(sensor_type_t type)
: IDevice(eDeviceMonitor), m_type{type} {}
