// 아두이노 6개 LED 점등실험
// LED에 연결된 디지털IO핀 설정
int Led1 = 1;
int Led2 = 2;
int Led3 = 3;
int Led4 = 4;
int Led5 = 5;
int Led6 = 6;

void setup()
{ 
  // 디지털 IO 핀 1~6을 출력 모드로 설정합니다.
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
}

void loop()
{   
  // 모든 LED를 켭니다.
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  
  // LED가 계속 켜지도록 무한 대기합니다.
  while (true) {
    // 무한 루프, 아무 것도 하지 않음
    // LED는 계속 켜져 있게 됩니다.
  }
}
