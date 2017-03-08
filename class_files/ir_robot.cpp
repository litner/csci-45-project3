#include "./../header_files/ir_robot.h"

IR_Robot::IR_Receiver(void) {
  if(lirc_init("lirc", 1) == -1)
    exit(EXIT_FAILURE);

  keymap = new char [MAXSIZE] {
  " KEY_NUMERIC_0 ",
  " KEY_NUMERIC_1 ",
  " KEY_NUMERIC_2 ",
  " KEY_NUMERIC_3 ",
  " KEY_NUMERIC_4 ",
  " KEY_NUMERIC_5 ",
  " KEY_NUMERIC_6 ",
  " KEY_NUMERIC_7 ",
  " KEY_NUMERIC_8 ",
  " KEY_NUMERIC_9 "};

  buttonTimer = millis();
}

IR_Robot::~IR_Robot(void) {
  lirc_freeconfig(config);
  exit(EXIT_SUCCESS);
}

int IR_Robot::key(char *code) {
  int num = 0;

  for (int i = 0; i < MAXSIZE; i++)
    if (strstr(code, keymap[i]))
      num = i;

  return num + 1;
}

void IR_Robot::checkCode(void) {
  if (lirc_readconfig(NULL, &config, NULL) == 0) {
    if(code == NULL) continue;  {
      if (millis() - buttonTimer > 400) {
        switch(key(code)) {
          case 1:
            cout << key(code) << endl;
            break;
          case 2:
            cout << key(code) << endl;
            break;
          case 3:
            cout << key(code) << endl;
            break;
        }
      }
    }
    free(code);
  }
}
