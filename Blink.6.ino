/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int RLedPin = 9;  // the PWM pin the RedLED is attached to
const int GLedPin = 10;  // the PWM pin the Green LED is attached to
const int BLedPin = 11;  // the PWM pin the Blue LED is attached to


int mood = 0;  //the toy's mood state
const int neutralMood = 10;  //the neutral mood state
unsigned long previousMillis = 0;
int fadingDirection = 1;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(RLedPin, OUTPUT);
  pinMode(GLedPin, OUTPUT);
  pinMode(BLedPin, OUTPUT);

  // initialize the mood state
  mood = neutralMood;
}

// the loop function runs over and over again forever
void loop() {
  float brightnessInterval = 225 / 10.0;
  if(mood >= neutralMood){
    analogWrite(RLedPin, 225);
    analogWrite(GLedPin, brightnessInterval * (mood - neutralMood));
    analogWrite(BLedPin, 225 - brightnessInterval * (mood - neutralMood));
  }
  else{
    analogWrite(BLedPin, 225 - brightnessInterval * (mood - neutralMood));
    analogWrite(GLedPin, brightnessInterval * (mood - neutralMood));
    analogWrite(RLedPin, 225);
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > 1000){
    mood = mood + fadingDirection;
    if(mood >= 20 || mood <= 0)
      fadingDirection = -fadingDirection;
    previousMillis = currentMillis;
  }
}
