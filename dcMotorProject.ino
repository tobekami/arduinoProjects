// Motor connected to pin 9
int motorPin = 9;

void setup() {
  // Set motor pin as output
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Turn the motor ON
  digitalWrite(motorPin, HIGH);
  delay(2000); // Motor runs for 2 seconds

  // Turn the motor OFF
  digitalWrite(motorPin, LOW);
  delay(2000); // Motor stops for 2 seconds
}
