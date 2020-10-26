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
  """
    int temp=digitalRead(8);
    // Serial.println("Intensity="); //print on serial monitor using ""
    // Serial.println(temp);         //display output on serial monitor
    // delay(300);
    int lightValue = analogRead(A0);
    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue);  
    

    int lightValue2 = analogRead(A5);
    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue2);  
    
    // map the light readings to the angle possible by the servo motor 
    lightValue = map (lightValue, 0, 1023, 0, 90);
    lightValue2 = map (lightValue2, 0, 1023, 0, 90);

    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue);  

    // control the servo motor based on the light value read, adjust linearly by angles 
    servo1.write (lightValue); 
    servo2.write (lightValue2);
"""
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
