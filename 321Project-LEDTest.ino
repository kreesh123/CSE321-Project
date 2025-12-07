// === LED Test ===
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED Test Started...");
}

void loop() {
  Serial.println("Light ON");
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  Serial.println("Light OFF");
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
