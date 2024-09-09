#define SWITCH_PIN 2

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Enable internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN);
  if (switchState == LOW) {
    Serial.println("Switch Pressed");
  } else {
    Serial.println("Switch Released");
  }
  delay(500);
}
