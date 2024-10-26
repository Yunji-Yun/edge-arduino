int Relaypin1 = 7;                 // IN1
int Relaypin2 = 6;                 // IN2
int Relaypin3 = 5;                 // IN3
int Relaypin4 = 4;                 // IN4

void setup()
{
pinMode(Relaypin1,OUTPUT);         // 릴레이 제어 1번핀을 출력으로 설정
pinMode(Relaypin2,OUTPUT);         // 릴레이 제어 2번핀을 출력으로 설정
pinMode(Relaypin3,OUTPUT);         // 릴레이 제어 3번핀을 출력으로 설정
pinMode(Relaypin4,OUTPUT);         // 릴레이 제어 4번핀을 출력으로 설정
}

void loop()
{
digitalWrite (Relaypin1, LOW); // 릴레이 ON
delay (1000);                  //1초 대기
digitalWrite (Relaypin1, HIGH); // 릴레이 OFF
delay (1000);

digitalWrite (Relaypin2, LOW); // 릴레이 ON
delay (1000);
digitalWrite (Relaypin2, HIGH); // 릴레이 OFF
delay (1000);

digitalWrite (Relaypin3, LOW); // 릴레이 ON
delay (1000);
digitalWrite (Relaypin3, HIGH); // 릴레이 OFF
delay (1000);

digitalWrite (Relaypin4, LOW); // 릴레이 ON
delay (1000);
digitalWrite (Relaypin4, HIGH); // 릴레이 OFF
delay (1000);
}