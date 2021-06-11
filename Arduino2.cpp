#define NOTE_C_SHARP 3
#define NOTE_D_SHARP 4
#define NOTE_F_SHARP 5
#define NOTE_G_SHARP 6
#define NOTE_A_SHARP 7
#define PIEZO 2
#define POT 0

// frequencies of notes 
double C_SHARP = 0.0;
double D_SHARP = 0.0; 
double F_SHARP = 0.0;
double G_SHARP = 0.0;
double A_SHARP = 0.0;
double C_HIGH = 0.0;

int state;
double octaveMultiplier;

void setup()
{
  pinMode(NOTE_C_SHARP, INPUT);
  pinMode(NOTE_D_SHARP, INPUT); 
  pinMode(NOTE_F_SHARP, INPUT); 
  pinMode(NOTE_G_SHARP, INPUT); 
  pinMode(NOTE_A_SHARP, INPUT); 
  Serial.begin(9600); 
  
  C_SHARP = 69.30;
  D_SHARP = 73.42;
  F_SHARP = 92.50;
  G_SHARP = 103.83;
  A_SHARP = 116.54;
  
  state = 0;
  octaveMultiplier = 0.0;
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
  
  if (digitalRead(NOTE_C_SHARP) == 1) {
    tone(PIEZO, C_SHARP * octaveMultiplier, 250);	// plays note c#
    
  } else if (digitalRead(NOTE_D_SHARP) == 1) {
    tone(PIEZO, D_SHARP * octaveMultiplier, 250);	// plays note d#
    
  } else if (digitalRead(NOTE_F_SHARP) == 1) {
    tone(PIEZO, F_SHARP * octaveMultiplier, 250);	// plays note f#
    
  } else if (digitalRead(NOTE_G_SHARP) == 1) {
    tone(PIEZO, G_SHARP * octaveMultiplier, 250);	// plays note g#
    
  } else if (digitalRead(NOTE_A_SHARP) == 1) {
    tone(PIEZO, A_SHARP * octaveMultiplier, 250);	// plays note a#
    
  } else {
    noTone(PIEZO);
  }
  
  delay(10);
}
