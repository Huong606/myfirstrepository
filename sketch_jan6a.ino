const int ledPin = 3;       // LED connected to digital pin D3
const int buttonPin = 2;    // Button connected to digital pin D2
int mode = 0;               // Current LED mode (0 to 3)
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Debounce logic
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      mode = (mode + 1) % 4; // Cycle through 0 to 3
    }
  }

  lastButtonState = reading;

  // LED behavior based on mode
  switch (mode) {
    case 0: // Steady ON
      digitalWrite(ledPin, HIGH);
      break;
    case 1: // Slow blink
      blinkLED(1000);
      break;
    case 2: // Medium blink
      blinkLED(500);
      break;
    case 3: // Fast blink
      blinkLED(200);
      break;
  }
}

void blinkLED(int interval) {
  static unsigned long previousMillis = 0;
  static bool ledState = false;

  if (millis() - previousMillis >= interval) {
    previousMillis = millis();
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }
}