#define SWITCH_PIN 2  // Button connected to pin 2
#define LED_PIN 9     // LED connected to pin 9

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);           // Set LED pin as output
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN);  // Read the state of the button

  if (switchState == LOW) {  // Button is pressed (LOW because of INPUT_PULLUP)
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn off the LED
  }
}
