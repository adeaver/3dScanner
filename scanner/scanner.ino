int sensorPin = A0;

float sensorOutput;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

double calcDistance(float voltage) {
 return -13.582 * pow(voltage, 3) + 87.266 * pow(voltage, 2) - 201.117 * voltage + 192.102; 
}

void loop() {
  sensorOutput = (analogRead(sensorPin)/1023.0)*5.0;
  Serial.println(calcDistance(sensorOutput));
}
