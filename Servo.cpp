#include <Servo.h>
#define SERVO1 13
#define SERVO2 12
#define SERVO3 11
#define SERVO4 10

Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 

int position = 0; 

void setup() {
  servo1.attach(SERVO1); 
  servo2.attach(SERVO2); 
  servo3.attach(SERVO3); 
  servo4.attach(SERVO4); 
}

void loop() {
  for (position = 0; position <= 180; position++) {
    servo1.write(position); 
    servo2.write(position); 
    servo3.write(position); 
    servo4.write(position); 
    delay(15);
  }
  
  delay(1000); 
  
  for (position = 180; position >= 0; position--) {
    servo1.write(position);
    servo2.write(position); 
    servo3.write(position); 
    servo4.write(position); 
    delay(15); 
  }
}
