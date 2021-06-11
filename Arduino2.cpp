#define NOTE_C_SHARP 3
#define NOTE_D_SHARP 4
#define NOTE_F_SHARP 5
#define NOTE_G_SHARP 6
#define NOTE_A_SHARP 7
#define PIEZO 2

// frequencies of notes 
double C_SHARP = 0.0;
double D_SHARP = 0.0; 
double F_SHARP = 0.0;
double G_SHARP = 0.0;
double A_SHARP = 0.0;
double C_HIGH = 0.0;


void setup()
{
  pinMode(NOTE_C_SHARP, INPUT);
  pinMode(NOTE_D_SHARP, INPUT); 
  pinMode(NOTE_F_SHARP, INPUT); 
  pinMode(NOTE_G_SHARP, INPUT); 
  pinMode(NOTE_A_SHARP, INPUT); 
  Serial.begin(9600); 
  
  C_SHARP = 277.18;
  D_SHARP = 311.13;
  F_SHARP = 369.99;
  G_SHARP = 415.30;
  A_SHARP = 466.16;
}

void loop()
{
  if (digitalRead(NOTE_C_SHARP) == 1) {
    tone(PIEZO, C_SHARP, 250);	// plays note c#
    
  } else if (digitalRead(NOTE_D_SHARP) == 1) {
    tone(PIEZO, D_SHARP, 250);	// plays note d#
    
  } else if (digitalRead(NOTE_F_SHARP) == 1) {
    tone(PIEZO, F_SHARP, 250);	// plays note f#
    
  } else if (digitalRead(NOTE_G_SHARP) == 1) {
    tone(PIEZO, G_SHARP, 250);	// plays note g#
    
  } else if (digitalRead(NOTE_A_SHARP) == 1) {
    tone(PIEZO, A_SHARP, 250);	// plays note a#
    
  } else {
    noTone(PIEZO);
  }
  
  delay(10);
}
