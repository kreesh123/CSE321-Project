// === PIR Sensor Test ===
const int SENSOR_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  int motion = digitalRead(SENSOR_PIN);

  if (motion == HIGH) {
    Serial.println("Motion detected!");
  } else {
    Serial.println("No motion...");
  }

  delay(1000); // check every 1 second
}
