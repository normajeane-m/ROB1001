
volatile long motorCount = 0;
long previousCount = 0;            // 이전 측정 시점의 펄스 수
float motorRPM = 0;                // 계산된 모터 RPM
unsigned long previousTime = 0;    // 이전 시간 (millis 기준)

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