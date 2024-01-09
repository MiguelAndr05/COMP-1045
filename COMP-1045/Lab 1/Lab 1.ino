/* 
Miguel Andrade
Sept 6, 2023
Lab 1: Controlling LED; small Circuit 
*/

//vara
int redLED = 13; //tells the code where to send power
int blueLED = 12;

const int dot = 200; //morse code dot; unit 200 ms 
const int dash = 600; // morse code dash
const int SpacePart = 200; //give a space between dot and dash's of a letter
const int SpaceLetter = 600; // give a space between letters of one word
const int SpaceWord = 1400; // give a space between words

void setup()//give led power
{
 pinMode(redLED, OUTPUT); 
 pinMode(blueLED, OUTPUT);	
}

void loop() {
  //level1();
  //level2();
  level3();
  
}



// Level 3
void level3() {
  for (int alternatePattern = 0; alternatePattern < 5; alternatePattern++) {
  digitalWrite(redLED, HIGH);
  delay(300);
  digitalWrite(redLED, LOW);
  delay(300);
  digitalWrite(blueLED, HIGH);
  delay(300);
  digitalWrite(blueLED,LOW);
  delay(300); 
  }
  
 for (int samePattern = 0; samePattern < 4; samePattern++) {
      
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
  delay(300);  //Delay for both 
      
      digitalWrite(blueLED,LOW);
      digitalWrite(redLED, LOW);
  delay(300); //delay for both 
    }
}




//level 2 (my girlfriend gave me these words i regret asking her)
void level2() {
  //Dogs
  digitalWrite(redLED, HIGH); //D 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  digitalWrite(redLED, LOW); 
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  digitalWrite(redLED, LOW); //Spaceletter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //O
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH);
  delay(dash);
  
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //G
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //S
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  
  digitalWrite(redLED, LOW); //Space Between Word
  delay(SpaceWord);
  
  //are
  digitalWrite(redLED, HIGH); //A
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //R
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);                         
  
  digitalWrite(redLED, HIGH); //E
  delay(dot);
  
  digitalWrite(redLED, LOW); //Space Between Word
  delay(SpaceWord);
  
  //great
  digitalWrite(redLED, HIGH); //G
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //R
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dot);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //E
  delay(dot);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //A
  delay(dot);
  digitalWrite(redLED, LOW);
  delay(SpacePart);
  digitalWrite(redLED, HIGH); 
  delay(dash);
  
  digitalWrite(redLED, LOW); //Space Between letter
  delay(SpaceLetter);
  
  digitalWrite(redLED, HIGH); //T
  delay(dash);
   
}



  
//Level 1
  void level1(){
  
  //for loop for slow cycle looping 3 times with adding condition every loop
  for (int loopSlow = 0; loopSlow < 3; loopSlow++ ) { 
 
  digitalWrite(redLED, HIGH); 
  delay(1000);
  digitalWrite(redLED, LOW); 
  delay(1000);
 
 } 
  //for loop for fast cycle looping 3 times with adding condition every loop
  for (int loopFast = 0; loopFast < 3; loopFast++ ) { 
  
  digitalWrite(redLED, HIGH);
  delay(100); 
  digitalWrite(redLED, LOW);
  delay(100); 
  
  }
}
