void setup() {
  Serial.begin(9600);
  initEncoder();
  initMotor();
}

void loop() {
  if (Serial.available()) {
    int s = Serial.parseInt();
    if (s || Serial.peek() == '\n') setMotorSpeed(s);
  }
  updateMotorRPM();  // 1초마다 RPM 계산 및 출력
}