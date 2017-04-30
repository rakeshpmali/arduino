// Nokia 5110 LCD-Display (84x48 pixels)

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// D7 - Serial clock out (CLK or SCLK)
// D6 - Serial data out (DIN)
// D5 - Data/Command select (DC or D/C)
// D4 - LCD chip select (CE or CS)
// D3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup()   {

  // Display initialization
  display.begin();

  // Contrast setting
  display.setContrast(55);
  display.clearDisplay();   // clears the screen and buffer
}

void loop() {
  
  display.setTextSize(1);
  set_text(11,0,"Hello Rocky!",BLACK);
  delay(500);
  
  display.drawLine(7,11,77,11,BLACK);
  display.display();
  delay(700);
  
  display.drawCircle(8,23,5,BLACK);
  display.display();
  delay(700);
  
  display.fillCircle(11,26,5,BLACK);
  display.display();
  delay(700);
  
  display.drawRect(25,18,10,10,BLACK);
  display.display();
  delay(700);

  display.fillRect(28,21,10,10,BLACK);
  display.display();
  delay(700);

  display.drawRoundRect(47,18,10,10,2,BLACK);
  display.display();
  delay(700);
  
  display.fillRoundRect(50,21,10,10,2,BLACK);
  display.display();
  delay(700);
  
  display.drawTriangle(68,18,68,28,78,23,BLACK);
  display.display();
  delay(700);

  display.fillTriangle(71,21,71,31,81,26,BLACK);
  display.display();
  delay(700);
  
  // A little bit scroll-text magic
  int x=0;
  for(int i=0;i<(5.6*8);i++){
    set_text(x,40,"www.iotopia.in",BLACK);
    delay(i==0?800:500);
    if(i<(5.6*8)-1)set_text(x,40,"www.iotopia.in",WHITE);
    if((i)<(2.74*8))x-=1;else x+=1;
  }
  delay(250);
  
  display.clearDisplay();      // Display clear
}

void set_text(int x,int y,String text,int color){
  
  display.setTextColor(color); // Text color, black or white
  display.setCursor(x,y);      // Start-Position of Text
  display.println(text);       // Output text line
  display.display();           // Display update
}

