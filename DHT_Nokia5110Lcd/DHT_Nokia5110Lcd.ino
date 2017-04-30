/* Temperature + Humidity on Nokia 5110*/
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;
byte prevTemp = 0, prevHumi = 0;

// for Nokia 5110 LCD-Display (84x48 pixels)
// D7 - Serial clock out (CLK or SCLK)
// D6 - Serial data out (DIN)
// D5 - Data/Command select (DC or D/C)
// D4 - LCD chip select (CE or CS)
// D3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup()   {
  //serial init
  Serial.begin(115200);
  // Display init
  display.begin();
  // Contrast setting
  display.setContrast(50);
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;

  // read without samples.
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    return;
  }

  //display on serial terminal
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" %");

  if(prevTemp != temperature || prevHumi != humidity) {
    display.clearDisplay();      // Display clear
    set_text(0,0,"* Weather *",BLACK);
    set_text(0,10,"Temp: ",BLACK);
    set_text(32,10,String(temperature),BLACK);
    set_text(42,10," 'C",BLACK);

    set_text(0,20,"Humi: ",BLACK);
    set_text(32,20,String(humidity),BLACK);
    set_text(42,20," %",BLACK);
  }
  prevTemp = temperature;
  prevHumi = humidity;
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}

void set_text(int x,int y,String text,int color){
  
  display.setTextColor(color); // Text color, black or white
  display.setCursor(x,y);      // Start-Position of Text
  display.println(text);       // Output text line
  display.display();           // Display update
}

