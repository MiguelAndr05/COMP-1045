int rotation_dial = 0;
bool light_status = false;
String sequence = "";
void set_brightness(String color) {
   int brightness = rotation_dial;
   Serial.print(color + "brightness: ");
   Serial.println(brightness);
}
void process_sequence() {
   for (int i = 0; i < sequence.length(); i++) {
      char color = sequence.charAt(i);
      if (color == 'R') {
         set_brightness("Red");
         light_status = true;
      }
      else if (color == 'G') {
         set_brightness("Green");
         light_status = true;
      }
      else if (color == 'B') {
         set_brightness("Blue");
         light_status = true;
      }
      else {
         Serial.println("Invalid color sequence.");
         light_status = false;
         break;
      }
   }
   
   if (light_status) {
      Serial.println("All LEDs have been set.");
   }
}
void setup() {
   Serial.begin(9600);
}
void loop() {
   if (sequence.length() == 0) {
      Serial.println("Please input the sequence of colors you would like to change in the format RGB, R = Red, G = Green, B = Blue. For example, RGB, GRB, BGR, etc.:");
      while (sequence.length() == 0) {
         if (Serial.available() > 0) {
            sequence = Serial.readStringUntil('\n');
            sequence.trim();
         }
      }
   }
   else {
      Serial.println("Enter a new sequence of colors:");
      while (sequence.length() == 0) {
         if (Serial.available() > 0) {
            sequence = Serial.readStringUntil('\n');
            sequence.trim();
         }
      }
   }
   
   if (sequence.length() != 3 || !(sequence.indexOf('R') != -1 && sequence.indexOf('G') != -1 && sequence.indexOf('B') != -1)) {
      Serial.println("Invalid input. Please provide a valid sequence with R, G, and B.");
      sequence = "";
      return;
   }
   
   process_sequence();
   sequence = "";
}