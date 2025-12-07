const int SENSOR_PIN = 2;
const int BUTTON_PIN = 3;
const int LED_PIN = 13;

unsigned long motionTimer = 0;
unsigned long lightDuration = 10000; // 10 seconds for demo but usually 30 mins
unsigned long overrideDelay = 5000;  // 5 seconds for demo but usally 1 min

bool lightState = false;
bool overrideActive = false;
bool lastButtonState = HIGH;

unsigned long overrideTime = 0;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Automated Light Logic Initialized");
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);
  int buttonState = digitalRead(BUTTON_PIN);

  
  if (buttonState == LOW && lastButtonState == HIGH) {
    overrideActive = true;
    overrideTime = millis();
    lightState = !lightState;
  if (lightState) {
      Serial.println("Manual ON");
    } else {
      Serial.println("Manual OFF");
    }
  } 
  lastButtonState = buttonState;

  if (overrideActive && (millis() - overrideTime > overrideDelay)) {
    overrideActive = false;
    Serial.println("Override ended, motion sensor reactivated");
  }

  if (!overrideActive) {
    if (motionDetected == HIGH) {
      lightState = true;
      motionTimer = millis();
      Serial.println("Motion detected, light ON");
    } 
    else if (lightState && (millis() - motionTimer > lightDuration)) {
      lightState = false;
      Serial.println("No motion, light OFF");
    }
  }

  if (lightState == true) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
