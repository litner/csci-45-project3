#ifndef SENTRY_H
#define SENTRY_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "./../header_files/servo_sensor.h"
#include "./../header_files/relay.h"

class Sentry {
  private:
    ServoSensor servo_sensor;
    Relay relay;
    int result;
  public:
    Sentry(void);
    ~Sentry(void);
    void seek(void);
    void destroy(int);
};
#endif
