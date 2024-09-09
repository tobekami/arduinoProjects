#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9); // Attach servo to pin 9
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos); // Set servo to position
    delay(15); // Wait for servo to reach position
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos); // Set servo to position
    delay(15); // Wait for servo to reach position
  }
}
