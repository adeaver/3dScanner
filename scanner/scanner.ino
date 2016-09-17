#include <Servo.h> 
 
Servo pan;

int sensorPin = A0;
int servoPinPan = 9;

int pos = 0;

float sensorOutput;

void setup() {
  pinMode(sensorPin, INPUT);
  pan.attach(servoPinPan);
  Serial.begin(9600);
}

double calcDistance(float voltage) {
 return -13.582 * pow(voltage, 3) + 87.266 * pow(voltage, 2) - 201.117 * voltage + 192.102; 
}

void loop() {
  Serial.println("START");
  for(pos = 45; pos <= 135; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    pan.write(pos);              // tell servo to go to position in variable 'pos' 
    sensorOutput = (analogRead(sensorPin)/1023.0)*5.0;
    Serial.println(calcDistance(sensorOutput));
    delay(100);                       // waits 15ms for the servo to reach the position 
  } 
    for(pos = 135; pos >= 45; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    pan.write(pos);              // tell servo to go to position in variable 'pos' 
    sensorOutput = (analogRead(sensorPin)/1023.0)*5.0;
    Serial.println(calcDistance(sensorOutput));
    delay(100);                       // waits 15ms for the servo to reach the position 
  }
  Serial.println("END");
}
