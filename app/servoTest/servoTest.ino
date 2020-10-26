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
  xTaskCreate(
    taskServo,              /* Task function. */
    "taskServo1",            /* String with name of task. */
    2048,                     /* Stack size in words. */
    (void *) &data1,       /* Parameter passed as input of the task */
    1,                         /* Priority of the task. */
    NULL);
}
 
void taskServo(void * datos ){
  monitor_params parameter = *(monitor_params *)datos;
  Servo servo = parameter.servo;
  int servoPin = parameter.servoPin;
  servo.attach(servoPin);
  int lightValue = parameter.lightPin;
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
