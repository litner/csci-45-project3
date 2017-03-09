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

#define uchar unsigned char

using namespace std;

class IR_Robot {
  private:
    int buttonTimer;
    char *c;
    char *code;
    struct lirc_config *config;
    int MAXSIZE;

    int key(char*);
  public:
    IR_Robot(void);
    ~IR_Robot(void);
    void checkCode(void);
};
#endif
