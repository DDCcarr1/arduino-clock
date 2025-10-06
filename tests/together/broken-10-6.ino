#include <Wire.h>            // wire library
#include "RTClib.h"          // rtclib library from Adafruit

RTC_DS3231 rtc;

// Segment pins
int t  = 6;  // top
int tr = 5;  // top right
int tl = 3;  // top left
int m  = 4;  // middle
int bl = 8;  // bottom left
int b  = 9;  // bottom
int br = 7;  // bottom right
// dp is on 5V, only for seg 2 - use 220 ohm

// Digit select pins (common cathode or anode)
int d1 = 13; // display 1
int d2 = 12; // display 2
int d3 = 11; // display 3
int d4 = 10; // display 4

// Values to display on each digit
int digit1 = 0;
int digit2 = 0;
int digit3 = 0;
int digit4 = 0;

void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(t, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(tl, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(br, OUTPUT);
  pinMode(bl, OUTPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
}

void loop() {
  // It's a good idea to not read the RTC too often; consider delay(300);
  DateTime time = rtc.now();
  digit1 = time.hour() / 10;
  digit2 = time.hour() % 10;
  digit3 = time.minute() / 10;
  digit4 = time.minute() % 10;

  // Rapidly cycle through all digits for proper multiplexing
  for (int i = 0; i < 50; i++) {
    disp(1, digit1);
    disp(2, digit2);
    disp(3, digit3);
    disp(4, digit4);
  }
}

void clear() {
  digitalWrite(t, LOW);
  digitalWrite(tr, LOW);
  digitalWrite(tl, LOW);
  digitalWrite(m, LOW);
  digitalWrite(b, LOW);
  digitalWrite(br, LOW);
  digitalWrite(bl, LOW);
}

void zero() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tl, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
  digitalWrite(bl, HIGH);
}

void one() {
  clear();
  digitalWrite(tr, HIGH);
  digitalWrite(br, HIGH);
}

void two() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(bl, HIGH);
}

void three() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
}

void four() {
  clear();
  digitalWrite(tl, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(br, HIGH);
}

void five() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tl, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
}

void six() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tl, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
  digitalWrite(bl, HIGH);
}

void seven() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(br, HIGH);
}

void eight() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tl, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
  digitalWrite(bl, HIGH);
}

void nine() {
  clear();
  digitalWrite(t, HIGH);
  digitalWrite(tl, HIGH);
  digitalWrite(tr, HIGH);
  digitalWrite(m, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(br, HIGH);
}

// Digit select functions
void m1() {
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
}

void m2() {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
}

void m3() {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
}

void m4() {
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
}

// Display the digit
void disp(int display, int num) {
  switch (display) {
    case 1: m1(); break;
    case 2: m2(); break;
    case 3: m3(); break;
    case 4: m4(); break;
  }
  switch (num) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
  delay(5); // 5ms/digit for visible persistence
}
