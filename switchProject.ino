#define SWITCH_PIN 2 // Define the pin number for the switch

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as input with an internal pull-up resistor
  Serial.begin(9600); // Start serial communication at a baud rate of 9600 for debugging
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN); // Read the state of the switch (HIGH or LOW)
  
  // Check if the switch is pressed (LOW because of the pull-up resistor)
  if (switchState == LOW) {
    Serial.println("Switch Pressed"); // Print message to the Serial Monitor when pressed
  } else {
    Serial.println("Switch Released"); // Print message when the switch is not pressed
  }
  
  delay(500); // Add a delay of 500ms between readings to prevent spamming the Serial Monitor
}
