#define PIEZO 8 

//header: define the frequencies/pitches used for this instrument
int notes[] = {262, 294, 330, 349};

// 383, 417, 451, 460

void setup(){
  Serial.begin(9600);
  pinMode(PIEZO, INPUT); 
}

void loop(){
  int keyVal = analogRead(A0);
  Serial.println(keyVal); 
  
  if (keyVal == 1023){ 
    tone(PIEZO, notes[0]); 
  } 
  else if (keyVal >= 990 && keyVal <=1010){ 
	tone(PIEZO, notes[1]); 
  } 
  else if (keyVal >= 505 && keyVal <= 515){ 
	tone(PIEZO, notes[2]); 
  } 
  else if (keyVal >= 5 && keyVal <=10){ 
    tone(PIEZO, notes[3]); 
  } 
  
  else {
    noTone(PIEZO);
  }
}

