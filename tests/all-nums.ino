int t = 6;  //top
int tr = 5; //top right
int tl = 3; //top left
int m = 4;  //middle
int bl = 8; //bottom left
int b = 9;  //bottom
int br = 7; //bottom right
  //dp is on 5v, only for seg 2
//variables

void setup() {
  pinMode(t, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(tl, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(br, OUTPUT);
  pinMode(bl, OUTPUT);
}

void loop() {
  zero();
  delay(1000);
  one();
  delay(1000);
  two();
  delay(1000);
  three();
  delay(1000);
  four();
  delay(1000);
  five();
  delay(1000);
  six();
  delay(1000);
  seven();
  delay(1000);
  eight();
  delay(1000);
  nine();
  delay(1000);
}

void clear()  {
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
