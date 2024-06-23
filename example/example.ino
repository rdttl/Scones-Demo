int ledPins[] = {2, 3, 4, 5, 6, 7, 8};  // Don't change these (or do, I'm not your Mum)
int slowDelayLED = 450;                 // You can change delay times tho :)
int delayLED = 150;
int fastDelayLED = 70;

// Main functions ////////////////////////////////////////////////////////////
// This is run once on startup. Useful to initialise LEDs to output, etc
void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

// This is called directly after setup().
void loop() {
  // printChar('a');
  // fadeInOut();
  // blankLEDs();
  // allLEDs();
}

// Helper functions //////////////////////////////////////////////////////////
// Given a char, it flashes the ascii representation on the LEDs
// You can reverse the order if you want ;)
// To reverse, change to "for (int i = 6; i >= 0; i--) {...}"
void printChar(char entry) {
  for (int i = 0; i < 7; i++) {
    if (entry & 1) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
    entry = entry >> 1;
  }
}

// Fairly easy to understand ;)
void blankLEDs() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
void allLEDs() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

// Fades the LEDs out in an infinite loop. Just flashes the LEDs really quickly
// to create an optical illusion of dimming
void fadeInOut() {
  while (1) {
    blankLEDs();
    delay(400);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 25; j++) {
        allLEDs();
        delay(i);
        blankLEDs();
        delay(4);
      }
    }
    for (int i = 10; i >= 0 ; i--) {
      for (int j = 0; j < 25; j++) {
        allLEDs();
        delay(i);
        blankLEDs();
        delay(4);
      }
    }
  }
}

