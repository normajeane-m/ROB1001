
volatile long motorCount = 0;

void setup() {
  Serial.begin(9600);
  initEncoder();  // 엔코더 핀 초기화 및 인터럽트 등록
}

void loop() {
  // 0.1초(100ms)마다 카운트 값 출력
  Serial.print("엔코더 카운트: ");
  Serial.println(motorCount);
  delay(100);
}