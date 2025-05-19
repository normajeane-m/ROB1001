#define ENC_CHA 3 // Ch A: Yellow
#define ENC_CHB 2 // Ch B: Green

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
  if (digitalRead(ENC_CHA) == LOW) {
    if (digitalRead(ENC_CHB) == HIGH) motorCount--;
    else motorCount++;
  } else {
    if (digitalRead(ENC_CHB) == HIGH) motorCount++;
    else motorCount--;
  }
}

void initEncoder() {
  pinMode(ENC_CHA, INPUT);
  pinMode(ENC_CHB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_CHA), countEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_CHB), countEncoder_B, CHANGE);
}