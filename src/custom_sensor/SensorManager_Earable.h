#ifndef EDGE_ML_EARABLE_SENSORMANAGER_EARABLE_H
#define EDGE_ML_EARABLE_SENSORMANAGER_EARABLE_H

#include "SensorID_Earable.h"
#include "SensorParseScheme.h"
#include "IMU_Sensor.h"
#include "BARO_Sensor.h"

class SensorManager_Earable : public SensorManagerInterface {
public:
    void setup() override {
        IMU_Sensor * imu = new IMU_Sensor();
        BARO_Sensor * baro = new BARO_Sensor();

        SensorInterface ** sensors = new SensorInterface * [MODULE_COUNT_PHYSICAL] {imu, baro};

        SensorManagerInterface::set_sensors(sensors);
        SensorManagerInterface::set_sensor_counts(SENSOR_COUNT, MODULE_COUNT_PHYSICAL);

        SensorManagerInterface::set_type_int(RETURN_TYPE_INT, INT_TYPE_COUNT);
        SensorManagerInterface::set_type_float(RETURN_TYPE_FLOAT, FLOAT_TYPE_COUNT);

        SensorManagerInterface::set_parse_scheme(PARSE_SCHEME_C, PARSE_TYPE_C, SENSOR_COUNT);

        SensorManagerInterface::init();
    }
};


#endif //EDGE_ML_EARABLE_SENSORMANAGER_EARABLE_H
