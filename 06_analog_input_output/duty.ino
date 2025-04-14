const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int dutyCycle = 60;   // 0 ~ 100 %
  int period = 10;      // 10 ms -> 100Hz

  int onTime = period * dutyCycle / 100;
  int offTime = period - onTime;

  digitalWrite(ledPin, HIGH);
  delay(onTime);

  digitalWrite(ledPin, LOW);
  delay(offTime);
}