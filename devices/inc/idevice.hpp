/**@file idevice.hpp
*
* @desrc Base device interface
*
* @authors
*      Serhii Bura <serhiibura@gmail.com>
*/

#ifndef __IDEVICE_HPP__
#define __IDEVICE_HPP__

#include <cstdint>

typedef enum {
    eDeviceMonitor = 0,
    eDeviceControl
} device_type_t;

class IDevice {
       public:
               virtual const char *getJSONValue() = 0;
               virtual std::int32_t getDeviceSubType() const = 0;
               std::uint16_t getDeviceId() const { return m_id; };
               device_type_t getDeviceType() const { return m_type; };
               virtual ~IDevice() = default;

       protected:
               explicit IDevice(device_type_t type = eDeviceMonitor);

       private:
               std::uint16_t m_id;
               device_type_t m_type;
};

#endif  //__IDEVICE_HPP__
