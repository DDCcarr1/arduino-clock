#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Manual RTC set: edit these values, set SET_RTC true to apply on next upload
const bool SET_RTC = false; // set to true to adjust the RTC when sketch starts, then set back to false
const int RTC_YEAR  = 2025;
const int RTC_MONTH = 10;
const int RTC_DAY   = 21;
const int RTC_HOUR  = 14;
const int RTC_MIN   = 42;
const int RTC_SEC   = 30;

void print2d(uint8_t v) {
  if (v < 10) lcd.print('0');
  lcd.print(v);
}

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  // Initialize RTC first
  if (!rtc.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("RTC Error");
    while (1) delay(10); // halt - RTC not found
  }

  // Set RTC if it lost power (only set once when needed)
  if (rtc.lostPower()) {
    lcd.setCursor(0, 0);
    lcd.print("Setting RTC...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    delay(1000);
    lcd.clear();
  }
    if (SET_RTC) {
    DateTime dt(RTC_YEAR, RTC_MONTH, RTC_DAY, RTC_HOUR, RTC_MIN, RTC_SEC);
    rtc.adjust(dt);
    // Optional: show confirmation on serial/lcd
    // Serial.print("RTC set to: "); printDateTimeSerial(dt);
    // Wait a moment so you can see it on LCD/Serial
    delay(500);
  }
}

void loop() {
  DateTime now = rtc.now();

  // First line: YYYY.MM.DD
  lcd.setCursor(0, 0);
  lcd.print(now.year());
  lcd.print('.');
  print2d(now.month());
  lcd.print('.');
  print2d(now.day());
  // Clear remaining characters on the first line (if any)
  lcd.setCursor(10, 0); // we used up to column 9 normally, clear from 10
  lcd.print("      ");

  // Second line: hh.mm with leading zeros
  lcd.setCursor(0, 1);
  print2d(now.hour());
  lcd.print('.');
  print2d(now.minute());
  // Clear remaining characters on the second line
  lcd.setCursor(5, 1); // hh.mm is 5 chars long
  lcd.print("           ");

  delay(1000);
}
