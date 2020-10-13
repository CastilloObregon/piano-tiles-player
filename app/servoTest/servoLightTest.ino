//include the servo library

#include <Servo.h>

//create a servo object called servo1 Servo servo1;
Servo servo1;

void setup() { // put your setup code here, to run once:

// set the servo pin, pin 9, as an servo output pin 
servo1.attach(9);

}
void loop() { // put your main code here, to run repeatedly:

int lightValue = analogRead(A0);

// map the light readings to the angle possible by the servo motor 
lightValue = map (lightValue, 0, 1023, 0, 180);


// control the servo motor based on the light value read, adjust linearly by angles 
servo1.write (lightValue); }
