// Analog Pins
#define NOTE_C 13
#define NOTE_D 12
#define NOTE_E 11
#define NOTE_F 10
#define NOTE_G 9
#define NOTE_A 8
#define NOTE_B 7
#define HIGH_C 6

#define NOTE_C_SHARP A0
#define NOTE_D_SHARP A1
#define NOTE_F_SHARP A3
#define NOTE_G_SHARP A4
#define NOTE_A_SHARP A5

#define PIEZO 4

// frequencies of notes 
double C = 0.0;
double C_SHARP = 0.0;
double D = 0.0;
double D_SHARP = 0.0; 
double E = 0.0;
double F = 0.0;
double F_SHARP = 0.0;
double G = 0.0;
double G_SHARP = 0.0;
double A = 0.0;
double A_SHARP = 0.0;
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
  
  C = 261.63;
  C_SHARP = 277.18;
  D = 293.66;
  D_SHARP = 311.13;
  E = 329.63;
  F = 349.23;
  F_SHARP = 369.99;
  G = 392.00;
  G_SHARP = 415.30;
  A = 440.00;
  A_SHARP = 466.16;
  B = 493.88;
  C_HIGH = 523.25;
}

void loop()
{
  
  if (digitalRead(NOTE_C) == 1) {
    tone(PIEZO, C, 250);	// plays note c
    
  } else if (analogRead(NOTE_C_SHARP) == 1) {
    tone(PIEZO, C_SHARP, 250);	// plays note c#
    
  } else if (digitalRead(NOTE_D) == 1) {
    tone(PIEZO, D, 250);	// plays note d
    
  } else if (analogRead(NOTE_D_SHARP) == 1) {
    tone(PIEZO, D_SHARP, 250);	// plays note d#
    
  } else if (digitalRead(NOTE_E) == 1) {
    tone(PIEZO, E, 250);	// plays note e
    
  } else if (digitalRead(NOTE_F) == 1) {
    tone(PIEZO, F, 250);	// plays note f 
    
  } else if (analogRead(NOTE_F_SHARP) == 1) {
    tone(PIEZO, F_SHARP, 250);	// plays note f#
    
  } else if (digitalRead(NOTE_G) == 1) {
    tone(PIEZO, G, 250);	// plays note g 
    
  } else if (analogRead(NOTE_G_SHARP) == 1) {
    tone(PIEZO, G_SHARP, 250);	// plays note g#
    
  } else if (digitalRead(NOTE_A) == 1) {
    tone(PIEZO, A, 250);	// plays note a
    
  } else if (analogRead(NOTE_A_SHARP) == 1) {
    tone(PIEZO, A_SHARP, 250);	// plays note a#
    
  } else if (digitalRead(NOTE_B) == 1) {
    tone(PIEZO, B, 250);	// plays note b
    
  } else if (digitalRead(HIGH_C) == 1) {
    tone(PIEZO, C_HIGH, 250); // plays note c
    
  } else {
    noTone(PIEZO);
  }
  
  delay(10);
}
