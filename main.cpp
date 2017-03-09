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

using namespace std;

int main(void) {
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  Sentry sentry;
  sentry.seek();

  return 0;
}

//PlaySound("C:\\Users\\Litner\\Desktop\\test.wav", NULL, SND_FILENAME);
