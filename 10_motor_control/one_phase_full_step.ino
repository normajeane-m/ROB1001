int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void fullStepUnipolar(int step) {
  switch (step % 4) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
}

void loop() {
  for (int i = 0; i < 2048; i++) { // 1회전 = 2048스텝 (28BYJ-48 기준)
    fullStepUnipolar(i);
    delay(2); // 속도 조절 (작을수록 빠름)
  }

  delay(1000); // 잠시 대기

  for (int i = 2047; i >= 0; i--) { // 반대 방향 회전
    fullStepUnipolar(i);
    delay(2);
  }

  delay(1000);
}
