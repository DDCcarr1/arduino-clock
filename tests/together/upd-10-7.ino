#include <Wire.h> //wire library
#include "RTClib.h" //rtclib library from adafruit
//includes

RTC_DS3231 rtc;
//o

//jk// do you have one 220 ohm on each segment bus? (none needed for digit cathodes)

int t = 6; //top
int tr = 5; //top right
int tl = 3; //top left
int m = 4; //middle
int bl = 8; //bottom left
int b = 9; //bottom
int br = 7; //bottom right
//dp is on 5v, only for seg 2 - use 220 ohm
// end segements

//jk // "d1 - display" = an LED digit confused me with "digit1" = a value to display

int d1 = 13; //display 1 //jk// usually called digits
int d2 = 12; //display 2
int d3 = 11; //display 3
int d4 = 10; //display 4
//end displays

int digit1 = 0; //jk// these are the values to show on each digit. I would name so indicative of value, like H10, H1, M10, M1
int digit2 = 0;
int digit3 = 0;
int digit4 = 0;
//variables

void setup() {
	Serial.begin(9600);
	if (!rtc.begin()) {
		Serial.println("Couldn't find RTC");
		while (1);
	} //if (!rtc.begin())

	if (rtc.lostPower()) {
		Serial.println("RTC lost power, setting the time!");
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
	} //if (rtc.lostPower())

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
} //void setup()

void loop() {
	//jk// I would allow time between reading the RTC delay(300);
	DateTime time = rtc.now();
	digit1 = time.hour() / 10;
	digit2 = time.hour() % 10;
	digit3 = time.minute() / 10;
	digit4 = time.minute() % 10;

  for(int i = 0; i >= 99; i++){
    disp(1, digit1);
    disp(2, digit2);
    disp(3, digit3);
    disp(4, digit4);
  }

} //void loop()

void clear() {
	digitalWrite(t, LOW);
	digitalWrite(tr, LOW);
	digitalWrite(tl, LOW);
	digitalWrite(m, LOW);
	digitalWrite(b, LOW);
	digitalWrite(br, LOW);
	digitalWrite(bl, LOW);
} //void clear()

void zero() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tl, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
	digitalWrite(bl, HIGH);
} //void zero()

void one() {
	clear();
	digitalWrite(tr, HIGH);
	digitalWrite(br, HIGH);
} //void one()

void two() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(bl, HIGH);
} //void two()

void three() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
} //void three()

void four() {
	clear();
	digitalWrite(tl, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(br, HIGH);
} //void four()

void five() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tl, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
} //void five()

void six() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tl, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
	digitalWrite(bl, HIGH);
} //void six()

void seven() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(br, HIGH);
} //void seven()

void eight() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tl, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
	digitalWrite(bl, HIGH);
} //void eight()

void nine() {
	clear();
	digitalWrite(t, HIGH);
	digitalWrite(tl, HIGH);
	digitalWrite(tr, HIGH);
	digitalWrite(m, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(br, HIGH);
} //void nine()

void m1() {
	digitalWrite(d1, LOW);
	digitalWrite(d2, HIGH);
	digitalWrite(d3, HIGH);
	digitalWrite(d4, HIGH);
} //void m1()

void m2() {
	digitalWrite(d1, HIGH);
	digitalWrite(d2, LOW);
	digitalWrite(d3, HIGH);
	digitalWrite(d4, HIGH);
} //void m2()

void m3() {
	digitalWrite(d1, HIGH);
	digitalWrite(d2, HIGH);
	digitalWrite(d3, LOW);
	digitalWrite(d4, HIGH);
} //void m3()

void m4() {
	digitalWrite(d1, HIGH);
	digitalWrite(d2, HIGH);
	digitalWrite(d3, HIGH);
	digitalWrite(d4, LOW);
} //void m4()

void disp(int display, int num) {
	switch(display) {
		case 1:
			m1(); break;
		case 2:
			m2(); break;
		case 3:
			m3(); break;
		case 4:
			m4(); break;
	} //switch(display)

	switch(num) {
		case 0:
			zero(); break;
		case 1:
			one(); break;
		case 2:
			two(); break;
		case 3:
			three(); break;
		case 4:
			four(); break;
		case 5:
			five(); break;
		case 6:
			six(); break;
		case 7:
			seven(); break;
		case 8:
			eight(); break;
		case 9:
			nine(); break;
	} //switch(num)

	delay(3); //jk// I'd go with 5ms/digit
} //void disp()
