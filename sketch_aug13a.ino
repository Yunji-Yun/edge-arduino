const int analogInPin = A0;  // ACS712 OUT 핀 연결
int sensorValue = 0;         // 센서 값을 저장할 변수
float voltage = 0;           // 전압 변수
float current = 0;           // 전류 변수
const int numReadings = 10;  // 측정 횟수

void setup() {
  Serial.begin(9600);        // 시리얼 통신 시작
}

void loop() {
  float total = 0;

  // 여러 번 측정하여 평균값을 계산
  for (int i = 0; i < numReadings; i++) {
    sensorValue = analogRead(analogInPin);
    total += sensorValue;
    delay(10);  // 작은 지연 추가
  }

  sensorValue = total / numReadings;
  voltage = sensorValue * (5.0 / 1023.0); // 전압으로 변환
  current = (voltage - 2.5) / 0.185;      // 전류 계산 (5A 센서의 감도: 185mV/A)

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  delay(1000);  // 1초마다 측정
}
