volatile long motorCount = 0;
long previousCount = 0;            // 이전 측정 시점의 펄스 수
unsigned long previousTime = 0;    // 이전 시간 (millis 기준)

// PID 계수
float Kp = 8.0;        // P Gain 수정
float Ki = 1.0;      // I Gain 수정
float Kd = 0;         // D Gain 수정

// PID 제어 변수
float err_p = 0;
float err_i = 0;
float err_d = 0;
float prev_err = 0;
unsigned long lastPIDTime = 0;

// 목표값과 현재값
float target = 0;           // 목표 RPM
float current;              // 실제 측정된 RPM

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
  updateMotorRPM();     // 1초마다 RPM 계산 및 출력
  pidControl();         // PID 제어 수행 (target과 current는 전역변수)
}