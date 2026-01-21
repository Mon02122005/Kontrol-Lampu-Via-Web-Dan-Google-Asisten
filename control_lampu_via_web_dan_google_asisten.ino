#include <SinricPro.h>
#include <SinricProSwitch.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// WiFi & API Settings
#define WIFI_SSID "Nama Wifi Kamu"
#define WIFI_PASS "Pas Wifi Kamu"
#define APP_KEY "Dari Sinric Pro"
#define APP_SECRET "Dari Sinric Pro"
#define DEVICE_ID "Dari Sinric Pro"
const char* serverUrl = "Url Web Kamu";

#define RELAY_PIN D1  // Pastikan relay aktif HIGH/LOW sesuai hardware
bool lastWebState = false;  // Status terakhir dari web
unsigned long lastCheck = 0;
const unsigned long checkInterval = 1;  // Cek web setiap 2 detik

// Handler SinricPro (kontrol suara)
bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(RELAY_PIN, state ? LOW : HIGH );
  Serial.printf("Lampu %s (via Suara)\n", state ? "ON" : "OFF");
  return true; // Tidak perlu sync ke web
}

// Cek status dari web
void checkWebServer() {
  if (WiFi.status() != WL_CONNECTED) return;

  WiFiClient client;
  HTTPClient http;
  http.begin(client, serverUrl);
  int httpCode = http.GET();

  if (httpCode == 200) {
    String perintah = http.getString();
    perintah.trim();

    if (perintah == "ON" && !lastWebState) {
      digitalWrite(RELAY_PIN, LOW);
      lastWebState = true;
      Serial.println("Lampu ON (via Web)");
    } 
    else if (perintah == "OFF" && lastWebState) {
      digitalWrite(RELAY_PIN, HIGH);
      lastWebState = false;
      Serial.println("Lampu OFF (via Web)");
    }
  }
  http.end();
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(1); Serial.print("."); }
  Serial.println("\nWiFi Connected!");

  // Setup SinricPro (suara)
  SinricProSwitch &mySwitch = SinricPro[DEVICE_ID];
  mySwitch.onPowerState(onPowerState);
  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void loop() {
  SinricPro.handle();  // Handle kontrol suara

  // Handle kontrol web
  if (millis() - lastCheck >= checkInterval) {
    lastCheck = millis();
    checkWebServer();
  }
}