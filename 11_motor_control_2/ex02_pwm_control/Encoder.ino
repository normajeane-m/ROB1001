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

void initEncoder() {
  pinMode(M1_DIR1, OUTPUT);
  pinMode(M1_DIR2, OUTPUT);;
  attachInterrupt(digitalPinToInterrupt(ENC_CHA), countEncoder, CHANGE);
}