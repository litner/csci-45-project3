#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define servo 17
#define infrared 27

int main(void) {
  if(wiringPiSetupGpio() < 0) {
//    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  pinMode(infrared, INPUT);
  softPwmCreate(servo, 0, 100);


  while (1) { 
    for (int i = 0; i <= 25; i++) {
      softPwmWrite(servo, i);
      delay(100);
    }

    delay(50);

    for (int i = 25; i >= 0; i--) {
      softPwmWrite(servo, i);
      delay(100);
    }

    delay(50);
  }

  return 0;
}
