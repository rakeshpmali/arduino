 /*
  * Name:         DHT11_LCD
  * Description:  Drive DHT11 & Display Temperature & Humidity Sensor on 16x2 LCD
  * Pin Setup:    DHT11 Signal = Pin 7;
  *               LCD RS = Pin 10
  *               LCD Enable = Pin 9
  *               LCD D4 = Pin 5
  *               LCD D5 = Pin 4
  *               LCD D6 = Pin 3
  *               LCD D7 = Pin 2
  *               LCD R/W = GND
  * Author:       Rakesh Mali              
  */
  
  #include <dht.h>
  #include <LiquidCrystal.h>

  LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

  dht DHT;

  #define DHT11_PIN 7

  void setup(){
  lcd.begin(16, 2);
  }

  void loop()
  {
    int chk = DHT.read11(DHT11_PIN);
    lcd.setCursor(0,0); 
    lcd.print("Temp = ");
    lcd.print(DHT.temperature);
    lcd.print(" \337C");
    lcd.setCursor(0,1);
    lcd.print("Humi = ");
    lcd.print(DHT.humidity);
    lcd.print(" %");
    delay(1000);
  }
