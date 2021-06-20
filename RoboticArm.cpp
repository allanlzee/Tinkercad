#include <Servo.h> 

#define SERVO1 13
#define SERVO2 12
#define SERVO3 11
#define SERVO4 10 

// Initialize Servos
Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 

// Initialize Potentiometer Values and Angles
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
  // Attach Servos to Digital Pins
  Serial.begin(9600); 
  servo1.attach(SERVO1); 
  servo2.attach(SERVO2); 
  servo3.attach(SERVO3); 
  servo4.attach(SERVO4); 
}

void loop()
{
  // Read in Potentiometer
  servo_value_1 = analogRead(A4); 
  servo_value_2 = analogRead(A3); 
  servo_value_3 = analogRead(A2); 
  servo_value_4 = analogRead(A1); 
  
  // Convert the range of 0 -> 1023 to 0 -> 546, which allows for angles 0 -> 360
  angle1 = map(servo_value_1, 0, 1023, 0, 546); 
  angle2 = map(servo_value_2, 0, 1023, 0, 546); 
  angle3 = map(servo_value_3, 0, 1023, 0, 546); 
  angle4 = map(servo_value_4, 0, 1023, 0, 546); 
  
  // Give the servo its respective angle
  servo1.write(angle1); 
  servo2.write(angle2); 
  servo3.write(angle3); 
  servo4.write(angle4);
  
  delay(20); 
}
