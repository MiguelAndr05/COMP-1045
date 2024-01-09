/*
Miguel Andrade
Sept 28, 23
this code uses a dial and led to change and modify the colour 
and change the speed of the delay
*/



int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data=0; //Used to store data from sensor.
int redPin=11; //red pin 
int bluePin = 10; //blue pin
int greenPin = 9; //red pin
int usInput = 0; //userinput
int lvl4Delay =500; //delay for level4

void loop() { //calling the level functions
  //level1 ();
  //level2(); 
  level3();
  //level4();

}

void setup() { //The Setup function runs once.

Serial.begin(9600); //this send data from Serial
	pinMode(rotationPin,INPUT); //getting input from the dial
	pinMode(redPin, OUTPUT); //allowing the pin to get power
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
  
}



void level1() { //The loop function runs forever.
data = analogRead(rotationPin); //Read the value from the light sensor and store it
//in the lightData variable.
Serial.print("Rotation value = ");
Serial.println(data); //Print the data to the serial port.
delay(1000); //Wait 1 second (1000mS) before running again.
}

  void level2() {
    //reverseing the dial and getting the data from the dial too
    data = 1023-analogRead(rotationPin); 
    
    analogWrite(redPin, 255); //give the led power 
    delay(data);
    analogWrite(redPin, 0); //shutting off the led power
    analogWrite(bluePin, 255);
    delay(data);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 255);
    delay(data);
    analogWrite(greenPin, 0);
    
    Serial.println(data); //print the delay 
   }
 
  void level3() { //ROYGBP
    data = analogRead(rotationPin);
   //red
    //if statement turning on led based on dial data
    if (data > 0 && data < 150) { 
      analogWrite(redPin, 255); //turn on led 
      analogWrite(greenPin,0);
  	  analogWrite(bluePin,0);
      Serial.println("Red"); //prints the colour
    } //orange
      else if (data > 151 && data < 300) {
            analogWrite(redPin, 255);
      		analogWrite(greenPin,165);
  	  		analogWrite(bluePin,0);	  
        Serial.println("Orange");
		//yellow
       }else if (data > 301 && data < 450) {
            analogWrite(redPin, 255);
      		analogWrite(greenPin,255);
  	  		analogWrite(bluePin,0);
        Serial.println("yellow");
           //green
        }else if (data > 451 && data < 600) {
            analogWrite(redPin, 0);
      		analogWrite(greenPin,255);
  	  		analogWrite(bluePin,0);
        Serial.println("Green");
            //blue
        }else if (data > 601 && data < 750) {
            analogWrite(redPin, 0);
      		analogWrite(greenPin,0);
  	  		analogWrite(bluePin,255);
        Serial.println("Blue");
  				//purple
        }else if (data > 751 && data < 1023) {
            analogWrite(redPin, 128);
      		analogWrite(greenPin, 0);
  	  		analogWrite(bluePin, 128);
        Serial.println("Purple");
      }
  }
            
	void level4() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    Serial.println("Type a letter R,G or B "); 
    //tells the user what to pick
    usInput = Serial.read();
    // tells you what you got
    Serial.print("I received: ");
    Serial.println(usInput, DEC);
      //prints the number the user get in decimal
    
    if (usInput == 114 || usInput==82) {
      //if statement taking userinput and showing colour
      analogWrite(redPin , 255);
      delay(lvl4Delay); //delay for level4
      analogWrite(redPin , 0);
    } else if (usInput == 103|| usInput==71) {
      analogWrite(greenPin , 255);
      delay(lvl4Delay);
      analogWrite(greenPin , 0);
    } else if (usInput == 98 || usInput == 66) {
      analogWrite(bluePin , 255);
      delay(lvl4Delay);
      analogWrite(bluePin , 0);
      }
  	}
  }
    
