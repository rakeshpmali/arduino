    /*
    * Name:         Ultrasonic_Sensor_HC-SR04
    * Description:  Drive Ultrasonic Sensor HC-SR04
    * Pin Setup:    Trig = Pin 11; Echo = Pin 12
    * Author:       Rakesh Mali              
    */
    //Global variables
    const int trigPin = 11;  //Trigger Pin
    const int echoPin = 12;  //Echo Pin

    long duration;
    int distance;
    
    void setup() 
    {
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      Serial.begin(9600); // Starts the serial communication (used for displaying text on serial console)
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
      // Calculating the distance
      distance= duration*0.034/2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
    }
