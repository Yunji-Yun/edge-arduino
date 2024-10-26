#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi 정보 설정
const char* ssid = "";
const char* password = "";
IPAddress local_IP( ); // ESP32가 사용할 IP address
IPAddress gateway( );    // Gateway IP address (공유기 IP주소)
IPAddress subnet( );   // subnet mask

// 릴레이 핀 설정
const int Relaypin1 = 16;
const int Relaypin2 = 17;
const int Relaypin3 = 18;
const int Relaypin4 = 19;



// 웹 서버 포트 설정
WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup...");

  // Wi-Fi 연결
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  // 핀 설정
  
  pinMode(Relaypin1, OUTPUT);
  pinMode(Relaypin2, OUTPUT);
  pinMode(Relaypin3, OUTPUT);
  pinMode(Relaypin4, OUTPUT);

  // 핀 초기 상태 설정 (릴레이가 OFF 상태로 시작)
  digitalWrite(Relaypin1, HIGH);
  digitalWrite(Relaypin2, HIGH);
  digitalWrite(Relaypin3, HIGH);
  digitalWrite(Relaypin4, HIGH);

  // HTTP 라우트 설정
  server.on("/power", HTTP_GET, handleRelayControl);
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}


void handleRelayControl() {
  if (!server.hasArg("power") || !server.hasArg("state")) {
    server.send(400, "text/plain", "Missing 'power' or 'state' parameter");
    return;
  }

  String power = server.arg("power");
  String state = server.arg("state");

  int pin;
  if (power == "1") pin = Relaypin1;
  else if (power == "2") pin = Relaypin2;
  else if (power == "3") pin = Relaypin3;
  else if (power == "4") pin = Relaypin4;
  else {
    server.send(400, "text/plain", "Invalid relay number");
    return;
  }

  if (state == "on") {
    digitalWrite(pin, LOW);  // 릴레이 ON
  } else if (state == "off") {
    digitalWrite(pin, HIGH);  // 릴레이 OFF
  } else {
    server.send(400, "text/plain", "Invalid state");
    return;
  }

  server.send(200, "text/plain", "success: power " + power + " is now " + state);

}
