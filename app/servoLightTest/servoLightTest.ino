//include the servo library

#include <Servo.h>

//create a servo object called servo1 Servo servo1;
Servo servo1;
Servo servo2;

void setup() { // put your setup code here, to run once:

  // set the servo pin, pin 9, as an servo output pin 
  servo1.attach(9);
  servo2.attach(5);

}
void loop() { 
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
}
