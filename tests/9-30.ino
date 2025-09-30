int t = 6;  //top
int tr = 5; //top right
int tl = 3; //top left
int m = 4;  //middle
int bl = 8; //bottom left
int b = 9;  //bottom
int br = 7; //bottom right
  //dp is on 5v, only for seg 2
//segements
int d1 = 13;  //display 1
int d2 = 12;  //display 2
int d3 = 11;  //display 3
int d4 = 10;  //display 4
//displays
//variables

void setup() {
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
  for(int i = 0; i<100; i++){
    m1();
    one();
    delay(1);
    m2();
    two();
    delay(1);
    m3();
    three();
    delay(1);
    m4();
    four();
    delay(1);
  }
  for(int ii = 0; ii<100; ii++){
    m2();
    one();
    delay(1);
    m3();
    two();
    delay(1);
    m4();
    three();
    delay(1);
    m1();
    four();
    delay(1);
  }
  for(int iii = 0; iii<100; iii++){
    m3();
    one();
    delay(1);
    m4();
    two();
    delay(1);
    m1();
    three();
    delay(1);
    m2();
    four();
    delay(1);
  }
  for(int iiii = 0; iiii<100; iiii++){
    m4();
    one();
    delay(1);
    m1();
    two();
    delay(1);
    m2();
    three();
    delay(1);
    m3();
    four();
    delay(1);
  }
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



void m1(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
}

void m2(){
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
}

void m3(){
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
}

void m4(){
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
}
