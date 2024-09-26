// Define the pins for the ultrasonic sensor
const int trigPin = 9;   // Trig pin of the ultrasonic sensor
const int echoPin = 10;  // Echo pin of the ultrasonic sensor

// Define the pin for the buzzer
const int buzzerPin = 8;

// Variables to store the measured distance and the duration of the echo
long duration;
int distance;

void setup() {
  // Initialize serial communication to monitor the distance in the Serial Monitor
  Serial.begin(9600);

  // Set trigPin as output to send the ultrasonic pulses
  pinMode(trigPin, OUTPUT);

  // Set echoPin as input to read the reflected pulses
  pinMode(echoPin, INPUT);

  // Set the buzzerPin as output to control the buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Send a 10us HIGH pulse to the trigPin to initiate a sensor reading
  digitalWrite(trigPin, LOW); // Ensure trigPin is low before starting
  delayMicroseconds(2);       // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Send a 10us HIGH pulse
  delayMicroseconds(10);       // Wait for 10 microseconds
  digitalWrite(trigPin, LOW);  // End the pulse

  // Measure the time taken by the ultrasonic pulse to bounce back
  duration = pulseIn(echoPin, HIGH); // pulseIn returns the duration in microseconds

  // Calculate the distance in centimeters
  // Speed of sound is ~343 m/s or 0.0343 cm/us, so the formula is (duration * 0.0343) / 2
  distance = duration * 0.0343 / 2;

  // Print the distance to the Serial Monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the distance is less than 20 cm, trigger the buzzer
  if (distance <= 20) {
    int delayTime = map(distance, 0, 20, 100, 1000); // Map distance to delay time (faster beep when closer)
    tone(buzzerPin, 1000);                           // Play a 1000 Hz tone on the buzzer
    delay(delayTime);                                // Wait based on the proximity
    noTone(buzzerPin);                               // Stop the tone after the delay
  } else {
    noTone(buzzerPin);                               // Ensure the buzzer is off if the distance is greater than 20 cm
  }

  // Add a short delay between each sensor reading to stabilize the values
  delay(200);
}
