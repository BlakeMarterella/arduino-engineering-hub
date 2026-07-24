# Arduino Uno

## Overview

The Arduino Uno is an 8-bit AVR microcontroller development board (ATmega328P) with 14 digital I/O pins, 6 analog inputs, a 16 MHz crystal oscillator, USB connection, and a 5V operating voltage. It is the most common entry-level Arduino board and the reference platform for the majority of Arduino libraries and tutorials.

## Key Specifications

| Parameter | Value |
|-----------|-------|
| Microcontroller | ATmega328P |
| Operating voltage | 5V |
| Input voltage (recommended) | 7–12V |
| Digital I/O pins | 14 (6 with PWM) |
| Analog input pins | 6 |
| DC current per I/O pin | 40 mA max |
| Flash memory | 32 KB (0.5 KB used by bootloader) |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| Clock speed | 16 MHz |

## Pin Overview

- **Digital pins 0–13**: General-purpose I/O; pin 0 (RX) and 1 (TX) are shared with the USB serial port.
- **PWM pins**: 3, 5, 6, 9, 10, 11 — support `analogWrite()`.
- **Analog pins A0–A5**: 10-bit ADC inputs (0–5V range).
- **Power pins**: 5V, 3.3V (max 50 mA), GND, VIN.
- **I2C**: A4 (SDA), A5 (SCL).
- **SPI**: 10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK).

## Notes

- Digital I/O pins source or sink up to 40 mA; keep total current draw across all pins under 200 mA.
- The 3.3V pin is regulated from the USB/barrel jack — do not use it to drive sensors that draw significant current.
- Pins 0 and 1 (Serial) should be avoided while using the USB serial monitor.

## Resources

- [Official product page](https://docs.arduino.cc/hardware/uno-rev3/)
- [ATmega328P datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
