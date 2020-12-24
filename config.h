/**
  @project    LeHAk
  @brief      A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller
  @file       config.h
  @copyright  Licensed under the MIT License, Copyright (c) 2020 EricConner.net
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
  
  // Max 4 sensors (L1, L2, L3 & L4) 
  void sensorSetup() {
    // Sensor 1
    sensor[0].name = "Hot Water Heater";
    sensor[0].topic = "hot_water_heater";
    sensor[0].statusPin = L1;
    sensor[0].statusLogic = NO;
    sensor[0].enabled = true;
    
    // Sensor 2
    sensor[1].name = "Condensate Pump";
    sensor[1].topic = "condensate_pump";
    sensor[1].statusPin = L2;
    sensor[1].statusLogic = NC;
    sensor[1].enabled = true;
    
    // Sensor 3
    sensor[2].name = "Washing Machine";
    sensor[2].topic = "washing_machine";
    sensor[2].statusPin = L3;
    sensor[2].statusLogic = NO;
    sensor[2].enabled = false;
    
    // Sensor 4
    sensor[3].name = "Laundry Sink";
    sensor[3].topic = "laundry_sink";
    sensor[3].statusPin = L4;
    sensor[3].statusLogic = NO;
    sensor[3].enabled = false;
  }

#endif  // CONFIG_H_
