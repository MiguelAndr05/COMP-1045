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
int redPIN = 13;
int bluePIN = 12;

// Declare variables to keep track of the LED and power states
bool blueHIGH = false;
bool redHIGH = false;
bool powerHIGH = false;

// Setup function runs once when the program starts
void setup() {
  // Begin serial communication at 9600 baud
  Serial.begin(9600);
  
  // Initialize the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  // Set the LED pins as output
  pinMode(redPIN, OUTPUT);
  pinMode(bluePIN, OUTPUT);
  
  // Print a message to the serial monitor
  Serial.println("Please Hit Power to start");
}

// Loop function runs continuously
void loop() {
  // If an IR command is received
  if (IrReceiver.decode()) {
    // Store the received command value
    value = IrReceiver.decodedIRData.command;
    
    // Resume receiving IR commands
    IrReceiver.resume();

    // If the power button (button 0) is pressed
    if (value == 0) {
      // Toggle the power state
      powerHIGH = !powerHIGH;
      
      // Print a welcome message and instructions to the serial monitor
      Serial.println("Welcome!");
      Serial.println("Button 1 for Blue LED");
      Serial.println("Button 2 for Red LED");
      Serial.println("Button 3 for Both LEDs");             
    }

    // If the power is on
    if (powerHIGH) {
      // If button 1 is pressed, toggle the blue LED
      if (value == 16) {
        blueHIGH = !blueHIGH;
        digitalWrite(bluePIN, blueHIGH);
      }
      
      // If button 2 is pressed, toggle the red LED
      if (value == 17) {
        redHIGH = !redHIGH;
        digitalWrite(redPIN, redHIGH);
      }
      
      // If button 3 is pressed, toggle both LEDs
      if (value == 18) {
        blueHIGH = !blueHIGH;
        redHIGH = !redHIGH;
        digitalWrite(bluePIN, blueHIGH);
        digitalWrite(redPIN, redHIGH);
      }
    }
  }
}