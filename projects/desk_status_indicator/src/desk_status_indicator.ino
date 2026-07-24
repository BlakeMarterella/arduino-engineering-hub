// include the library
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int BUTTON1_PIN    = 7;
const int BUTTON2_PIN    = 6;
const int LED_PIN        = 8;
const int TRIG_PIN       = 9;
const int ECHO_PIN       = 10;

const int FLASH_INTERVAL = 500;  // ms between LED toggles when flashing
const int DIST_INTERVAL  = 250;  // ms between distance reads

enum State { OFF, ON_CALL, LOCKED_IN };
State currentState = OFF;

bool lastButton1 = HIGH;
bool lastButton2 = HIGH;

unsigned long lastFlashTime = 0;
unsigned long lastDistTime  = 0;
bool ledOn = false;

float lastValidInches = -1;
int   missCnt         = 0;
const int MAX_MISSES  = 5; // show "-----" only after this many consecutive misses

void showOff() {
  lcd.clear();
  digitalWrite(LED_PIN, LOW);
  ledOn = false;
}

void showOnCall() {
  lcd.clear();
  lcd.print(" In a Meeting   ");
  lcd.setCursor(0, 1);
  lcd.print("Dist: reading...");
  digitalWrite(LED_PIN, HIGH);
  ledOn = true;
}

void showLockedIn() {
  lcd.clear();
  lcd.print("  Locked In     ");
  digitalWrite(LED_PIN, LOW);
  ledOn = false;
  lastFlashTime = millis();
}

float readDistanceInches() {
  // Send 10µs trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure how long the echo pin stays HIGH (timeout after 38ms covers full 400cm range)
  long duration = pulseIn(ECHO_PIN, HIGH, 38000);

  // duration / 148 converts microseconds to inches (speed of sound)
  return duration / 148.0;
}

void updateDistance() {
  float inches = readDistanceInches();

  lcd.setCursor(0, 1);
  if (inches >= 0.8 && inches <= 157) {
    lastValidInches = inches;
    missCnt = 0;
    lcd.print("Dist: ");
    lcd.print(inches, 1);
    lcd.print(" in      "); // trailing spaces clear stale characters
  } else {
    missCnt++;
    if (missCnt < MAX_MISSES && lastValidInches > 0) {
      // Hold last good reading while glitching — avoids flicker
      lcd.print("Dist: ");
      lcd.print(lastValidInches, 1);
      lcd.print(" in      ");
    } else {
      lcd.print("Dist: -----      ");
    }
  }
}

void setup() {
  lcd.begin(16, 2);

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  showOff();
}

void loop() {
  bool b1 = digitalRead(BUTTON1_PIN);
  bool b2 = digitalRead(BUTTON2_PIN);

  // Button 1 — On a Call
  if (b1 == LOW && lastButton1 == HIGH) {
    delay(50); // debounce
    if (currentState == ON_CALL) {
      currentState = OFF;
      showOff();
    } else {
      currentState = ON_CALL;
      showOnCall();
      lastDistTime = millis();
    }
  }

  // Button 2 — Locked In
  if (b2 == LOW && lastButton2 == HIGH) {
    delay(50); // debounce
    if (currentState == LOCKED_IN) {
      currentState = OFF;
      showOff();
    } else {
      currentState = LOCKED_IN;
      showLockedIn();
    }
  }

  // Flash LED when Locked In
  if (currentState == LOCKED_IN) {
    unsigned long now = millis();
    if (now - lastFlashTime >= FLASH_INTERVAL) {
      ledOn = !ledOn;
      digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
      lastFlashTime = now;
    }
  }

  // Update distance on second line when On a Call
  if (currentState == ON_CALL) {
    unsigned long now = millis();
    if (now - lastDistTime >= DIST_INTERVAL) {
      updateDistance();
      lastDistTime = now;
    }
  }

  lastButton1 = b1;
  lastButton2 = b2;
}
