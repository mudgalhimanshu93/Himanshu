#include <LiquidCrystal.h>
#define          sensor           0
int  Vin;           //  Variable to read the value from the Arduino’s pin

float  tempc;
float tempf;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("temp =");
}

void loop() 
{
  Vin = analogRead (sensor);  /*   Tells the Arduino to read the pin and stores the value in “Vin” */

  tempc=(500*Vin)/1024;
  tempf=(tempc*9)/5+32;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(tempc);    // Exhibits the value of the temperature on the display

  lcd.print(" *c");
  lcd.setCursor(6, 1);
  lcd.print(tempf);
  lcd.print(" *F      ");
  //lcd.print(millis()/1000);
}

