// ==== Efficient Automated Light Switch (Logic + LED) ====

const int PIR_PIN = 2;
const int BUTTON_PIN = 3;
const int LED_PIN = 13;

unsigned long motionTimer = 0;
unsigned long lightDuration = 10000; // 10 seconds (use 1800000 for 30 min)
unsigned long overrideDelay = 5000;  // 5 seconds override disable time

bool lightState = false;
bool overrideActive = false;
bool lastButtonState = HIGH;

unsigned long overrideStart = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Automated Light Logic Initialized");
}
