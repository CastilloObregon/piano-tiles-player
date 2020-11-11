//include the servo library

#include <Servo.h>

unsigned long led1LastMillis = 0;
unsigned long led2LastMillis = 0;

//create a servo object called servo1 Servo servo1;
Servo servo1;
Servo servo2;

boolean servo1State = false;
boolean servo2State = false;

boolean cycleCheck(unsigned long *lastMillis, unsigned int cycle) 
{
 unsigned long currentMillis = millis();
 if(currentMillis - *lastMillis >= cycle)
 {
   *lastMillis = currentMillis;
   return true;
 }
 else
   return false;
}


void setup() { // put your setup code here, to run once:

  // set the servo pin, pin 9, as an servo output pin 
  servo1.attach(9);
  servo2.attach(5);

}
void loop() { 
    int temp=digitalRead(8);
    int lightValue = analogRead(A0);
    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue);  

    int lightValue2 = analogRead(A5);
    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue2);  

    if(cycleCheck(&led1LastMillis, servo1))
    {
      // digitalWrite(ledPin1, servo1State);
      // servo2State = !servo2State;
      servo1.write (lightValue); 
    }
    if(cycleCheck(&led2LastMillis, servo2))
    {
      // digitalWrite(ledPin2, servo2State);
      // servo2State = !servo2State;
      servo2.write (lightValue2);
    }
}
