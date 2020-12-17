# LeHAk

## A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller

```yaml
binary_sensor:
  - platform: mqtt
    name: "Washing Machine"
    device_class: moisture
    state_topic: "sensor/moisture/washing_machine/state"
    payload_on: "on"
    payload_off: "off"
    availability:
      - topic: "LeHAk/availability"
        payload_available: "online"
        payload_not_available: "offline"
    qos: 0
  - platform: mqtt
    name: "Hot Water Heater"
    device_class: moisture
    state_topic: "sensor/moisture/hot_water_heater/state"
    payload_on: "on"
    payload_off: "off"
    availability:
      - topic: "LeHAk/availability"
        payload_available: "online"
        payload_not_available: "offline"
    qos: 0
  - platform: mqtt
    name: "Condensate Pump"
    device_class: problem
    state_topic: "sensor/problem/condensate_pump/state"
    payload_on: "on"
    payload_off: "off"
    availability:
      - topic: "LeHAk/availability"
        payload_available: "online"
        payload_not_available: "offline"
    qos: 0
```
