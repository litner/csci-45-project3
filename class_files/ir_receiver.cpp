#include "./../header_files/ir_receiver.h"

IR_Receiver::IR_Receiver(void) {
  pinMode(IR, INPUT);
}

IR_Receiver::~IR_Receiver(void) { }
