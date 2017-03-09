#ifndef SENTRY_H
#define SENTRY_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include "./../header_files/random_player.h"
#include "./../header_files/relay.h"
#include "./../header_files/servo_sensor.h"

using namespace std;

class Sentry {
  private:
    RandomPlayer random_player;
    Relay relay;
    int result;
    ServoSensor servo_sensor;
  public:
    Sentry(void);
    ~Sentry(void);
    void *seek(void);
    void destroy(void);
};
#endif
