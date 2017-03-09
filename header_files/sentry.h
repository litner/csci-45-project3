#ifndef SENTRY_H
#define SENTRY_H

#include <iostream>
#include <lirc/lirc_client.h>
#include <wiringPi.h>
#include "./../header_files/ir_robot.h"
#include "./../header_files/relay.h"
#include "./../header_files/servo_sensor.h"

using namespace std;

class Sentry {
  private:
    IR_Robot ir_robot;
    Relay relay;
    int result;
    ServoSensor servo_sensor;
  public:
    Sentry(void);
    ~Sentry(void);
    void seek(char*);
    void destroy(void);
};
#endif
