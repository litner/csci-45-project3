#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>
#include <errno.h>
#include "./header_files/sentry.h"

#define IR 26
#define RelayPin 22
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

int main(void) {

  struct lirc_config *config;
  int buttonTimer = millis();
  char *code;
  char *c;

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  //pinMode(IR, INPUT);
  pinMode(RelayPin, OUTPUT);

/*  while(1) {
    cout << code << endl;
    if(code==NULL) continue;  {
      if (millis() - buttonTimer > 400) {
        switch(key(code)) {
          case 1:
            cout << "crap1" << endl;
            digitalWrite(LedOne, HIGH);
            break;
          case 2:
            cout << "alsks" << endl;;
            digitalWrite(LedTwo, HIGH);
            break;
          case 3:
            digitalWrite(LedOne, LOW);
            digitalWrite(LedTwo, LOW);
            break;
          break;
        }
      }
    }
    free(code);
  }*/
  Sentry sentry;
  sentry.seek(code);

  return 0;
}

//PlaySound("C:\\Users\\Litner\\Desktop\\test.wav", NULL, SND_FILENAME);
