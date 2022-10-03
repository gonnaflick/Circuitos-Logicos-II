int buttonPinA = 2;
int buttonPinB = 3;
int buttonPinC = 4;
int ledPinSUM = 9;
int ledPinCOUT = 10;

int A;
int B;
int C;

void setup() {
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);
  pinMode(buttonPinC, INPUT_PULLUP);
  pinMode(ledPinSUM, OUTPUT);
  pinMode(ledPinCOUT, OUTPUT);
}

void loop() {
  A = digitalRead(buttonPinA);
  B = digitalRead(buttonPinB);
  C = digitalRead(buttonPinC);

  
  if(A == 1 && B == 0 && C == 0 || A == 0 && B == 1 && C == 0 || A == 0 && B == 0 && C == 1){
      digitalWrite(ledPinCOUT, HIGH);
      digitalWrite(ledPinSUM, LOW);
  }
  else if(A == 0 && B == 0 && C == 0){
      digitalWrite(ledPinCOUT, LOW);
      digitalWrite(ledPinSUM, LOW);
  }
  else if(A == 1 && B == 1 && C == 1){
      digitalWrite(ledPinCOUT, HIGH);
      digitalWrite(ledPinSUM, HIGH);
  }else{
      digitalWrite(ledPinCOUT, LOW);
      digitalWrite(ledPinSUM, HIGH);
  }
}
