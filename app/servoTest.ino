#include <Servo.h>
#include <Arduino_FreeRTOS.h>
 
int servoPin = 9;
Servo servo;  
int servoAngle = 0;   
void setup(){
  Serial.begin(9600);  
  servo.attach(servoPin);
  xTaskCreate(
    taskServo,              /* Task function. */
    "taskServo1",            /* String with name of task. */
    10000,                     /* Stack size in words. */
    NULL,       /* Parameter passed as input of the task */
    1,                         /* Priority of the task. */
    NULL);
}
 
void taskServo(void * parameter ){
	servo.write(0);   
   delay(10);         
   servo.write(45);   
   delay(10);         
}

void loop(){
}
