/**@file bme280.cpp
 *
 * @desrc bme280 API definition
 *
 * @authors
 *      Serhii Bura <serhiibura@gmail.com>
 */

#include "bme280.hpp"
#include "logger_api.h"

static
result_t runMeasurementsForcedMode(bme280_dev_st_t *dev) {
    int8_t rslt = BME280_OK;
    uint8_t settings_sel = 0;

    /* Recommended mode of operation: Indoor navigation */
    dev->settings.osr_h = BME280_OVERSAMPLING_1X;
    dev->settings.osr_p = BME280_OVERSAMPLING_16X;
    dev->settings.osr_t = BME280_OVERSAMPLING_2X;
    dev->settings.filter = BME280_FILTER_COEFF_16;

    settings_sel = BME280_OSR_PRESS_SEL | BME280_OSR_TEMP_SEL |
                   BME280_OSR_HUM_SEL | BME280_FILTER_SEL;

    /* Set the sensor settings */
    rslt = bme280_set_sensor_settings(settings_sel, dev);
    if (BME280_OK != rslt) {
        logErrorMsg("Failed to set sensor settings (code %+d).", rslt);

        return eResultFailed;
    }

    rslt = bme280_set_sensor_mode(BME280_FORCED_MODE, dev);
    if (BME280_OK != rslt) {
        logErrorMsg("Failed to set sensor mode (code %+d).", rslt);
    }

    return eResultSucces;
}

IBme280::IBme280(sensor_type_t type, bme280_dev_st_t *dev)
    :ISensor(type) {
    if(nullptr == dev) {
        logErrorMsg("Invalid input: %p", dev);

        return;
    }

    m_id = ((struct identifier*)(dev->intf_ptr))->dev_addr;
    m_bmeDevice = dev;
    measurementsRun = false;
};

result_t IBme280::initDevice() {
}

result_t IBme280::startMeasurements(bme280_mode_t mode) {
    result_t result = eResultSucces;

    switch (mode) {
        case BME280_MODE_FORCED:
            result = runMeasurementsForcedMode(m_bmeDevice);

            break;
        default:
            logErrorMsg("Uknown mode: %d", mode);

            result = eResultFailed;

            break;
    }

    if (eResultSucces != result) {
        logErrorMsg("Failed to start measurements");
    } else {
        logDebugMsg("Measurements is succesfully runing in %d mode", mode);

        measurementsRun = true;
    }

    return result;
}

uint32_t IBme280::getTemperature() {
    bme280_sensor_data_st_t data;
    std::int32_t rslt = 0;

    of


}

uint32_t IBme280::getHumidity() {
}

uint32_t IBme280::getPressure() {
}

class Bme280Temperature : public IBme280 {
    public:
        virtual ~Bme280Temperature() = default;
        explicit Bme280Temperature(bme280_dev_st_t *dev);
        virtual int getValue() final;
};

class Bme280Humidity : public IBme280 {
    public:
        virtual ~Bme280Humidity() = default;
        explicit Bme280Humidity(bme280_dev_st_t *dev);
        virtual int getValue() final;
};

class Bme280Pressure : public IBme280 {
    public:
        virtual ~Bme280Pressure() = default;
        explicit Bme280Pressure(bme280_dev_st_t *dev);
        virtual int getValue() final;
};

