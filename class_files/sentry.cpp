#include "./../header_files/sentry.h"

Sentry::Sentry(void) {
  result = LOW;
  cout << "Turret Deployed" << endl;
}

Sentry::~Sentry(void) { }

void Sentry::seek(void) {
  while(1) {
    result = servo_sensor.searchLeft();

    if (result == HIGH)
      destroy();

    ir_robot.checkCode();

    delay(50);

    result = servo_sensor.searchRight();

    if (result == HIGH)
      destroy();

    ir_robot.checkCode();

    delay(50);
  }
}

void Sentry::destroy(void) {
  relay.on();

  delay(5000);

  relay.off();
}
