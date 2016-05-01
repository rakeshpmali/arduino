 /*
  * Name:         LCD_Test
  * Description:  Drive Ultrasonic Sensor HC-SR04 & Display distance on 16x2 LCD
  * Pin Setup:    Trig = Pin 11; Echo = Pin 12
  *               LCD RS pin to digital pin 10
  *               LCD Enable pin to digital pin 9
  *               LCD D4 pin to digital pin 5
  *               LCD D5 pin to digital pin 4
  *               LCD D6 pin to digital pin 3
  *               LCD D7 pin to digital pin 2
  *               LCD R/W pin to ground
  * Author:       Rakesh Mali              
  */
    #include <LiquidCrystal.h> // includes the LiquidCrystal Library
    
    LiquidCrystal lcd(10, 9, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
    const int trigPin = 11;
    const int echoPin = 12;
    const int LEDPin = 13;
    int maxRange = 300; // Maximum range needed
    int minRange = 0; // Minimum range needed
    long duration;
    int distanceCm;
    
    void setup() 
    {
      Serial.begin (9600);
      lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display

      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }
    
    void loop()
    {
      // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      
      distanceCm = duration*0.034/2;

      if (distanceCm >= maxRange || distanceCm <= minRange)
      {
         distanceCm = -1;
         digitalWrite(LEDPin, HIGH); 
      }
      
      lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
      lcd.print("Dist: "); // Prints string "Distance" on the LCD
      lcd.print(distanceCm); // Prints the distance value from the sensor
      lcd.print(" cm");
      Serial.println(distanceCm);
      delay(800);
  
      lcd.clear(); // Clears the display 
     
    }
