#define RELAY_COIL 2
#define REVERSE_BUTTON 6
#define BREAK_BUTTON 7
#define POTENT 0
#define TRANSISTOR_BASE 8

int counterclockwise = 1; 
int potent = 0; 
int break_button = 0; 

void setup()
{
  Serial.begin(9600); 
  pinMode(RELAY_COIL, OUTPUT);
  pinMode(REVERSE_BUTTON, INPUT); 
  pinMode(TRANSISTOR_BASE, OUTPUT); 
  pinMode(BREAK_BUTTON, INPUT); 
}

void loop()
{ 
  if (digitalRead(BREAK_BUTTON) == 1) {
    break_button = (break_button + 1) % 2; 
    do {
    } while (digitalRead(BREAK_BUTTON) == 1); 
  }
  
  // Check for reversal button 
  if (digitalRead(REVERSE_BUTTON) == 1) {
    counterclockwise = (counterclockwise + 1) % 2; 
    do {
    } while (digitalRead(REVERSE_BUTTON) == 1); 
  }
  
  potent = analogRead(POTENT);
  
  // Reverse/stop the motor according to the boolean
  if (break_button) {
    analogWrite(TRANSISTOR_BASE, 1); 
  } else if (counterclockwise) {
    digitalWrite(RELAY_COIL, LOW);
  } else {
    digitalWrite(RELAY_COIL, HIGH);
  }
  
  // Send the potentiometer measure to the transistor
  if (!break_button) {
    int speed = max(round(potent/4), 2);
    analogWrite(TRANSISTOR_BASE, speed); 
    //Serial.print("Potentiometer: "); 
    Serial.println(speed); 
  } 
}
