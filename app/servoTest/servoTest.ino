#include <Servo.h>
#include <Arduino_FreeRTOS.h>
    
typedef struct Data
{
    int servoPin;
    int lightPin;
    Servo servo;
} monitor_params;

// Llamada a servos
Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4; 

void setup(){
  
  // Pines para servos
  int servoPins[4]= {7,9,11,13};
  // Pines para sensores
  int lightPins[4] = {analogRead(A0),analogRead(A1),analogRead(A3),analogRead(A4)};
   

  Serial.begin(9600);  

  // Task 1
  monitor_params data1 = {servoPins[0],lightPins[0],servo1};
  /*xTaskCreate(
    taskServo,         
    "taskServo1",      
    2048,              
    (void *) &data1,   
    1,     
    NULL);*/
    xTaskCreate(
    taskServo,         
    "taskServo1",      
    2048,              
    NULL,   
    1,     
    NULL);
}
 
void taskServo(void * datos ){
  Serial.println("Estas en taskServo");
  //monitor_params parameter = *(monitor_params *)datos;
  //Servo servo = parameter.servo;
  Servo servo;
  //int servoPin = parameter.servoPin;
  int servoPin = 7;
  servo.attach(servoPin);
  //int lightValue = parameter.lightPin;
  int lightValue = analogRead(A0);
  // Serial.println("Intensity="); //print on serial monitor using ""
  // Serial.println(temp);         //display output on serial monitor
  // delay(300);
  Serial.println("Intensity="); //print on serial monitor using ""
  Serial.println(lightValue);  

  // map the light readings to the angle possible by the servo motor 
  lightValue = map (lightValue, 0, 1023, 0, 45);

  Serial.println("Intensity="); //print on serial monitor using ""
  Serial.println(lightValue);  

  // control the servo motor based on the light value read, adjust linearly by angles 
  servo1.write (lightValue); 
}

void loop(){
}
