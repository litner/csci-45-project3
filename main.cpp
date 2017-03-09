#include <errno.h>
#include <iostream>
#include <lirc/lirc_client.h>
#include <pthread.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wiringPi.h>
#include "./header_files/ir_robot.h"
#include "./header_files/sentry.h"

using namespace std;

int main(void) {
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  pthread_t robot, guard;

  Sentry sentry;
  IR_Robot ir_robot;

  system("omxplayer /home/pi/csci-45-project3/mp3s/start.mp3");

  pthread_create(&robot, NULL, ir_robot.start(), NULL);
  pthread_create(&guard, NULL< sentry.seek(), NULL);

  pthread_join(robot, NULL);
  pthread_join(guard, NULL);

  return 0;
}
