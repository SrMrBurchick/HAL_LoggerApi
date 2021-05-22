/**@file isenor.hpp
 *
 * @desrc Base sensor interface
 *
 * @authors
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef __ISENSOR_HPP__
#define __ISENSOR_HPP__

#include "idevice.hpp"

#include "board_config.h"

typedef enum {
    eSensorTemperature = 0,
    eSensorHumidity    = 1,
    eSensorPressure    = 2
} sensor_type_t;

class ISensor : public IDevice {
        public:
                virtual ~ISensor() = default;
                virtual result_t getValue(int &) = 0;
                virtual std::int32_t getDeviceSubType() const final {
                        return m_type;
                };

        protected:
                explicit ISensor(sensor_type_t type);

        private:
                sensor_type_t m_type;
};

#endif  //__ISENSOR_HPP__
