#include "arduino_secrets.h"


#include "thingProperties.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Pines para Wemos D1 R32
const int oneWireBus = 4;    // Pin D4
const int phPin = 36;        // Pin A0 (GPIO 36)
LiquidCrystal_I2C lcd(0x3F, 20, 4); 

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

unsigned long lastApiSend = 0;
const unsigned long apiInterval = 3600000; // 1 Hora en ms
const char* serverName = "http://TU_URL_DE_RENDER_O_IP:5000/recomendaciones";

void setup() {
  Serial.begin(115200);
  delay(1500); 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SMART AQUA v1.0");

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  sensors.begin();
}

void loop() {
  ArduinoCloud.update(); // Mantiene la conexión con la nube
  
  // 1. LECTURA DE SENSORES
  sensors.requestTemperatures();
  DS18b20_temperatura = sensors.getTempCByIndex(0);
  
  // Suavizado de lectura de pH (Promedio)
  float suma = 0;
  for(int i=0; i<20; i++) { suma += analogRead(phPin); delay(5); }
  float voltaje = (suma / 20.0) * (3.3 / 4095.0);
  Ph22_pchimetro = 3.5 * voltaje; // Ajustar tras calibración

  // 2. ACTUALIZAR PANTALLA LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: "); lcd.print(DS18b20_temperatura, 1); lcd.print(" C  ");
  lcd.setCursor(0, 2);
  lcd.print("pH  : "); lcd.print(Ph22_pchimetro, 2); lcd.print("    ");

  // 3. CONSULTA A GEMINI CADA HORA
  if (millis() - lastApiSend >= apiInterval || lastApiSend == 0) {
    if (WiFi.status() == WL_CONNECTED) {
      consultarIA();
      lastApiSend = millis();
    }
  }
}

void consultarIA() {
  lcd.setCursor(0, 3);
  lcd.print("IA: Consultando...  ");
  
  HTTPClient http;
  http.begin(serverName);
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<512> doc;
  doc["temperatura"] = DS18b20_temperatura;
  doc["ph"] = Ph22_pchimetro;
  doc["pregunta"] = "Analiza estos datos para mi pez betta y dame 3 consejos muy breves.";

  String jsonStr;
  serializeJson(doc, jsonStr);

  int httpCode = http.POST(jsonStr);

  if (httpCode > 0) {
    String payload = http.getString();
    StaticJsonDocument<1024> resDoc;
    deserializeJson(resDoc, payload);
    
    // Guardamos la respuesta en la variable de la nube
    gemini_recomendaciones = resDoc["gemini"].as<String>();
    
    lcd.setCursor(0, 3);
    lcd.print("IA: Consejos Listos ");
  } else {
    lcd.setCursor(0, 3);
    lcd.print("IA: Error de Red    ");
  }
  http.end();
}