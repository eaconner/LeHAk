/*   
 * LeHAk
 * A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller
 * Licensed under the MIT License, Copyright (c) 2020 EricConner.net
*/

#ifndef CONFIG_H_
  #define CONFIG_H_
  
  #include "./sensor_t.h"
  
  // Wifi Parameters
  #define WIFI_SSID "WIFI_SSID"
  #define WIFI_PASSWORD "WIFI_PASSWORD"
  
  // MQTT Parameters
  #define MQTT_BROKER "192.168.0.xxx"
  #define MQTT_CLIENTID "LeHAk"
  #define MQTT_USERNAME "MQTT_USERNAME"
  #define MQTT_PASSWORD "MQTT_PASSWORD"
  
  // Max 7 sensors, don't use D0 or D3. 
  void sensorSetup() {
    // Sensor 0
    sensor[0].name = "Washing Machine";
    sensor[0].topic = "sensor/moisture/washing_machine";
    sensor[0].statusPin = D5;
    sensor[0].statusLogic = NO;
    sensor[0].enabled = false;
    
    // Sensor 1
    sensor[1].name = "Hot Water Heater";
    sensor[1].topic = "sensor/moisture/hot_water_heater";
    sensor[1].statusPin = D6;
    sensor[1].statusLogic = NO;
    sensor[1].enabled = true;
    
    // Sensor 2
    sensor[2].name = "Condensate Pump";
    sensor[2].topic = "sensor/problem/condensate_pump";
    sensor[2].statusPin = D7;
    sensor[2].statusLogic = NC;
    sensor[2].enabled = true;
  }

#endif  // CONFIG_H_
