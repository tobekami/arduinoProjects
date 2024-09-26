#include <Servo.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 8;
const int ledPin = 7;
const int servoPin = 6;

// Variables to store distance and duration
long duration;
int distance;
int doorOpenThreshold = 50;  // Threshold distance to trigger the door opening (in cm)
int doorCloseDelay = 3000;   // Delay before closing the door (in ms)

Servo myServo;  // Create a Servo object

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach the servo to the servo pin
  myServo.attach(servoPin);

  // Start with the LED off and servo in the closed position
  digitalWrite(ledPin, LOW);
  myServo.write(0);  // Door closed (0 degrees)
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse duration from Echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than the threshold (object detected)
  if (distance < doorOpenThreshold) {
    // Turn on the LED to indicate motion detected
    digitalWrite(ledPin, HIGH);

    // Open the door (servo turns to 90 degrees)
    myServo.write(90);
    Serial.println("Door opened");

    // Wait for a while before closing the door
    delay(doorCloseDelay);

    // Close the door (servo turns back to 0 degrees)
    myServo.write(0);
    Serial.println("Door closed");
    
    // Turn off the LED after door closes
    digitalWrite(ledPin, LOW);
  }

  // Small delay before repeating the loop
  delay(500);
}
