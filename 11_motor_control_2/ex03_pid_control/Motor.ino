#define MOTOR_PWM 6
#define MOTOR_DIR1 7
#define MOTOR_DIR2 8

long previousCount = 0;            // 이전 측정 시점의 펄스 수
float motorRPM = 0;                // 계산된 모터 RPM
unsigned long previousTime = 0;    // 이전 시간 (millis 기준)

// PID 계수
float Kp = 0.04;
float Ki = 0.0003;
float Kd = 0.1;

// PID 제어 변수
float err_p = 0;
float err_i = 0;
float err_d = 0;
float prevError = 0;
unsigned long lastPIDTime = 0;

// 목표값과 현재값
float target = 0;           // 목표 RPM
extern float current;       // 실제 측정된 RPM (Encoder에서 정의)

void initMotor() {
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_DIR1, OUTPUT);
  pinMode(MOTOR_DIR2, OUTPUT);
}

void setMotorSpeed(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    analogWrite(MOTOR_PWM, speed);
    digitalWrite(MOTOR_DIR1, HIGH);
    digitalWrite(MOTOR_DIR2, LOW);
  } else if (speed < 0) {
    analogWrite(MOTOR_PWM, -speed);
    digitalWrite(MOTOR_DIR1, LOW);
    digitalWrite(MOTOR_DIR2, HIGH);
  } else {
    analogWrite(MOTOR_PWM, 0);
    digitalWrite(MOTOR_DIR1, LOW);
    digitalWrite(MOTOR_DIR2, LOW);
  }
}

// RPM 계산 함수
void updateMotorRPM() {
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime >= 1000) { // 1초마다 측정
    long pulses = motorCount - previousCount;

    // RPM 계산: pulses / (PPR * 체배 * 감속비) * 60
    motorRPM = pulses * 60.0 / (11.0 * 2.0 * 46.0);

    previousCount = motorCount;
    previousTime = currentTime;

    Serial.print("현재 모터 속도 (RPM): ");
    Serial.println(motorRPM);
  }
}

void pidControl() {
  unsigned long now = millis();
  float dt = (now - lastPIDTime) / 1000.0;

  if (dt >= 0.05) {  // 50ms 주기
    err_p = target - current;
    err_i += err_p * dt;
    err_d = (err_p - prev_err) / dt;

    float output = Kp * err_p + Ki * err_i + Kd * err_d;

    output = constrain(output, -255, 255);
    if (output == 255 || output == -255) {
      err_i -= err_p * dt;
    }

    setMotorSpeed((int)output);

    prev_err = err_p;
    lastPIDTime = now;

    Serial.print("RPM: ");
    Serial.print(current);
    Serial.print(" / Target: ");
    Serial.println(target);
  }
}

float pControl() {
  unsigned long now = millis();
  float dt = (now - lastPIDTime) / 1000.0;

  if (dt >= 0.05) {  // 50ms 주기
    float err_p = target - current;
    float output = Kp * err_p;
    output = constrain(output, -255, 255);
    setMotorSpeed((int)output);
    lastPIDTime = now;
    Serial.print("RPM: ");
    Serial.print(current);
    Serial.print(" / Target: ");
    Serial.println(target);
  }
}

float pdControl() {
  unsigned long now = millis();
  float dt = (now - lastPIDTime) / 1000.0;

  if (dt >= 0.05) {  // 50ms 주기
    float err_p = target - current;
    float err_d = (err_p - prev_err) / dt;
    float output = Kp * err_p + Kd * err_d;
    output = constrain(output, -255, 255);
    setMotorSpeed((int)output);
    lastPIDTime = now;
    Serial.print("RPM: ");
    Serial.print(current);
    Serial.print(" / Target: ");
    Serial.println(target);
  } 
}