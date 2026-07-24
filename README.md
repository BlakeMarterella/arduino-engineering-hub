# Arduino Engineering Hub

A collection of Arduino projects and hardware documentation.

## Projects

| Name | Description | Created |
|------|-------------|---------|
| [Desk Status Indicator](projects/desk_status_indicator/README.md) | A desk-mounted device that displays your working status on a 16×2 LCD and signals it via an LED using two toggle buttons. | 2026-07-24 |

## Hardware

| Component | Details |
|-----------|---------|
| [Arduino Uno](hardware/arduino_uno.md) | ATmega328P-based microcontroller board; 5V, 14 digital I/O, 6 analog inputs, 16 MHz |
| [16×2 LCD (HD44780)](hardware/lcd_16x2_hd44780.md) | 16-column × 2-row character display; 4-bit parallel interface; driven by `LiquidCrystal` library |
| [HC-SR04 Ultrasonic Sensor](hardware/hc_sr04.md) | Ultrasonic distance sensor; 2–400 cm range; 5V required; TRIG/ECHO interface |
| [LED](hardware/led.md) | Standard 5 mm through-hole indicator LED; requires current-limiting resistor |
| [Momentary Push Button](hardware/pushbutton.md) | Tactile switch; normally open; used with `INPUT_PULLUP` — no external resistor needed |
| [Potentiometer](hardware/potentiometer.md) | 3-terminal variable resistor; 10 kΩ used for LCD contrast adjustment |
