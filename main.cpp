#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>
#include <errno.h>
#include "./header_files/ir_robot.h"
#include "./header_files/sentry.h"

using namespace std;

int main(void) {
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n", strerror(errno));
    return 1;
  }

  Sentry sentry;
  IR_Robot ir_robot;

  system("omxplayer /home/pi/csci-45-project3/mp3s/start.mp3");

  int pid;
	pid = fork();

	if(pid == 0) {
    ir_robot.start();
		_exit(0);
	} else {
    sentry.seek();
		wait();
	}

  return 0;
}
