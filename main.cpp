#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  while(1) {
  
  }

  return 0;
}
