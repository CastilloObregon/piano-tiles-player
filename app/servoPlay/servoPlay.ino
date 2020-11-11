#include <Servo.h>
Servo myservo_0;
Servo myservo_1;
Servo myservo_2;
Servo myservo_3;

void setup() {

myservo_0.attach (7);  
myservo_1.attach (9);  
//myservo_2.attach (11);  
//myservo_3.attach (13);  

pinMode(A7, INPUT);
pinMode(A9, INPUT);
//pinMode(A11, INPUT);
//pinMode(A13, INPUT);
Serial.begin(9600);
}

void loop() {

int light_0 = analogRead(A7);
Serial.println(light_0);  
int light_1 = analogRead(A9);
//Serial.println(light_1);
//int light_2 = analogRead(A11);
//Serial.println(light_2);
//int light_3 = analogRead(A13);
//Serial.println(light_3);        

 

if(light_0 > 500)
 {
      
for (int angle_0=0; angle_0<20; angle_0+=3)  
     {
      myservo_0.write(angle_0);  
       
     }
  }
else  
{
  int angle_0=0;
  myservo_0.write(angle_0);  
//  delay(5);  
 }

 

if(light_1 > 500) 
 {
      
for (int angle_1=0; angle_1<20; angle_1+=3) 
     {
      myservo_1.write(angle_1); 
//      delay(5);  
     }
  }
else  
{
  int angle_1=0;
  myservo_1.write(angle_1); 
//  delay(5); 
 }
//
// 
//
//if(light_2 > 500)
// {
//      
//for (int angle_2=0; angle_2<30; angle_2+=3)
//     {
//      myservo_2.write(angle_2);
////      delay(5); 
//     }
//  }
//else 
//{
//  int angle_2=0;
//  myservo_2.write(angle_2);  
////  delay(5);  
// }

// 
//
//
// if(light_3 > 400)
// {
//      
//for (int angle_3=0; angle_3<90; angle_3+=3) 
//     {
//      myservo_3.write(angle_3);
//      delay(5); 
//     }
//  }
//else 
//{
//  int angle_3=0;
//  myservo_3.write(angle_3);  
//  delay(1); 
// }  

}
