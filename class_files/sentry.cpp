#include "./../header_files/sentry.h"

Sentry::Sentry(void) {
  if(lirc_init("lirc", 1)==-1)
    exit(EXIT_FAILURE);

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
    while(1) {
cout << "First" << endl;
      result = servo_sensor.searchLeft();

      if (result == HIGH)
        destroy();
cout << "Second" << endl;
      if(code != NULL)
        ir_robot.checkCode(code);

      delay(50);

      result = servo_sensor.searchRight();

      if (result == HIGH)
        destroy();

        if(code != NULL)
          ir_robot.checkCode(code);

      delay(50);
    }
  }
}

void Sentry::destroy(void) {
  relay.on();

  delay(5000);

  relay.off();
}
