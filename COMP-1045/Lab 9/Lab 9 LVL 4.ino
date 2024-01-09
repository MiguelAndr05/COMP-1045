/*
Miguel Andrade
 Nov 15th, 23
Using an ir remote to turn on leds

*/

#include <IRremote.h>

#define IR_RECEIVE_PIN 11



//variables
int value = 1;
int redPIN = 13;
int bluePIN = 12;
int blue = 9;
int red = 10; 
int green = 6;

int counter = 0;
int freq1 = 1000;
int freq = 0;


void setup() {
  Serial.begin(9600);
 
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  pinMode(redPIN, OUTPUT);
  pinMode(bluePIN, OUTPUT);
  
  Serial.println("Please Hit Power to start");
  Serial.println("1. Lights Blue");
  Serial.println("2. Lights Red");
  Serial.println("3. Flash both red and blue");
  Serial.println("4. Pick what color youd like");
  
}


//main loop
void loop() {
  
  // Store the command from the IR signal
  if (IrReceiver.decode()) {
    value = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    Serial.println(value);
  }
   
  if (value == 0) {
    counter++;
    value = -1;  // Change value so that the counter doesn't increment again until the next 0 is received
    Serial.println(counter);
  }
  //make sure you press the on buttom
  if (counter == 1) { 
    //turn blue light on
 if (value == 16) {
  digitalWrite(bluePIN, HIGH);
  delay(500);
  digitalWrite(bluePIN, LOW);
} 
    //turn red light on
  else if 
   (value == 17) {
  digitalWrite(redPIN, HIGH);
  delay(500);
  digitalWrite(redPIN, LOW);
}
 // call the alternate function
  else if 
   (value == 18) {
	alernat();
} 
      //call the pickflash function
  else if (value == 20 ) {
    pickflash(); 
  } 
 }  
}

//funtion to flashlightshow
void pickflash() {
digitalWrite(red, HIGH); 
delay(200); 
digitalWrite(red, LOW);  
  //yellow
  digitalWrite(red, HIGH); 
digitalWrite(green, HIGH); 
delay(200); 
digitalWrite(red, LOW); 
digitalWrite(green, LOW);
//green
  digitalWrite(green, HIGH);  
delay(200); 
digitalWrite(green, LOW);
  // Blue
digitalWrite(blue, HIGH); 
delay(200); 
digitalWrite(blue, LOW); 
  //Magenta
  digitalWrite(red, HIGH); 
digitalWrite(blue, HIGH); 
delay(200); 
digitalWrite(red, LOW); 
digitalWrite(blue, LOW); 
  }
  




//function to flash LED
void alernat() {
 
  while(value==18)
  {
   digitalWrite(bluePIN, HIGH);
  digitalWrite(redPIN, HIGH);
  delay(500);
  digitalWrite(bluePIN, LOW);
  digitalWrite(redPIN, LOW);
  delay(500);
    return;
  }
  
} 
 
  
