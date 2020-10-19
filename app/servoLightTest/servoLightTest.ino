//include the servo library

#include <Servo.h>

//create a servo object called servo1 Servo servo1;
Servo servo1;

void setup() { // put your setup code here, to run once:

pinMode(8,INPUT);
// set the servo pin, pin 9, as an servo output pin 
servo1.attach(9);

}
void loop() { // put your main code here, to run repeatedly:
    int temp=digitalRead(8);
    // Serial.println("Intensity="); //print on serial monitor using ""
    // Serial.println(temp);         //display output on serial monitor
    // delay(300);
    int lightValue = analogRead(A0);
    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue);  

    // map the light readings to the angle possible by the servo motor 
    lightValue = map (lightValue, 0, 1023, 0, 45);

    Serial.println("Intensity="); //print on serial monitor using ""
    Serial.println(lightValue);  

    // control the servo motor based on the light value read, adjust linearly by angles 
    servo1.write (lightValue); 
}
