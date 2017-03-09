#include "./../header_files/sentry.h"

Sentry::Sentry(void) {
  result = LOW;
  cout << "Turret Deployed" << endl;
  code = NULL;
}

Sentry::~Sentry(void) {
  lirc_freeconfig(config);
  exit(EXIT_SUCCESS);
}

void Sentry::seek(void) {
  if(lirc_readconfig(NULL, &config , NULL)==0) {
    while(lirc_nextcode(&code)==0) {
      result = servo_sensor.searchLeft();

      if (result == HIGH)
        destroy();

      if(code==NULL) continue; {
        ir_robot.checkCode(code);
      }

      delay(50);

      result = servo_sensor.searchRight();

      if (result == HIGH)
        destroy();

        if(code==NULL) continue; {
          ir_robot.checkCode(code);
        }

      delay(50);
    }
  }
}

void Sentry::destroy(void) {
  relay.on();

  delay(5000);

  relay.off();
}
