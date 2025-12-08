// === Button Test ===
const int BUTTON_PIN = 3;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    Serial.println("Button pressed!");
    delay(300);
  }
}
