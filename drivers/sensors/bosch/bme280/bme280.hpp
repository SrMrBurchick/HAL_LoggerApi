/**@file bme280.hpp
 *
 * @desrc Decalration bme280 API's
 *
 * @authors
 *      Serhii Bura <serhiibura@gmail.com>
 */

#ifndef __BME280_HPP__
#define __BME280_HPP__

#include <cstdint>

#include "board_config.h"
#include "isensor.hpp"

#include "bme280.h"

typedef struct bme280_dev bme280_dev_st_t;
typedef struct bme280_data bme280_sensor_data_st_t;

struct identifier {
    uint8_t dev_addr;
};

typedef enum {
    BME280_MODE_FORCED = 0,
} bme280_mode_t;

class IBme280 : public ISensor {
    public:
        virtual ~IBme280() = default;
        result_t startMeasurements(bme280_mode_t mode);
    protected:
        explicit IBme280(sensor_type_t type, bme280_dev_st_t *dev);
    private:
        result_t initDevice();
        uint32_t getTemperature();
        uint32_t getHumidity();
        uint32_t getPressure();

        bme280_dev_st_t *m_bmeDevice;
        std::uint8_t    m_id;
        bool            measurementsRun;
};

class Bme280Temperature : public IBme280 {
    public:
        virtual ~Bme280Temperature() = default;
        explicit Bme280Temperature(bme280_dev_st_t *dev);
        virtual result_t getValue(int &) final;
};

class Bme280Humidity : public IBme280 {
    public:
        virtual ~Bme280Humidity() = default;
        explicit Bme280Humidity(bme280_dev_st_t *dev);
        virtual result_t getValue(int &) final;
};

class Bme280Pressure : public IBme280 {
    public:
        virtual ~Bme280Pressure() = default;
        explicit Bme280Pressure(bme280_dev_st_t *dev);
        virtual result_t getValue(int &) final;
};

#endif  // __BME280_HPP__
