#ifndef IR_ROBOT_H
#define IR_ROBOT_H

#include <iostream>
#include <lirc/lirc_client.h>
#include <wiringPi.h>

class IR_Receiver {
  private:
    int buttonTimer;
    char *c;
    char *code;
    struct lirc_config *config;
    char *keymap[MAXSIZE]
    const int MAXSIZE = 10;

    int key(char*);
  public:
    IR_Receiver(void);
    ~IR_Receiver(void);
    void checkCode(void);
};
#endif
