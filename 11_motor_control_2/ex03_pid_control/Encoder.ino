#define ENC_CHA 3 // Ch A: Yellow
#define ENC_CHB 2 // Ch B: Green

volatile long motorCount = 0;

void countEncoder() {
  if (digitalRead(ENC_CHA) == HIGH) {
    if (digitalRead(ENC_CHB) == LOW) motorCount++;
    else motorCount--;
  } else {
    if (digitalRead(ENC_CHB) == HIGH) motorCount++;
    else motorCount--;
  }
}

void countEncoder_B() {
  if (digitalRead(interruptPinA) == LOW) {
    if (digitalRead(interruptPinB) == HIGH) motorCount--;
    else motorCount++;
  } else {
    if (digitalRead(interruptPinB) == HIGH) motorCount++;
    else motorCount--;
  }
}

void initEncoder() {
  pinMode(ENC_CHA, INPUT_PULLUP);
  pinMode(ENC_CHB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENC_CHA), countEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_CHB), countEncoder_B, CHANGE);
}