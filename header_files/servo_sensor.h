#ifndef SERVO_SENSOR_H
#define SERVO_SENSOR_H

#include <wiringPi.h>
#include <softPwm.h>

#define servo 17
#define infrared 27

class ServoSensor {
  public:
    ServoSensor(void);
    ~ServoSensor(void);
    int searchLeft(void);
    int searchRight(void);
};
#endif
