# LeHAk

## A Home-Automation-friendly ESP8266-based MQTT Binary Sensor Controller

```yaml
binary_sensor:
  - platform: mqtt
    name: "Hot Water Heater"
    device_class: moisture
    state_topic: "LeHAk/hot_water_heater/state"
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
    state_topic: "LeHAk/condensate_pump/state"
    payload_on: "on"
    payload_off: "off"
    availability:
      - topic: "LeHAk/availability"
        payload_available: "online"
        payload_not_available: "offline"
    qos: 0
```
