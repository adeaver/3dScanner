#include <Servo.h> 
 
Servo pan;
Servo tilt;

int sensorPin = A0;
int servoPinPan = 9;
int servoPinTilt = 10;

// Position variables
int h_pos = 0;
int v_pos = 0;

// min-max value for the angles
int min_h = 65;
int max_h = 115;

int min_v = 10;
int max_v = 30;

float sensorOutput;

void setup() {
  pinMode(sensorPin, INPUT);
  pan.attach(servoPinPan);
  tilt.attach(servoPinTilt);
  Serial.begin(9600);
}

// calculates the distance given a voltage
double calcDistance(float voltage) {
 return -13.582 * pow(voltage, 3) + 87.266 * pow(voltage, 2) - 201.117 * voltage + 192.102; 
}

// scans a line
void scanLine() {
  // Print Token to Begin Collecting line data
  Serial.println("START_LINE");
  for(h_pos = min_h; h_pos <= max_h; h_pos += 1) {
    
    // Write panning servo to a given position    
    pan.write(h_pos);
    
    // This should STOP the arduino to allow the servo to catch up
    // Debouncing would allow the loop to continue    
    delay(100);
        
    // Read the sensor value when the servo is at a given position
    sensorOutput = (analogRead(sensorPin)/1023.0)*5.0;
    Serial.println(calcDistance(sensorOutput)); 
  }
  // Print token to End collecting line data 
  Serial.println("END_LINE");  
}

void loop() {
  // Started Scanning Token
  Serial.println("BEGIN_SCAN");

  // Move tilt servo
  for(v_pos = max_v; v_pos >= min_v; v_pos -= 5) {
    tilt.write(v_pos);
    scanLine(); 
  }
  
  // Done Scanning Token
  Serial.println("END_SCAN");  
}
