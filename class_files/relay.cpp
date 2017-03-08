#include "./../header_files/relay.h"

Relay::Relay(void) {
  pinMode(RelayPin, OUTPUT);
}

Relay::~Relay(void) { }

void Relay::on(void) {
  digitalWrite(RelayPin, HIGH);
}

void Relay::off(void) {
  digitalWrite(RelayPin, LOW);
}
