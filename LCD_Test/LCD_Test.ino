 /*
  * Name:         LCD_Test
  * Description:  Drive 16x2 LCD
  * Pin Setup:    LCD RS pin to digital pin 10
  *               LCD Enable pin to digital pin 9
  *               LCD D4 pin to digital pin 5
  *               LCD D5 pin to digital pin 4
  *               LCD D6 pin to digital pin 3
  *               LCD D7 pin to digital pin 2
  *               LCD R/W pin to ground
  * Author:       Rakesh Mali              
  */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}
