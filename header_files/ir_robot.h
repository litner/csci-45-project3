#ifndef IR_ROBOT_H
#define IR_ROBOT_H

#include <iostream>
#include <lirc/lirc_client.h>
#include <string.h>
#include <wiringPi.h>

using namespace std;

class IR_Robot {
  private:
    int buttonTimer;
    char *c;
    char *code;
    struct lirc_config *config;
    char *keymap;
    int MAXSIZE;

    int key(char*);
  public:
    IR_Robot(void);
    ~IR_Robot(void);
    void checkCode(void);
};
#endif
