void setup() {
  pinMode(8, OUTPUT); // Set pin 8 as output
}

void loop() {
  tone(8, 1000); // Generate a 1kHz tone
  delay(1000);   // Wait for 1 second
  noTone(8);     // Stop the tone
  delay(1000);   // Wait for 1 second
}
