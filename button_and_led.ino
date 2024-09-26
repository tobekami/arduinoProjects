int ledPin = 9;     // LED connected to digital pin 9
int buttonPin = 7;  // Button connected to digital pin 7
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);     // Set the LED pin as output
  pinMode(buttonPin, INPUT);    // Set the button pin as input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button
  
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }
}
