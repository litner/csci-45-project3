#include "./../header_files/servo_sensor.h"

ServoSensor::ServoSensor(void) {
  pinMode(infrared, INPUT);
  softPwmCreate(servo, 0, 100);
}

ServoSensor::~ServoSensor(void) { }

int ServoSensor::searchLeft(void) {
  for (int i = 0; i <= 25; i++) {
    softPwmWrite(servo, i);

    if (digitalRead(infrared) == LOW)
      return HIGH;

    delay(100);
  }

  return LOW;
}

int ServoSensor::searchRight(void) {
  for (int i = 25; i >= 0; i--) {
    softPwmWrite(servo, i);

    if (digitalRead(infrared) == LOW)
      return HIGH;

    delay(100);
  }

  return LOW;
}
