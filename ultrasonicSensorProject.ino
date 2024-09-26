// Define pins for the ultrasonic sensor
#define TRIG_PIN 9  // Trigger pin of the ultrasonic sensor
#define ECHO_PIN 10 // Echo pin of the ultrasonic sensor

void setup() {
  // Initialize pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance based on the speed of sound
  distance = (duration / 2) / 29.1; // Convert to centimeters
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait before next measurement
  delay(500);
}
