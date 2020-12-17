/*   
 * LeHAk
 * A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller
 * Licensed under the MIT License, Copyright (c) 2020 EricConner.net
*/

#ifndef SENSOR_T_H_
  #define SENSOR_T_H_
  
  #define D1 5
  #define D2 4
  #define D4 2
  #define D5 14
  #define D6 12 
  #define D7 13
  #define D8 15
  
  #define ioCount 7
  
  enum logicBool {
    NO,
    NC
  };
  
  struct sensor_t {
    String name;
    String topic;
    int statusPin;
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
