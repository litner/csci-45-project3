#include "./../header_files/ir_robot.h"

IR_Robot::IR_Robot(void) {
  if(lirc_init("lirc", 1) == -1)
    exit(EXIT_FAILURE);

  buttonTimer = millis();
  code = NULL;
  MAXSIZE = 10;
  cout << "Robot Activated, waiting for command" << endl;
}

IR_Robot::~IR_Robot(void) { }

int IR_Robot::key(char* code) {
  int num = 0;

  char *keymap[MAXSIZE] ={
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

  for (int i = 0; i < MAXSIZE; i++) {
    if (strstr(code, keymap[i]))  {
      num = i;
    }
  }

  return num + 1;
}

void IR_Robot::checkCode(char* code) {
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

void IR_Robot::start(void) {
  if(lirc_readconfig(NULL, &config, NULL) == 0) {
      while(lirc_nextcode(&code)==0)  {
        if(code == NULL) continue;  {
          if (millis() - buttonTimer > 400)
            checkCode(code);
        }

        free(code);
      }

    lirc_freeconfig(config);
  }

  lirc_deinit();

  exit(EXIT_SUCCESS);
}
