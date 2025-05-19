#define MOTOR_PWM 6
#define MOTOR_DIR1 7
#define MOTOR_DIR2 8

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