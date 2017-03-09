#include "./../header_files/sentry.h"

Sentry::Sentry(void) {
  result = LOW;
  cout << "Turret Deployed" << endl;
  code = NULL;
  srand (time(NULL));
}

Sentry::~Sentry(void) { }

void Sentry::seek(void) {
    while(1) {
      result = servo_sensor.searchLeft();

      if (result == HIGH)
        destroy();

      delay(50);

      result = servo_sensor.searchRight();

      if (result == HIGH)
        destroy();

      delay(50);
    }
  }
}

void Sentry::destroy(void) {
  relay.on();

  random_player.play(rand() % 11 + 1);

  relay.off();
}
