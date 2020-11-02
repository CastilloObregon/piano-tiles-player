//include the servo library

#include <Servo.h>

//create a servo object called servo1 Servo servo1;
Servo servo7;
Servo servo9;
Servo servo11;
Servo servo13;

void setup() { // put your setup code here, to run once:

  //Start Serial
  Serial.begin(9600);
  Serial.println("Initialize setup");
  // set the servo pin, pin 9, as an servo output pin 
  servo7.attach(7);
  servo9.attach(9);
  servo11.attach(11);
  servo13.attach(13);
  Serial.println("Setup Done");

}
void loop() { 
    int lightValue7 = analogRead(A7);
    int lightValue9 = analogRead(A9);
    int lightValue11 = analogRead(A11);
    int lightValue13 = analogRead(A13);
    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue);  
    

    //int lightValue2 = analogRead(A5);
    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue2);  
    
    // map the light readings to the angle possible by the servo motor 
    lightValue7 = map (lightValue7, 0, 1023, 0, 90);
    lightValue9 = map (lightValue9, 0, 1023, 0, 90);
    lightValue11 = map (lightValue11, 0, 1023, 0, 90);
    lightValue13 = map (lightValue13, 0, 1023, 0, 90);

    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue);  

    // control the servo motor based on the light value read, adjust linearly by angles 
    servo7.write (lightValue7); 
    servo9.write (lightValue9);
    servo11.write (lightValue11);
    servo13.write (lightValue13);
}
