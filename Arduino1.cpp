// Analog Pins
#define NOTE_C 13
#define NOTE_D 12
#define NOTE_E 11
#define NOTE_F 10
#define NOTE_G 9
#define NOTE_A 8
#define NOTE_B 7
#define HIGH_C 6
#define POT 0

#define PIEZO 4

int state;
double octaveMultiplier;

// frequencies of notes #define POT 0
double C = 0.0;
double D = 0.0;
double E = 0.0;
double F = 0.0;
double G = 0.0;
double A = 0.0;
double B = 0.0;
double C_HIGH = 0.0;

void setup()
{  
  pinMode(NOTE_C, INPUT); 
  pinMode(NOTE_D, INPUT); 
  pinMode(NOTE_E, INPUT); 
  pinMode(NOTE_F, INPUT); 
  pinMode(NOTE_G, INPUT); 
  pinMode(NOTE_A, INPUT); 
  pinMode(NOTE_B, INPUT); 
  pinMode(HIGH_C, INPUT);  
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
  
  state = 0;
  octaveMultiplier = 0.0;
  
  C = 65.41;
  D = 73.42;
  E = 82.41;
  F = 87.31;
  G = 98.00;
  A = 110.00;
  B = 123.47;
  C_HIGH = 130.81;
}

void loop()
{
  
  if (analogRead(POT) >= 0 && analogRead(POT) < 164){
    state = 0;
  } else if (analogRead(POT) >= 164 && analogRead(POT) < 348){
    state = 1;  
  } else if (analogRead(POT) >= 348 && analogRead(POT) < 511){
    state = 2;  
  } else if (analogRead(POT) >= 511 && analogRead(POT) < 675){
    state = 3;  
  } else if (analogRead(POT) >= 675 && analogRead(POT) < 859){
	state = 4;  
  } else if (analogRead(POT) >= 859 && analogRead(POT) < 1023){
	state = 5;
  }
  
  octaveMultiplier = pow(2, state);
  
  if (digitalRead(NOTE_C) == 1) {
    tone(PIEZO, C * octaveMultiplier, 250);	// plays note c
    
  } else if (digitalRead(NOTE_D) == 1) {
    tone(PIEZO, D * octaveMultiplier, 250);	// plays note d
    
  } else if (digitalRead(NOTE_E) == 1) {
    tone(PIEZO, E * octaveMultiplier, 250);	// plays note e
    
  } else if (digitalRead(NOTE_F) == 1) {
    tone(PIEZO, F * octaveMultiplier, 250);	// plays note f 

  } else if (digitalRead(NOTE_G) == 1) {
    tone(PIEZO, G * octaveMultiplier, 250);	// plays note g 

  } else if (digitalRead(NOTE_A) == 1) {
    tone(PIEZO, A * octaveMultiplier, 250);	// plays note a

  } else if (digitalRead(NOTE_B) == 1) {
    tone(PIEZO, B * octaveMultiplier, 250);	// plays note b
    
  } else if (digitalRead(HIGH_C) == 1) {
    tone(PIEZO, C_HIGH * octaveMultiplier, 250); // plays note c
    
  } else {
    noTone(PIEZO);
  }
  
  delay(10);
}
