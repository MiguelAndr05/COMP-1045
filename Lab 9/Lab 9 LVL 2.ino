/*
Miguel Andrade
 Nov 15th, 23
Using an ir remote to turn on leds
*/

// Include the IRremote library
#include <IRremote.h>

// Define the pin that the IR receiver is connected to
#define IR_RECEIVE_PIN 11

// Declare variables for the IR command value and the LED pins
int value;
int ledblue = 12;
int ledred = 13;

// Setup function runs once when the program starts
void setup() {
  // Begin serial communication at 9600 baud
  Serial.begin(9600);
  
  // Initialize the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  // Set the LED pins as output
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
}

// Loop function runs continuously
void loop() {
  // If an IR command is received
  if (IrReceiver.decode()) {
    // Resume receiving IR commands
    IrReceiver.resume();
    
    // Store the received command value
    value = IrReceiver.decodedIRData.command;  
    
    // Print the received command value to the serial monitor
    Serial.println(value);
  }
  
  // If button 1 is pressed, turn on the blue LED
  if (IrReceiver.decodedIRData.command == 16) {
    digitalWrite(ledblue, HIGH);
  }

  // If button 2 is pressed, turn on the red LED
  if (IrReceiver.decodedIRData.command == 17) {
    digitalWrite(ledred, HIGH);
  }

  // If button 3 is pressed, turn off the blue LED
  if (IrReceiver.decodedIRData.command == 18) {
    digitalWrite(ledblue, LOW);
  }

  // If button 4 is pressed, turn off the red LED
  if (IrReceiver.decodedIRData.command == 20) {
    digitalWrite(ledred, LOW);
  }

  // If button 5 is pressed, flash both LEDs 3 times
  if (IrReceiver.decodedIRData.command == 21) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledred, HIGH);
      digitalWrite(ledblue, HIGH);
      delay(500);
      digitalWrite(ledred, LOW);
      digitalWrite(ledblue, LOW);
      delay(500);
    }
  }
}