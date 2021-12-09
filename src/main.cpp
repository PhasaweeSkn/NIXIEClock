#include <Arduino.h>
#include <WiFi.h>

char *wifi_pass = "ABCDEFGH";
char *wifi_ap_ssid = "HELLO_ESP32";
char *wifi_ap_pass = "123456";


void setup() {

  // TODO: INIT PERIPHERAL

  // TODO: LOAD PARM from internal memory

  
  Serial.begin(115200);

  WiFi.mode(WIFI_MODE_APSTA);

  WiFi.disconnect();
  delay(100);

  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  Serial.setTimeout(10000);
  Serial.println("Choose SSID:");
  String ssid = Serial.readString();
  uint16_t index_ssid = ssid.toInt();
  Serial.println("Press Password:");
  String pass = Serial.readString();

  Serial.println("SSID: " + WiFi.SSID(index_ssid - 1));

  WiFi.softAP(wifi_ap_ssid,wifi_ap_pass);

  WiFi.begin(ssid.c_str(),pass.c_str());
//  WiFi.begin(WiFi.SSID(index_ssid - 1),"ABC");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.println(WiFi.localIP());

  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");

  delay(1000);

}