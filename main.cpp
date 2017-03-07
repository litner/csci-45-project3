#include <errno.h>
#include <iostream>
#include <lirc/lirc_client.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <time.h>
#include "./header_files/sentry.h"

#define IR 26
#define RelayPin 2
#define LedOne 20
#define LedTwo 21

using namespace std;

int cnt = 0;

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
" KEY_NUMERIC_0 ",
" BTN_0 ",
" BTN_1 ",
" KEY_NUMERIC_1 ",
" KEY_NUMERIC_2 ",
" KEY_NUMERIC_3 ",
" KEY_NUMERIC_4 ",
" KEY_NUMERIC_5 ",
" KEY_NUMERIC_6 ",
" KEY_NUMERIC_7 ",
" KEY_NUMERIC_8 ",
" KEY_NUMERIC_9 "};

int key(char *code) {
  int i;
  int num;

  for (i=0; i<21; i++){
    if (strstr(code, keymap[i]))  {
      num = i;
    }
  }
  return num + 1;
}

using namespace std;

int main(void) {
  struct lirc_config *config;
  int buttonTimer = millis();
  char *code;
  char *c;

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  Sentry sentry;
  sentry.seek();

  pinmode(IR, INPUT);
  if(lirc_init("lirc", 1) == -1)
    exit(EXIT_FAILURE);

  //pinMode(IR, INPUT);
  pinMode(RelayPin, OUTPUT);
  pinMode(LedOne, OUTPUT);
  pinMode(LedTwo, OUTPUT);

  if (lirc_readconfig(NULL, &config, NULL) == 0) {
    while(lirc_nextcode(&code) == 0) {
      cout << key(code) << endl;

      if(code==NULL) continue;  {
        if (millis() - buttonTimer > 400) {
          switch(key(code)) {
            case 13:
              cout << "crap1" << endl;
              digitalWrite(LedOne, HIGH);
              break;
            case 14:
              cout << "alsks" << endl;;
              digitalWrite(LedTwo, HIGH);
              break;
            case 15:
              digitalWrite(LedOne, LOW);
              digitalWrite(LedTwo, LOW);
              break;
            break;
          }
        }
      }
      free(code);
    }

    lirc_freeconfig(config);
    exit(EXIT_SUCCESS);
  }

  return 0;
}

//PlaySound("C:\\Users\\Litner\\Desktop\\test.wav", NULL, SND_FILENAME);
