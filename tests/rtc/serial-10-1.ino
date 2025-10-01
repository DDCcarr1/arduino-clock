/*/
NOTICE
This code works, but was generated with Artificial Intelligence.
I do NOT condone AI for final works. I DO condone AI for learning purposes.
/*/

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;  // or RTC_DS1307 rtc; for DS1307

void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    // Set the time to compile time (adjust as needed)
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  // Print in 24-hour format: HH:MM:SS
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000);
}
