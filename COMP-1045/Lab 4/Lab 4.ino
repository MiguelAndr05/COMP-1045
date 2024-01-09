int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int redLed = 13; //red led
int blueLed = 12;//blue led	
int greenLed = 11;//green led 
int lvlLEDS[] = {10,11,12,13}; //led array



void setup() { //The Setup function runs once.
Serial.begin(9600); 
  pinMode(redLed, OUTPUT); //give power to the led
  pinMode(blueLed, OUTPUT);//give power to the led
  pinMode(greenLed, OUTPUT);//give power to the led

}

void loop() {
 //level1(); 
 //level2();
 level3();
 //level4();
}



void level1() { //The loop function runs forever.
data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData
data = map(data,6,679,0,100); //map the data value to a percentage
Serial.print("Light value =");
Serial.println(data); //Print the data to the serial port.
delay(1000); //Wait 1 second (1000mS) before running again.
}

void level2() {
  data = analogRead(lightPin);
  data = map(data, 6, 679 , 0 , 100);
  
  if (data < 50) { //once aboue 50% display both at same time
   digitalWrite(redLed, HIGH); 
   digitalWrite(blueLed, HIGH);
   delay(1000);
   digitalWrite(redLed, LOW);
   digitalWrite(blueLed, LOW);
  }
}

void level3() {
  data = analogRead(lightPin);
  data = map(data, 6, 679 , 0 , 100); //make the data value easier to work with
  
  if (data >= 50) { //if its below 50 it displys the led
    digitalWrite (redLed, HIGH);
  	} 
  else {
    digitalWrite(redLed, LOW);
    }
  
  if (data >= 30 && data <= 60) { //if the below above 30 and below 60
    digitalWrite (blueLed, HIGH);
    }
  else { 
  	digitalWrite (blueLed, LOW);
  	}
  
  if (data < 33) {
  digitalWrite(greenLed, HIGH); //repeat at a slowly rate 1000ms
  delay(1000);
  digitalWrite(greenLed,LOW); 
   delay(1000);
  } else if (data > 66){ 
  digitalWrite(greenLed, HIGH); //repeat at a faster rate
  delay(200);
  digitalWrite(greenLed,LOW);
  delay(200);
} else {
  digitalWrite(greenLed, LOW); //if its not between those nums it turns off
  }
  Serial.println(data); //prints data
}

void level4() {
  data = analogRead(lightPin);
  data = map(data, 6, 679 , 0 , 15); //setting value 0-15
  
  for (int ledvalue = 0; ledvalue < 4; ledvalue++) {
    int binaryNum = 1 << ledvalue; //shift the value of one by one place based on the ledvaluve
    if (binaryNum & data) { 
      digitalWrite(lvlLEDS[ledvalue],HIGH); //sets the array to high
    } else {
      digitalWrite(lvlLEDS[ledvalue],LOW); //sets the array to low
      Serial.println(data); //prints value of data
    }
   }
}
  
  
  
 