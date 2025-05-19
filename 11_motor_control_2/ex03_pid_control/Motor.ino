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
  unsigned long now = millis();
  float dt = (now - previousTime) / 1000.0;

  if (dt >= 0.01) {  // 10ms 주기
    long pulses = motorCount - previousCount;
    // RPM 계산: pulses / (PPR * 체배 * 감속비) * 60
    current = pulses / (11.0 * 4.0 * 46.0) * 60 / dt;
    previousCount = motorCount;
    previousTime = now;
  }
}

// Velocity control (PID)
void pidControl() {
  unsigned long now = millis();
  float dt = (now - lastPIDTime) / 1000.0;

  if (dt >= 0.01) {  // 10ms 주기
    err_p = target - current;
    err_i += err_p;
    err_d = (err_p - prev_err) / dt;

    err_i = constrain(err_i, -50.0f, 50.0f);
    float output = Kp * err_p + Ki * err_i + Kd * err_d;
    
    Serial.print("Target:");
    Serial.print((int)target);
    Serial.print(",");
    Serial.print("Current:");
    Serial.print((int)current);
    Serial.print(",");
    Serial.print("Output:");
    Serial.println((int)output);

    setMotorSpeed((int)output);

    prev_err = err_p;
    lastPIDTime = now;
  }
}