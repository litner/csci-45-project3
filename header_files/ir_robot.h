#ifndef IR_ROBOT_H
#define IR_ROBOT_H

#include <errno.h>
#include <iostream>
#include <lirc/lirc_client.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wiringPi.h>
#include "./../header_files/random_player.h"
#include "./../header_files/relay.h"

using namespace std;

class IR_Robot {
  private:
    int buttonTimer;
    void checkCode(int);
    string code;
    struct lirc_config *config;
    int key(string);
    int MAXSIZE;
    RandomPlayer random_player;
    Relay relay;
  public:
    IR_Robot(void);
    ~IR_Robot(void);
    void start(void);
};
#endif
