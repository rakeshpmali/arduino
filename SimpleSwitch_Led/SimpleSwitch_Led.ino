/*
 This is simple program to operate LED based on switch status
 Pin 8 = Switch
 Pin 13 = LED (on board)
 When switch turned ON, LED turns ON & viceversa
 */

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an outpu (LED)
  pinMode(13, OUTPUT);

  // initialize digital pin 8 as an input (Switch)
  pinMode(8, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  if(1 == digitalRead(8))
    digitalWrite(13, HIGH);   
   delay(100);
   
  if(0 == digitalRead(8))
    digitalWrite(13, LOW);
  delay(100);              
  
}
