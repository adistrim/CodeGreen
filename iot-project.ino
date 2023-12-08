#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const int rs = D0, en = D1, d4 = D2, d5 = D3, d6 = D4, d7 = D5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int mqPin = A0; // Analog pin for MQ-3 sensor

const char* ssid = "-------";      // Enter your WiFi Name
const char* password = "------"; // Enter your WiFi Password

const char* thingSpeakApiKey = "------";
const long thingSpeakChannel = 0000000;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  lcd.begin(16, 2);
  lcd.print("Connecting...");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Warming Sensor");
  pinMode(mqPin, INPUT);

  int wifiAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && wifiAttempts < 20) {
    delay(500);
    Serial.print(".");
    wifiAttempts++;
  }

  if (WiFi.status() != WL_CONNECTED) {
    lcd.clear();
    lcd.print("Wifi Failed!");
    lcd.setCursor(0, 1);
    lcd.print("Warming Sensor");
  } else {
    lcd.clear();
    lcd.print("Wifi Connected!");
    lcd.setCursor(0, 1);
    lcd.print("Warming Sensor");
  }

  ThingSpeak.begin(client);  // Initialize ThingSpeak
  delay(3000);
}

void loop() {

  int sensorValue = analogRead(mqPin);
  float air_quality = (sensorValue / 1024.0) * 100.0;

  // Print pollution level on LCD
  lcd.setCursor(0, 1);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("Pollution-" + String(air_quality) + "%");

  // Upload data to ThingSpeak
  ThingSpeak.setField(1, air_quality);  // Set the field number and value
  int status = ThingSpeak.writeFields(thingSpeakChannel, thingSpeakApiKey);

  if (status == 200) {
    Serial.println("ThingSpeak update successful.");
  } else {
    Serial.println("Error updating ThingSpeak. HTTP status code: " + String(status));
  }

  delay(10000);  // Delay for a longer period before reading and uploading data again
}
