# LED (Light-Emitting Diode)

## Overview

An LED is a two-terminal semiconductor device that emits light when current flows through it in the forward direction. It is a standard indicator component in Arduino projects, driven directly from a digital output pin through a current-limiting resistor.

## Key Specifications

Typical 5 mm through-hole LED (values vary by color and manufacturer):

| Parameter | Typical Value |
|-----------|---------------|
| Forward voltage (Vf) | 1.8–2.2V (red/yellow), 3.0–3.4V (blue/white/green) |
| Forward current (If) | 10–20 mA |
| Max current | 30–40 mA |

## Pin Identification

| Terminal | Identifier | Description |
|----------|------------|-------------|
| Anode | + / long leg / flat-side mark absent | Positive terminal; connect toward power |
| Cathode | − / short leg / flat side on rim | Negative terminal; connect to GND |

## Current-Limiting Resistor

Always use a series resistor between the Arduino pin and the LED:

```
R = (Vcc - Vf) / If
```

At 5V with a red LED (Vf ≈ 2V) at 10 mA: R = (5 − 2) / 0.01 = **300 Ω** (use 220 Ω–330 Ω from standard values).

## Notes

- Arduino digital pins are rated at 40 mA max and 5V — never connect an LED directly without a resistor.
- Driving the LED from the pin's HIGH state is the most common approach (`digitalWrite(pin, HIGH)` = LED on).
- For very bright or high-power LEDs, use a transistor or MOSFET to avoid exceeding the pin's current limit.
