bool PRESSED = LOW;
bool cur_state = !PRESSED;
bool pre_state;
int but_cnt = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  cur_state = digitalRead(3);
  if (cur_state == PRESSED){  // 버튼이 클릭 되면 실행
    if (pre_state != PRESSED) // 이전 버튼이 클릭이 안되어있으면 실행
    {
      digitalWrite(13, HIGH);
      pre_state = PRESSED;
      but_cnt++;
    }

  }
  else{
    pre_state = !PRESSED;
    digitalWrite(13, LOW);
  }
  Serial.println(but_cnt);
}
