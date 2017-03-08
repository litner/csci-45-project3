#ifndef RELAY_H
#define RELAY_H

#include <wiringPi.h>

#define RelayPin 22

class Relay {
  public:
    Relay(void);
    ~Relay(void);
    void on(void);
    void off(void);
};
#endif
