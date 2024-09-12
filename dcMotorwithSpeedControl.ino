// Motor control pins
int motorIn1 = 9;
int motorIn2 = 8;
int motorSpeed = 10;  // ENA pin connected to pin 10 for PWM control

void setup() {
  // Set motor control pins as output
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorSpeed, OUTPUT);
}

void loop() {
  // Run the motor forward at full speed
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  analogWrite(motorSpeed, 255);  // Set speed to maximum
  delay(3000);                   // Run for 3 seconds

  // Stop the motor
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  delay(1000);                   // Pause for 1 second

  // Run the motor in reverse at half speed
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);
  analogWrite(motorSpeed, 128);  // Set speed to half
  delay(3000);                   // Run for 3 seconds

  // Stop the motor
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  delay(1000);                   // Pause for 1 second
}
