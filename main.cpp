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

void *iRobot(void *);
void *iSentry(void *);

int main(void) {
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  pthread_t robot, guard;

  system("omxplayer /home/pi/csci-45-project3/mp3s/start.mp3");

  pthread_create(&robot, NULL, iRobot, NULL);
  pthread_create(&guard, NULL, iSentry, NULL);

  pthread_join(robot, NULL);
  pthread_join(guard, NULL);

  return 0;
}

void *iRobot(void *arg) {
  IR_Robot ir_robot;
  ir_robot.start();
}

void *iSentry(void *arg) {
  Sentry sentry;
  sentry.seek();
}
