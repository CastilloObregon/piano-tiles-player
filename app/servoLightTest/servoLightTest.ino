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
    int lightValue1 = analogRead(A0);
    int lightValue2 = analogRead(A1);
    int lightValue3 = analogRead(A2);
    int lightValue4 = analogRead(A3);
    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue);  
    

    //int lightValue2 = analogRead(A5);
    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue2);  
    
    // map the light readings to the angle possible by the servo motor 
    lightValue1 = map (lightValue1, 0, 1023, 0, 90);
    lightValue2 = map (lightValue2, 0, 1023, 0, 90);
    lightValue3 = map (lightValue3, 0, 1023, 0, 90);
    lightValue4 = map (lightValue4, 0, 1023, 0, 90);

    //Serial.println("Intensity="); //print on serial monitor using ""
    //Serial.println(lightValue);  

    // control the servo motor based on the light value read, adjust linearly by angles 
    servo7.write (lightValue1); 
    servo9.write (lightValue2);
    servo11.write (lightValue3);
    servo13.write (lightValue4);
}
