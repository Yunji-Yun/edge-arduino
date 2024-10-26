#include <dummy.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4
#define CDS_PIN 23
#define DHTTYPE DHT11

const char* ssid = "";           // WiFi SSID
const char* password = "";   // WiFi 비밀번호
const char* serverUrl = "";  // 서버 URL

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    int lightLevel = analogRead(CDS_PIN);
    float brightness = (float)lightLevel / 1023.0 * 100.0;

    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    String postData = "temperature=" + String(t) + "&humidity=" + String(h) + "&brightness=" + String(brightness);

    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(10000); // 10초마다 데이터 전송
}
