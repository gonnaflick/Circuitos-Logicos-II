int buttonPinA = 2;
int buttonPinB = 3;
int buttonPinC = 4;
int buttonPinD = 5;
int segmentA = 46;
int segmentB = 48;
int segmentC = 51;
int segmentD = 49;
int segmentE = 53;
int segmentF = 50;
int segmentG = 52;

int A;
int B;
int C;
int D;

void bcd(int dec_value)  
{
  switch(dec_value)
  {
    case 0:  
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, HIGH); 
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW); 
    break;
    case 1:  
      digitalWrite(segmentA, LOW);  
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);  
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
    break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
    break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
    break;
    case 4:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
    break;
    case 5:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
    break;
    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
    break;
    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
    break;
    case 8:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
    break;
    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
    break;
    default:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
    break;
  }
}

void setup() {
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);
  pinMode(buttonPinC, INPUT_PULLUP);
  pinMode(buttonPinD, INPUT_PULLUP);
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void loop() {
  A = digitalRead(buttonPinA);
  B = digitalRead(buttonPinB);
  C = digitalRead(buttonPinC);
  D = digitalRead(buttonPinD);
  
  if(A == 0 && B == 0 && C == 0 && D == 0)
    bcd(0);
  else if(A == 0 && B == 0 && C == 0 && D == 1)
    bcd(1);
  else if(A == 0 && B == 0 && C == 1 && D == 0)
    bcd(2);
  else if(A == 0 && B == 0 && C == 1 && D == 1)
    bcd(3);
  else if(A == 0 && B == 1 && C == 0 && D == 0)
    bcd(4);
  else if(A == 0 && B == 1 && C == 0 && D == 1)
    bcd(5);
  else if(A == 0 && B == 1 && C == 1 && D == 0)
    bcd(6);
  else if(A == 0 && B == 1 && C == 1 && D == 1)
    bcd(7);
  else if(A == 1 && B == 0 && C == 0 && D == 0)
    bcd(8);
  else if(A == 1 && B == 0 && C == 0 && D == 1)
    bcd(9);
  else
    bcd(10);
}
