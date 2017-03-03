#ifndef IR_REMOTE_CONTROL_H
#define IR_REMOTE_CONTROL_H

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

class IR_Remote_Control {
  private:
    char keymap;
    int key;
  public:
    
}
