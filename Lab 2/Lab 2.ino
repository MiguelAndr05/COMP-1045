/* 
Miguel Andrade
Wednesday 20th, 23
This program uses RGB light
Running throught lightshow and different cycles of RGB
*/

   
int RGBRed = 11; //The red RGB LED is connected pin 11
int RGBGreen = 13; //The green RGB LED is connected pin 13 
int RGBBlue = 12; //The blue RGB LED is connected pin 12 
int waitTime = 2000; //src waittimes

//delay times for level 2 
int fast = 500; //dlay of 500 milliseconds
int medium = 1000; //delay of 1000 milliseconds
int slow = 1500; //delay of 1500 milliseconds
int slowaf = 2000; //delay of 2000 milliseconds
int faster = 200; //delay of 300 milliseconds

void loop() {
 //level1();
// level2();
 level3();
}

//random cycle
void cycle1() {
  //cyan
  digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH);
delay(fast); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW); 
  //red
  digitalWrite(RGBRed, HIGH); 
delay(slowaf); 
digitalWrite(RGBRed, LOW);
  //maginta
  digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
delay(medium); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW);
  //blue
  digitalWrite(RGBBlue, HIGH); 
delay(slow); 
digitalWrite(RGBBlue, LOW); 
  // Green
digitalWrite(RGBGreen, HIGH);  
delay(fast); 
digitalWrite(RGBGreen, LOW); 
  Serial.println("5.5 seconds for end of cycle 1"); //printstatment for time of lightshow
}
void cycle2() { //rainbow colours
  //red
  digitalWrite(RGBRed, HIGH); 
delay(fast); 
digitalWrite(RGBRed, LOW);  
  //yellow
  digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(fast); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBGreen, LOW);
//green
  digitalWrite(RGBGreen, HIGH);  
delay(fast); 
digitalWrite(RGBGreen, LOW);
  // Blue
digitalWrite(RGBBlue, HIGH); 
delay(fast); 
digitalWrite(RGBBlue, LOW); 
  //Magenta
  digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
delay(fast); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
  Serial.println("2.5 seconds for end of cycle 2");
  Serial.println("8 seconds in total"); //print statment for total time of lightshow
}
//rgb loop
void cycle3() {
  for(int rgbloop =0; rgbloop<3; rgbloop++) {
  // Red
digitalWrite(RGBRed, HIGH); 
delay(fast); 
digitalWrite(RGBRed, LOW); 
// Green
digitalWrite(RGBGreen, HIGH);  
delay(fast); 
digitalWrite(RGBGreen, LOW); 
// Blue
digitalWrite(RGBBlue, HIGH); 
delay(fast); 
digitalWrite(RGBBlue, LOW); 
   
  }
  Serial.println("4.5 seconds for end of cycle 3");
    Serial.println("12.5 seconds total");
}
//blues cycle
void cycle4() {
      // Blue
digitalWrite(RGBBlue, HIGH); 
delay(fast); 
digitalWrite(RGBBlue, LOW); 
      // White (Red + Blue + Green)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(slow); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW);
      // Cyan (Blue + Green)
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(fast); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW);
    

  Serial.println("2.5 seconds for end of cycle 4");
  	Serial.println("15 seconds End of LightShow"); //printing end of the light show
}

void setup() { //The Setup function runs once.
   
pinMode(RGBRed, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreen, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBlue, OUTPUT); //Setup blue RGB LED pin as an output pin.
Serial.begin(9600);
}

void level1() { //The loop function runs forever.
// Red
digitalWrite(RGBRed, HIGH); 
delay(waitTime); 
digitalWrite(RGBRed, LOW); 
// Green
digitalWrite(RGBGreen, HIGH);  
delay(waitTime); 
digitalWrite(RGBGreen, LOW); 
// Blue
digitalWrite(RGBBlue, HIGH); 
delay(waitTime); 
digitalWrite(RGBBlue, LOW); 
// Magenta (Red + Blue)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
delay(waitTime); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
// Yellow (Red + Green)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(waitTime); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBGreen, LOW);
// Cyan (Blue + Green)
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(waitTime); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW); 
// White (Red + Blue + Green)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(waitTime); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW); 
}

void level2() {
  
    cycle1(); //call for functions of the cycles 
    cycle2();
    cycle3();
    cycle4();
    delay (5000);
}

void level3() {
  double lightsdowndelay = 0;
  //for loop and varaible for level 3 runing through 10 times
  for(int lightsdown = 0; lightsdown < 10; lightsdown++) {
    // Red
digitalWrite(RGBRed, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBRed, LOW); 
// Green
digitalWrite(RGBGreen, HIGH);  
delay(lightsdowndelay); 
digitalWrite(RGBGreen, LOW); 
// Blue
digitalWrite(RGBBlue, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBBlue, LOW); 
// Magenta (Red + Blue)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
// Yellow (Red + Green)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBGreen, LOW);
// Cyan (Blue + Green)
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW); 
// White (Red + Blue + Green)
digitalWrite(RGBRed, HIGH); 
digitalWrite(RGBBlue, HIGH); 
digitalWrite(RGBGreen, HIGH); 
delay(lightsdowndelay); 
digitalWrite(RGBRed, LOW); 
digitalWrite(RGBBlue, LOW); 
digitalWrite(RGBGreen, LOW); 
  
 
    if (lightsdown == 1) {  //if statement tracking when lightsdown goes up and chaning the respected delaya
      lightsdowndelay = 1000/7;
      Serial.println(lightsdowndelay); //prints out what the delays change too once looped
    } else if (lightsdown == 2) {
      lightsdowndelay = 2000/7;
      Serial.println(lightsdowndelay);
    }  else if (lightsdown == 3) {
      lightsdowndelay = 3000/7;
      Serial.println(lightsdowndelay);
    }   else if (lightsdown == 4) {
      lightsdowndelay = 4000/7;
      Serial.println(lightsdowndelay);
    }    else if (lightsdown == 5) {
      lightsdowndelay = 5000/7;
      Serial.println(lightsdowndelay);
    }     else if (lightsdown == 6) {
      lightsdowndelay = 6000/7;
      Serial.println(lightsdowndelay);
    }      else if (lightsdown == 7) {
      lightsdowndelay = 7000/7;
      Serial.println(lightsdowndelay);
    }       else if (lightsdown == 8) {
      lightsdowndelay = 8000/7;
      Serial.println(lightsdowndelay);
    }        else if (lightsdown == 9) {
      lightsdowndelay = 9000/7;
      Serial.println(lightsdowndelay);
    }          else if (lightsdown == 10) {
      lightsdowndelay = 10000/7;
      Serial.println(lightsdowndelay);
      
    }
  }
}
