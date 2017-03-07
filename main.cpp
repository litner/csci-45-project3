#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

#define IR 1
#define RelayPin 2
#define LedOne 23
#define LedTwo 24

using namespace std;

char *keymap[9] ={
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
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  pinMode(IR, INPUT);
  pinMode(RelayPin, OUTPUT);

  while(1) {
    if(code==NULL) continue;  {
      if (millis() - buttonTimer > 400) {
        switch(key(code)) {
          case 1:
            //std::cout << "crap1\n";
            digitalWrite(LedOne, HIGH);
            break;
          case 2:
            //std::cout << "alsks\n";
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
  }

  return 0;
}

//PlaySound("C:\\Users\\Litner\\Desktop\\test.wav", NULL, SND_FILENAME);
