/**
  @project    LeHAk
  @brief      A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller
  @file       sensor_t.h
  @copyright  Licensed under the MIT License, Copyright (c) 2020 EricConner.net
*/

#ifndef SENSOR_T_H_
  #define SENSOR_T_H_
  
  #define L1 12
  #define L2 14 
  #define L3 13
  #define L4 15
  
  #define ioCount 4
  
  enum logicBool {
    NO,
    NC
  };
  
  struct sensor_t {
    String name = "";
    String topic = "";
    int statusPin = 0;
    logicBool statusLogic = NC;
    bool state = false;
    bool enabled = false;
    bool alarm = false;
  } sensor[ioCount];
  
  struct state_t {
    bool value = false;
    bool lastValue = false;
    unsigned int time = 0;
    unsigned int lastTime = 0;
  } state[ioCount];

#endif  // SENSOR_T_H_
