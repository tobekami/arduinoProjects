#define MOTOR_PIN1 5
#define MOTOR_PIN2 6

void setup() {
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
}

void loop() {
  analogWrite(MOTOR_PIN1, 255); // Full speed forward
  analogWrite(MOTOR_PIN2, 0);
  delay(2000); // Run motor forward for 2 seconds

  analogWrite(MOTOR_PIN1, 0); // Stop motor
  analogWrite(MOTOR_PIN2, 0);
  delay(1000);

  analogWrite(MOTOR_PIN1, 0); // Full speed backward
  analogWrite(MOTOR_PIN2, 255);
  delay(2000); // Run motor backward for 2 seconds

  analogWrite(MOTOR_PIN1, 0); // Stop motor
  analogWrite(MOTOR_PIN2, 0);
  delay(1000);
}
