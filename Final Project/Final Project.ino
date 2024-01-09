/*
Miguel Andrade
Alarm Clock
Dec 16th, 23

The first button edits the alarm hour
The second buttond edits the alarm min
The third buttons edits tjh alarm sec

     I made the disign compact to try 
to look like the inside of a real alarm clock

the main issues i ran into was wiring that took alot of time
i just kept misplacing wires until i found the website below

Another issue i ran into was the updating of the alarm time
the math there was actually diffcult to pin point because mintue 
kept going in - nothing 
I ended up finding code that worked and used it for insperation 
and changed it up to work with my project
https://www.tinkercad.com/things/2oX9hyAlBHV-arduino-alarm-clock-40

I used an website to help with wiring because
i was struggling to get the LCD screen to display anything
https://www.instructables.com/Digital-Clock-Using-Tinkercad/

*/

// Initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>
//lcd list
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int currentHour = 1; //change the hour,min,sec
int currentMinute = 0; 
int currentSecond = 0;
int alarmSetHour = 0;
int alarmSetMinute = 0;
int alarmSetSecond = 10; //set to 10sec for the video
int buttonPinHour = 8;
int buttonPinMinute = 7;
int buttonPinSecond = 6;
int buzzer = 10;
bool alarmtriggerd = false; //tells another function that the alarm was triggerd


void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPinHour, INPUT);
  pinMode(buttonPinMinute, INPUT);
  pinMode(buttonPinSecond, INPUT);
  
  Serial.begin(9600);
}

void loop() {
//this small block of code is the logic to the entire time system in 
//this project
//it simple works by taking whatever time the user has added and 
//add +1 until it hit 60 sec and then adds one to a min and then repeats
//that cycle until there is 60 minutes and then goes to the hour
  
 
  currentSecond++;

  if (currentSecond == 60) {
    currentMinute++;
    currentSecond = 0;
  }

  if (currentMinute == 60) {
    currentMinute = 0;
    currentHour++;
  }

  if (currentHour == 24) {
    currentHour = 0;
  }
  /*
  This block of if statments just checks to see if a button was clicked
  and just adds +1 to alarmvarible
  Execpt for seconds since its constantly going down it goes up by
  +2
   */
     if (digitalRead(buttonPinHour) == HIGH) {
    alarmSetHour++;
    Serial.println("Hour's Button Pressed");//just for bebugging  
     }
  if (digitalRead(buttonPinMinute) == HIGH) {
    
    alarmSetMinute++;
    Serial.println("Minute's Button Pressed");
  }
  if (digitalRead(buttonPinSecond) == HIGH) {
    alarmSetSecond = alarmSetSecond + 2;
    Serial.println("Second's Button Pressed");
  }

    //calls all the functions
  delay(1000);
  displayClockTime();
  updateAlarmTime();
  displayAlarmTime();
}

/*
This is the logic for the alarm time
What this code does it that is simply removes
-1 from whatever the user sets the alarm too
and once all alarm varaibles hit zero it 
calls the alarm and sets its trigger to true
prompting the message


*/
void updateAlarmTime() {
  if (alarmSetHour == 0 && alarmSetMinute == 0 && alarmSetSecond == 0) {
    activateAlarm();
    alarmtriggerd = true;
  } else {
    if (alarmSetSecond > 0) {
      alarmSetSecond--;
    } else if (alarmSetMinute > 0) {
      alarmSetMinute--;
      alarmSetSecond = 59;  // Reset seconds to 59 when minutes decrement
    } else if (alarmSetHour > 0) {
      alarmSetHour--;
      alarmSetMinute = 59;  // Reset minutes to 59 when hours decrement
      alarmSetSecond = 59;  // Reset seconds to 59 when hours decrement
    }
  }
}

  //this function display the time before alarm time
  //while also checking if the alarm has been triggered
  //for the good moring message
void displayAlarmTime() {
  if (!alarmtriggerd) {
    lcd.setCursor(1, 0);
    lcd.print(alarmSetHour);
    lcd.setCursor(2, 0);
    lcd.print(":");
    lcd.setCursor(4, 0);
    lcd.print(alarmSetMinute);
    lcd.setCursor(6, 0);
    lcd.print(":");
    lcd.setCursor(8, 0);
    lcd.print(alarmSetSecond);
  } else {
    // Break out of the function if the alarm is triggered
    return;
  }
}

//this function display the normal clock time
//on the lcd screen
void displayClockTime() {
  lcd.setCursor(1, 1);
  lcd.print(currentHour);
  lcd.setCursor(2, 1);
  lcd.print(":");
  lcd.setCursor(4, 1);
  lcd.print(currentMinute);
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(8, 1);
  lcd.print(currentSecond);
}

//this function just works the buzzer once its called in updateAlarmTime()
//i attempt to make it sound like a stryotypical alarm clock like the movies
void activateAlarm() {
tone(10, 1000, 500);  
delay(400);         
tone(10, 1500, 500); 
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Time to Wake Up");
delay(400); 
tone(10, 1000, 500);  
delay(400);          
tone(10, 1500, 500); 
delay(400);
tone(10, 1500, 500); 
delay(400);
tone(10, 1500, 500); 
delay(400);
 
}
