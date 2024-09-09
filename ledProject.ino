void setup() {
  pinMode(13, OUTPUT); // Set pin 13 as output
}

void loop() {
  digitalWrite(13, HIGH); // Turn LED on
  delay(1000);            // Wait for 1 second
  digitalWrite(13, LOW);  // Turn LED off
  delay(1000);            // Wait for 1 second
}
