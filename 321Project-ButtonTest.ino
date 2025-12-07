// === Button Test ===
const int BUTTON_PIN = 3;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // uses internal pull-up resistor
  Serial.println("Button Test Started...");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) { // pressed
    Serial.println("Button pressed!");
    delay(300); // debounce delay
  }
}
