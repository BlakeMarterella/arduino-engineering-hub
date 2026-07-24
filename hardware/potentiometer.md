# Potentiometer

## Overview

A potentiometer (pot) is a three-terminal variable resistor that acts as an adjustable voltage divider. Rotating the shaft moves a wiper contact along a resistive track, producing an output voltage between 0V and the supply voltage.

## Key Specifications

Common values used in Arduino projects: 10 kΩ (contrast adjust, analog input), 1 kΩ–100 kΩ for general use.

| Terminal | Description |
|----------|-------------|
| Left outer | One end of the resistive track (connect to GND or VCC) |
| Right outer | Other end of the resistive track (connect to VCC or GND) |
| Center wiper | Variable output — connect to the target input pin |

## Common Uses

| Use Case | Typical Value |
|----------|---------------|
| LCD contrast (V0 pin) | 10 kΩ |
| Analog input dial | 10 kΩ |
| Motor speed control | 10 kΩ–50 kΩ |

## Notes

- The outer terminals are interchangeable — swapping them reverses the direction of travel (min↔max).
- For analog reads on Arduino: outer terminals to 5V and GND, wiper to an analog input pin (A0–A5).
- Potentiometers rated for panel mounting have a threaded bushing and nut for chassis installation; breadboard-compatible versions have straight pins.
