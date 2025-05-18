void setup() {
  Serial.begin(9600);
  initEncoder();
  initMotor();
}

void loop() {
  if (Serial.available()) {
    int s = Serial.parseInt();
    if (s || Serial.peek() == '\n') target = s;  // target은 전역변수
  }

  pidControl();         // PID 제어 수행 (target과 current는 전역변수)
  updateMotorRPM();     // 1초마다 RPM 계산 및 출력
}