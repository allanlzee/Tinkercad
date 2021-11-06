#define CHANNEL_A_MOTOR1 2
#define CHANNEL_A_MOTOR2 4
#define TRANSISTOR_BASE_MOTOR1 3 
#define TRANSISTOR_BASE_MOTOR2 5 
#define HOLES_IN_ENCODER 1000
#define SECONDS_PER_MINUTE 60.0 

// Variables to store data used to calculate averages
float compensation_factor = 0.0; 
int tests = 0; 
float average = 0.0;

// Initial Speed of the Motors
float motor1_speed = 200.00; 
float motor2_speed = 200.00;

void setup()
{
  Serial.begin(19200); 
  
  pinMode(CHANNEL_A_MOTOR1, INPUT_PULLUP);
  pinMode(TRANSISTOR_BASE_MOTOR1, OUTPUT); 
  
  pinMode(CHANNEL_A_MOTOR2, INPUT_PULLUP); 
  pinMode(TRANSISTOR_BASE_MOTOR2, OUTPUT);
  
}

void loop()
{
  // Run the motors
  Serial.println(round(motor1_speed));
  Serial.println(round(motor2_speed));
  analogWrite(TRANSISTOR_BASE_MOTOR1, round(motor1_speed));
  analogWrite(TRANSISTOR_BASE_MOTOR2, round(motor2_speed));
  
  delay(2000);
  
  // Calculate motor frequency
  float motor1 = frequency(CHANNEL_A_MOTOR1) * SECONDS_PER_MINUTE / (2 * HOLES_IN_ENCODER);
  float motor2 = frequency(CHANNEL_A_MOTOR2) * SECONDS_PER_MINUTE / (2 * HOLES_IN_ENCODER);
  
  // Find compensation and apply to motor 2
  float compensate = 1.00; 
  
  compensate = motor2 / motor1; 
  
  compensation_factor += compensate;
  
  // Calculate the average compensation after adding current compensation
  tests++; 
  average = compensation_factor / tests; 
  
  // No idea why this line makes my program crash
  //Serial.println(compensate, 4);
  
  // Apply compensation to motor 2
  motor2_speed /= average; 
  
  // Print compensation statistics
  Serial.print("Average Compensation: "); 
  Serial.println(average, 4); 
  
  Serial.print("Ideal Compensation: "); 
  Serial.print(motor2);
  Serial.print(" / "); 
  Serial.print(motor1); 
  Serial.print(" = "); 
  Serial.println(compensate, 4); 
  
  // Prints the RPM of the Motor 
  Serial.print("MOTOR 1: "); 
  Serial.print(motor1, 2); 
  Serial.println(" RPM");
  Serial.print("MOTOR 2: "); 
  Serial.print(motor2, 2); 
  Serial.println(" RPM");
  
  Serial.println(); 
}

// Read the RPM for any motor by using a channel 
// @param channel: Arduino Pin for Channel A of respective motor

unsigned int frequency(int channel) {
  int value = 0; 
  int changes = 0; 
  unsigned long timeStart = millis(); 
  
  do {
    value = (value + 1) % 2; 
    	
    do {
    } while (digitalRead(channel) == value && millis() - timeStart < 1000);
    
    changes++; 
  } while (millis() - timeStart < 1000); 
  
  return changes;
}
