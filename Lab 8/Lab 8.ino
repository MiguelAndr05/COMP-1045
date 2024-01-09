/*
Miguel ANdrade
Nov 7th 
Making an LCD screen display things and answering questions
*/



#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd( 10,9,5,4,3,2); //These pin numbers are hard coded in on the serial backpack
int buttonPin= 1;
int buttonPin2= 0;
int counter=0;
int newTopic = 0;
int newItem1 = 0;
int newItem2 = 0;
int newItem3 = 0;
int i=0;
int numitems = 5;

int yesCount = 0;
 int noCount = 0;

String array1[] = {"Pen", "Pencil", "Marker", "Highlighter", "crayon"};
int numitems1 = 5;
String array2[]	= {"Dog", "Cat", "Bird", "Mouse", "Rabbit"};
int numitems2 = 5;
String array3[]	= {"Tree","Bush","Grass", "Flower", "Cacti"};          	
int numitems3 = 5;

String questions[]= {"Did you eat?","Do you like horror?",
                     "like video games?","like dogs?","Can you draw?"};

void setup()
{
lcd.begin (16,2); //Initialize the LCD.
pinMode(buttonPin, INPUT);//Setup button pin as an input pin.
pinMode(buttonPin2, INPUT);
}

void loop() {
 // level1();
//level2();
// level3();
  level4();
}

void level1(){
lcd.clear();
lcd.setCursor(0,0); //goto first column and first line (0,0)
lcd.print("321"); //Print at cursor Location
lcd.setCursor(0,1); //goto first column and second line
lcd.print("Maker"); //Print at cursor Location
delay(1000);
}

void level2() {
lcd.clear();
//move name at first line  
for(int i = 0; i < 3;  i++)
{  
lcd.setCursor(i,0); //goto first column and first line (0,0)
lcd.print("Miguel Andrade"); //Print at cursor Location
delay(500);
lcd.clear();
}
//move name at second line  
for(int i = 2; i > -1; i--)
{  
lcd.setCursor(i,1); //goto first column and first line (0,0)
lcd.print("Miguel Andrade"); //Print at cursor Location
delay(500);
lcd.clear();
	}  
}

void level3() {
  // Display a welcome message if button hasn't been pressed yet
  if(counter == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Welcome!");
    delay(200);
  }
  
  // If button is pressed, increment the buttonPress counter
  if(digitalRead(buttonPin) == HIGH) 
  {
    counter++;
    delay(200);
  }
  
  // If button has been pressed once, display items from array1
  if(counter == 1)
  {
    for(i = 0; i < numitems1; i++) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(array1[i]);
      delay(1000);
      
      // If button is pressed, store the current item index and break the loop
      if(digitalRead(buttonPin) == HIGH)
      {
        newItem1 = i;
        break;
      }
    }
  }

  // If button has been pressed twice, display items from array2
  if(counter == 2) 
  {
    for(i = 0; i < numitems2; i++) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(array2[i]);
      delay(1000);
      
      // If button is pressed, store the current item index and break the loop
      if(digitalRead(buttonPin) == HIGH)
      {
        newItem2 = i;
        break;
      }
    }
  }

  // If button has been pressed thrice, display items from array3
  if(counter == 3) 
  {
    for (i = 0; i < numitems3; i++) 
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(array3[i]);
      delay(1000);
      
      // If button is pressed, store the current item index and break the loop
      if(digitalRead(buttonPin) == HIGH)
      {
        newItem3 = i;
        break;
      }
    }
  }    

  // If button has been pressed four times, display the selected items
  if(counter == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(array1[newItem1]);
    delay(500);
    lcd.setCursor(0, 8);
    lcd.print(array2[newItem2]);
    delay(500);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print(array3[newItem3]);
    delay(500);
  }

  // If button has been pressed five times, clear the LCD and reset the counter
  if(counter == 5)
  {
    lcd.clear();
    counter = 0;
    delay(200);
  }
}

void level4() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Yes: Button A");
  lcd.setCursor(0, 1);
  lcd.print("No: Button B");

  delay(3000); 

  // Ask all the questions
  for (int i = 0; i < numitems; i++)
  {
    askQuestion(i);
  }

  // Display the results
  displayResults();

  // Wait for a button press
  while (digitalRead(buttonPin) != HIGH && digitalRead(buttonPin2) != HIGH)
  {
    delay(10000); 
  }

  // Reset the counts
  yesCount = 0;
  noCount = 0;
  delay(1000); 
}

// Function to ask a question
void askQuestion(int questionIndex)
{
  bool answered = false;

  while (!answered)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(questions[questionIndex]);

    // If Button A is pressed, increment the yesCount and mark the question as answered
    if (digitalRead(buttonPin) == HIGH)
    {
      yesCount++;
      answered = true;
      delay(500);
    }
    // If Button B is pressed, increment the noCount and mark the question as answered
    else if (digitalRead(buttonPin2) == HIGH)
    {
      noCount++;
      answered = true;
      delay(500); 
    }
    delay(2000); 
  }
}

// Function to display the results
void displayResults()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Yes: " + String(yesCount));
  lcd.setCursor(0, 1);
  lcd.print("No: " + String(noCount));
  delay(5000); 
}
  
  
  
  
  
  
  
  
  
  
