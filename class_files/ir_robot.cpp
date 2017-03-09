#include "./../header_files/ir_robot.h"

IR_Robot::IR_Robot(void) {
  if(lirc_init("lirc", 1) == -1)
    exit(EXIT_FAILURE);

  free(code);
  //c = NULL;
  //code = NULL;
  MAXSIZE = 21;

  buttonTimer = millis();
}

IR_Robot::~IR_Robot(void) {
  lirc_freeconfig(config);
  exit(EXIT_SUCCESS);
}

int IR_Robot::key(char* code) {
  int num = 0;

  char *keymap[21] ={
    " KEY_CHANNELDOWN ",
    " KEY_CHANNEL ",
    " KEY_CHANNELUP ",
    " KEY_PREVIOUS ",
    " KEY_NEXT ",
    " KEY_PLAYPAUSE ",
    " KEY_VOLUMEDOWN ",
    " KEY_VOLUMEUP ",
    " KEY_EQUAL ",
    " BTN_0 ",
    " BTN_1 ",
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

  cout << "test2" << endl;

  for (int i = 0; i < MAXSIZE; i++) {
    cout << "test3" << endl;
    if (strstr(code, keymap[i]))  {
      num = i;
    }
  }

  cout << "test4:" << num << endl;

  return num + 1;
}

void IR_Robot::checkCode(void) {
  if (lirc_readconfig(NULL, &config, NULL) == 0) {
    if (millis() - buttonTimer > 400) {
      cout << "test1" << endl;
      lirc_nextcode(&code);
      switch(key(code)) {
        case 1:
          cout << "test5" << endl;
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
    free(code);
  }
}
