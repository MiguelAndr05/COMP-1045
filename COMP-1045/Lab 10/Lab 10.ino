/*
Miguel Andrade
Learning how to use a servo 
Dec 6th 2023
*/


#include <Servo.h>

// Define the pins for the buttons and LEDs
int button1 = 7;
int button2 = 6;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Create a Servo object
Servo myservo;

// Define the initial angle for the servo
int angle = 0;

  // Set the LED pins as output
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  myservo.attach(4);
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
}


void loop() {
  level3();
 //level2();
 //level1();
   
}


void level3(){
  // Write the current angle to the servo
  myservo.write(angle);
// Check if button1 is pressed
  if(digitalRead(button1)==HIGH){
    Serial.println("forward");
    myservo.write(0);
    angle -= 45;
  }

  // Check if button2 is pressed
  if(digitalRead(button2)==HIGH){
    Serial.println("backward");
    myservo.write(-180);
    angle += 45;
  }
 
  if(angle == 0){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(angle == 45){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else if(angle == 90){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  else if(angle == 135) {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else if(angle == 180){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  }
  else if (angle >180){
    for (int i = 0;i<5;i++){
     angle -= 45;
     myservo.write(angle);
     delay(200);
    
    if(angle == 180)
    {
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    }
    else if(angle == 135) {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
   else if(angle == 90){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
    else if(angle == 45){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
   else if(angle == 0){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }     
  }
  }
  else if(angle <0){
    for (int i = 0;i<5;i++){
     angle += 45;
     myservo.write(angle);
     delay(200);
      
    if(angle == 0){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(angle == 45){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else if(angle == 90){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  else if(angle == 135) {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else if(angle == 180){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  }
 
		}
	}
}
void level2(){
  // Check if button1 is pressed
  if(digitalRead(button1)==HIGH){
    Serial.println("forward");
    myservo.write(25);
    delay(1500);
  }

  // Check if button2 is pressed
  if(digitalRead(button2)==HIGH){
    Serial.println("backward");
    myservo.write(-25);
    delay(1500);
  }
}

void level1(){
  // Move the servo to 180 degrees, wait for 1.5 seconds, then move it to 0 degrees
  myservo.write(180);
  delay(1500);
  myservo.write(0);
  delay(1500);
}