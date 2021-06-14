int cNote = 9;
int dNote = 8;
int eNote = 7;
int fNote = 6;
int gNote = 5;
int aNote = 4;
int bNote = 3;
int Piezo = 2;

double c = 261.63;// the frequency of note c
double d = 293.66;// the frequency of note d
double e = 329.63;// the frequency of note e
double f = 349.23;// the frequency of note f
double g = 392;// the frequency of note g
double a = 440;// the frequency of note a
double b = 493.88;// the frequency of note b

void setup()
{
  pinMode(cNote, INPUT);
  pinMode(dNote, INPUT);
  pinMode(eNote, INPUT);
  pinMode(fNote, INPUT);
  pinMode(gNote, INPUT);
  pinMode(aNote, INPUT);
  pinMode(bNote, INPUT);
  pinMode(Piezo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(cNote));
  Serial.println(digitalRead(dNote));
  Serial.println(digitalRead(eNote));
  Serial.println(digitalRead(fNote));
  Serial.println(digitalRead(gNote));
  Serial.println(digitalRead(aNote));
  Serial.println(digitalRead(bNote));
  
  if (digitalRead(cNote) == 1) {
    tone(Piezo, c, 250);	// plays note c
  } else if (digitalRead(dNote) == 1) {
    tone(Piezo, d, 250);	// plays note d
  } else if (digitalRead(eNote) == 1) {
    tone(Piezo, e, 250);	// plays note e 
  } else if (digitalRead(fNote) == 1) {
    tone(Piezo, f, 250);	// plays note f 
  } else if (digitalRead(gNote) == 1) {
    tone(Piezo, g, 250);	// plays note g 
  } else if (digitalRead(aNote) == 1) {
    tone(Piezo, a, 250);	// plays note a 
  } else if (digitalRead(bNote) == 1) {
    tone(Piezo, b, 250);	// plays note b
  } else {
    noTone(Piezo);
  }
  delay(10);
}
