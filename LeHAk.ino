/*   
 * LeHAk
 * v2020.1217.1
 * A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller
 * Licensed under the MIT License, Copyright (c) 2020 EricConner.net
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "./sensor_t.h"
#include "./config.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* mqtt_broker = MQTT_BROKER;
const char* mqtt_clientId = MQTT_CLIENTID;
const char* mqtt_username = MQTT_USERNAME;
const char* mqtt_password = MQTT_PASSWORD;

int debounceTime = 2000;

String availabilityBase = MQTT_CLIENTID;
String availabilitySuffix = "/availability";
String availabilityTopicStr = availabilityBase + availabilitySuffix;
const char* availabilityTopic = availabilityTopicStr.c_str();

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  Serial.println("\nStarting LeHAk...\n");
  
  // Load sensor data from config.h
  sensorSetup();
  
  // Setup pin and initialize values for each sensor
  for (int s = 0; s < ioCount; s++) {
    if (sensor[s].enabled) {
      pinMode(sensor[s].statusPin, INPUT_PULLUP);
      Serial.print("Configured: ");
      Serial.println(sensor[s].name);
      delay(500);
      
      state[s].value = digitalRead(sensor[s].statusPin);
      state[s].lastValue = state[s].value;
      state[s].lastTime = millis();
    }
  }
  
  setupWifi();
  client.setServer(mqtt_broker, 1883);
  reconnect();
  delay(500);
  
  // Publish sensor state at startup
  for (int s = 0; s < ioCount; s++) {
    if (sensor[s].enabled) {
      publishState(s);
      delay(500);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  checkSensors();
}

// Wifi setup function
void setupWifi() {
  delay(10);
  Serial.print("\nConnecting to ");
  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWiFi connected - IP address: ");
  Serial.println(WiFi.localIP());
}

// Connect/Reconnect to the MQTT broker
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("\nAttempting MQTT connection...");
    // Attempt to connect
    if (client.connect(mqtt_clientId, mqtt_username, mqtt_password, availabilityTopic, 0, true, "offline")) {
      Serial.println("Connected!\n");

      // Publish the availability message on connect/reconnect
      Serial.print("Published: ");
      Serial.print(availabilityTopic);
      Serial.println(" - \"online\"");
      client.publish(availabilityTopic, "online", true);
    }
  }
}

// Check sensors function
void checkSensors() {
  for (int s = 0; s < ioCount; s++) {
    // Check is sensor is enabled
    if (sensor[s].enabled) {
      // Get current sensor state
      state[s].value = digitalRead(sensor[s].statusPin);
      // Check if state has changed
      if (state[s].value != state[s].lastValue) {
        state[s].time = millis();
        // Debounce input
        if (state[s].time - state[s].lastTime >= debounceTime) {
          publishState(s);
          state[s].lastValue = state[s].value;
          state[s].lastTime = state[s].time;
        }
      }
    }
  }
  
  delay(1000);
}

// Publish sensor state function
void publishState(uint8_t s) {
  String stateStr = sensor[s].topic + "/state";
  const char*  stateTopic = stateStr.c_str();
  
  if (state[s].value == HIGH) {
    if (sensor[s].statusLogic == NO) {
      Serial.print("Published: ");
      Serial.print(stateTopic);
      Serial.println(" - \"off\"");
      client.publish(stateTopic, "off", true);
    } else if (sensor[s].statusLogic == NC) {
      Serial.print("Published: ");
      Serial.print(stateTopic);
      Serial.println(" - \"on\"");
      client.publish(stateTopic, "on", true);
    }
  } else if (state[s].value == LOW) {
    if (sensor[s].statusLogic == NO) {
      Serial.print("Published: ");
      Serial.print(stateTopic);
      Serial.println(" - \"on\"");
      client.publish(stateTopic, "on", true);
    } else if (sensor[s].statusLogic == NC) {
      Serial.print("Published: ");
      Serial.print(stateTopic);
      Serial.println(" - \"off\"");
      client.publish(stateTopic, "off", true);
    }
  }
}
