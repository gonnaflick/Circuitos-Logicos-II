#include "SevSeg.h"
#include <math.h>

int buttonPinA0 = 6;
int buttonPinA1 = 5;
int buttonPinA2 = 4;
int buttonPinA3 = 3;
int buttonPinB0 = 7;
int buttonPinB1 = 8;
int buttonPinB2 = 9;
int buttonPinB3 = 10;
int buttonPinC0 = 2;
  
SevSeg sevseg;

void setup() {
  pinMode(buttonPinA0, INPUT_PULLUP);
  pinMode(buttonPinA1, INPUT_PULLUP);
  pinMode(buttonPinA2, INPUT_PULLUP);
  pinMode(buttonPinA3, INPUT_PULLUP);
  pinMode(buttonPinB0, INPUT_PULLUP);
  pinMode(buttonPinB1, INPUT_PULLUP);
  pinMode(buttonPinB2, INPUT_PULLUP);
  pinMode(buttonPinB3, INPUT_PULLUP);

  byte numDigits = 4;  
  byte digitPins[] = {53, 51, 49, 47};
  byte segmentPins[] = {52, 50, 48, 46, 44, 42, 40};
  bool resistorsOnSegments = 0;
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  
  int decimal = 0, base = 1, remainder, num = 0, carry = 0;
  int eS0 = 0, eS1 = 0, eS2 = 0, eS3 = 0;
  
  int eA0 = digitalRead(buttonPinA0);
  int eA1 = digitalRead(buttonPinA1);
  int eA2 = digitalRead(buttonPinA2);
  int eA3 = digitalRead(buttonPinA3);
  
  int eB0 = digitalRead(buttonPinB0);
  int eB1 = digitalRead(buttonPinB1);
  int eB2 = digitalRead(buttonPinB2);
  int eB3 = digitalRead(buttonPinB3);
  int eC0 = digitalRead(buttonPinC0);
  
  eS0  = eA0 ^ eB0 ^ eC0;
  carry = ((eA0 ^ eB0) && eC0) | (eA0 & eB0);

  eS1  = eA1 ^ eB1 ^ carry;
  carry = ((eA1^ eB1) && carry) | (eA1 & eB1);

  eS2  = eA2 ^ eB2 ^ carry;
  carry = ((eA2 ^ eB2) && carry) | (eA2 & eB2);

  eS3  = eA3 ^ eB3 ^ carry;
  carry = ((eA3 ^ eB3) && carry) | (eA3 & eB3);

  num = concatenate(carry, eS3);
  num = concatenate(num, eS2);
  num = concatenate(num, eS1);
  num = concatenate(num, eS0);
  
  int temp = num;
  
 while(temp > 0) {
      remainder = temp % 10;
      decimal = decimal + remainder * base;
      temp = temp / 10;
      base = base * 2;
  }
 
  sevseg.setNumber(decimal, 3);
  sevseg.refreshDisplay();
}

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}
