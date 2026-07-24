# HC-SR04 Ultrasonic Distance Sensor

## Overview

The HC-SR04 is a low-cost ultrasonic ranging module that measures distance by emitting a 40 kHz ultrasonic burst and timing the return echo. It outputs a single pulse whose width (in microseconds) is proportional to the round-trip travel time of sound.

## Key Specifications

| Parameter | Value |
|-----------|-------|
| Operating voltage | 5V DC |
| Quiescent current | < 2 mA |
| Working current | 15 mA |
| Ranging distance | 2 cm – 400 cm |
| Ranging accuracy | ±3 mm |
| Measuring angle | ≤ 15° |
| Trigger input pulse | 10 µs HIGH |
| Echo output | 5V pulse, width proportional to distance |
| Minimum cycle time | ~60 ms between readings |

## Pins

| Pin | Description |
|-----|-------------|
| VCC | 5V power supply |
| GND | Ground |
| TRIG | Trigger input (send 10 µs HIGH pulse to start a reading) |
| ECHO | Echo output (HIGH pulse width = round-trip time in µs) |

## How to Use

1. Send a 10 µs HIGH pulse to TRIG.
2. The module emits 8 ultrasonic bursts at 40 kHz.
3. ECHO goes HIGH for the duration of the return echo.
4. Distance = `pulse_duration_µs / 148.0` (inches) or `/ 58.0` (centimeters).

## Notes

- **Requires 5V** — will not operate reliably at 3.3V.
- **ECHO outputs 5V**: safe for Arduino Uno but will damage 3.3V boards (ESP32, Nano 33, etc.) without a voltage divider.
- **Minimum range is 2 cm**: anything closer returns unreliable readings.
- **Allow ≥ 60 ms between readings** to prevent the module from picking up echoes from the previous pulse. 250 ms is a safe interval in practice.
- Do not aim two HC-SR04s at each other — they will interfere with each other's echo signals.
- Use `pulseIn(ECHO_PIN, HIGH, 38000)` with a 38 ms timeout to safely handle out-of-range (no-echo) conditions.

## Resources

- [HC-SR04 datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
