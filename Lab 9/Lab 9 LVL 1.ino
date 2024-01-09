/*
Miguel Andrade
 Nov 15th, 23
Using an IR remote to turn on leds
*/

#include <IRremote.h>
#define IR_RECEIVE_PIN 11


int value;

void setup() {
Serial.begin(9600);
IrReceiver.begin(IR_RECEIVE_PIN);
  
}

void loop() {

  if (IrReceiver.decode()) {
IrReceiver.resume();
value = IrReceiver.decodedIRData.command;
Serial.println(value);
    
	}
}