#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>
#include "LedControl.h"
LedControl lc=LedControl(12,14,13,1); //12 to Din, 14 to CLK, 13 to CS

int prevKills = -1;

void setup() {

  Serial.begin(115200);
  WiFi.begin("Abc", "11111111");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi connecting...");
    delay(500);
  }
  Serial.println("Wifi connected");
  lc.shutdown(0,false);

  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);

  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi disconnected, retrying...");
    WiFi.begin("Abc", "11111111");
    delay(5000); // Delay before retrying
  }
  Serial.println("Wifi connected");

  HTTPClient http;
  http.begin("https://api.mozambiquehe.re/bridge?auth=d7225f3fdec52d224d6d738c8f1df3b2&platform=PC&player=JasonMgrass");

  int httpCode = http.GET();
  if (httpCode > 0) {
    String input = http.getString();
    DynamicJsonDocument doc(12288);
    DeserializationError error = deserializeJson(doc, input);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    JsonObject legends_all_Pathfinder_data_1 = doc["legends"]["all"]["Pathfinder"]["data"][1];
    int legends_all_Pathfinder_data_1_value = legends_all_Pathfinder_data_1["value"];
    String kills = String(legends_all_Pathfinder_data_1_value);

    if (kills.toInt() != prevKills) {
      for (int i = 0; i < kills.length(); i++) {
        char c = kills.charAt(i);
        lc.setChar(0, 7 - i, c, false);
        delay(50); // Delay between each character (adjust as needed)
      }

      prevKills = kills.toInt();
    }
  }
  else {
    Serial.println("Error on HTTP request");
  }

  http.end(); // Free the resources

  delay(60000); // Wait 30 seconds before next API call
}
