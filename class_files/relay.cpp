#include "./../header_files/relay.h"
<<<<<<< 8379e53c28702099e75a94c9952ade1e65d61b33

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
=======
>>>>>>> lots of stuff
