#ifndef SENTRY_H
#define SENTRY_H

#include <iostream>
#include <wiringPi.h>
#include "./../header_files/servo_sensor.h"
#include "./../header_files/relay.h"

using namespace std;

class Sentry {
  private:
    ServoSensor servo_sensor;
    Relay relay;
    int result;
  public:
    Sentry(void);
    ~Sentry(void);
    void seek(void);
    void destroy(void);
};
#endif
