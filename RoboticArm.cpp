#include <Servo.h> 

#define SERVO1 13
#define SERVO2 12
#define SERVO3 11
#define SERVO4 10 

Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 

int servo_value_1; 
int servo_value_2; 
int servo_value_3; 
int servo_value_4; 

double angle1; 
double angle2; 
double angle3; 
double angle4; 

void setup()
{
  Serial.begin(9600); 
  servo1.attach(SERVO1); 
  servo2.attach(SERVO2); 
  servo3.attach(SERVO3); 
  servo4.attach(SERVO4); 
}

void loop()
{
  servo_value_1 = analogRead(A4); 
  servo_value_2 = analogRead(A3); 
  servo_value_3 = analogRead(A2); 
  servo_value_4 = analogRead(A1); 
  
  angle1 = map(servo_value_1, 0, 1023, 0, 273); 
  angle2 = map(servo_value_2, 0, 1023, 0, 273); 
  angle3 = map(servo_value_3, 0, 1023, 0, 273); 
  angle4 = map(servo_value_4, 0, 1023, 0, 273); 
  
  servo1.write(angle1); 
  servo2.write(angle2); 
  servo3.write(angle3); 
  servo4.write(angle4);
  
  delay(15); 
}
