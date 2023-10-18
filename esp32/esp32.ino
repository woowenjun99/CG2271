#define RXD2 16
#define TXD2 17
#include <WebSocketsServer.h>
#include <WiFiMulti.h>
#include <WiFi.h>
#include <stdlib.h>

WebSocketsServer webSocket = WebSocketsServer(8080);
WiFiMulti WiFiMulti;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
      IPAddress ip = webSocket.remoteIP(num);
      Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      webSocket.sendTXT(num, "Connected");
      break;
    }
    case WStype_TEXT: {
      // Serial.printf("[%u] get Text: %s\n", num, payload);
      uint8_t num2 = strtol((char*) payload, NULL, 10); 
      Serial.println(num2);
      webSocket.sendTXT(num, payload);
      break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  WiFiMulti.addAP("macmini", "1234567890");
  Serial.println("Connecting");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  // Get the local IP address so that we can put in our flutter app
  Serial.println(WiFi.localIP());
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
}
