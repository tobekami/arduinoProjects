// Pin definitions
const int trigPin = 9;
const int echoPin = 8;
const int ledPin = 7;
const int buzzerPin = 6;

// Variables to store distance and duration
long duration;
int distance;
int alarmThreshold = 50;  // Set threshold distance in cm

void setup() {
  // Initialize the serial monitor for debugging
  Serial.begin(9600);
  
  // Pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Start with LED and Buzzer off
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
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

  // Print distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than the threshold (object detected)
  if (distance < alarmThreshold) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    
    // Turn on the buzzer (sound alarm)
    digitalWrite(buzzerPin, HIGH);
    
    // Delay to allow alarm to stay on for 2 seconds
    delay(2000);  // Alarm duration
  } else {
    // Turn off LED and buzzer if no object detected within range
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Small delay before repeating the loop
  delay(500);
}
