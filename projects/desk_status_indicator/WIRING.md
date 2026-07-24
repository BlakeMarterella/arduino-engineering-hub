# Wiring Guide — Desk Status Indicator

## Components
- Arduino Uno
- 16x2 LCD (HD44780-compatible)
- HC-SR04 ultrasonic distance sensor
- 1x LED (any color)
- 2x Momentary push buttons
- 1x 10kΩ potentiometer (LCD contrast)
- 1x 220Ω resistor (LED current limiting)
- Breadboard + jumper wires

---

## LCD → Arduino

| LCD Pin | Label      | Connects To               |
|---------|------------|---------------------------|
| 1       | VSS        | GND                       |
| 2       | VDD        | 5V                        |
| 3       | V0         | Center wiper of 10kΩ pot  |
| 4       | RS         | Arduino pin 12            |
| 5       | RW         | GND                       |
| 6       | E          | Arduino pin 11            |
| 7–10    | D0–D3      | Not connected (4-bit mode) |
| 11      | D4         | Arduino pin 5             |
| 12      | D5         | Arduino pin 4             |
| 13      | D6         | Arduino pin 3             |
| 14      | D7         | Arduino pin 2             |
| 15      | LED+       | 5V (via 220Ω resistor)    |
| 16      | LED−       | GND                       |

**Contrast potentiometer:** outer pins to 5V and GND, center wiper to LCD pin 3.

---

## HC-SR04 Ultrasonic Sensor → Arduino

| Sensor Pin | Connects To      |
|------------|------------------|
| VCC        | 5V               |
| GND        | GND              |
| TRIG       | Arduino pin 9    |
| ECHO       | Arduino pin 10   |

### ⚠ Important notes about the HC-SR04

- **Must use 5V.** The sensor will not work reliably on 3.3V.
- **Minimum range is 2cm (~0.8 in).** Anything closer returns garbage readings. The sketch handles this and displays "out of range."
- **Maximum range is 400cm (~157 in / ~13 ft).** Beyond that the echo never returns and the sensor times out.
- **ECHO pin outputs 5V.** This is fine for Arduino Uno (which is 5V tolerant), but would damage a 3.3V board (ESP32, Nano 33, etc.) without a voltage divider.
- **Do not point two HC-SR04s at each other** — they will interfere with each other's echo signals.
- The sensor needs ~60ms between readings to avoid picking up echoes from the previous pulse. The sketch reads every 250ms to stay well clear of this.

---

## LED

| Connection          | Connects To                   |
|---------------------|-------------------------------|
| Anode (+, long leg) | 220Ω resistor → Arduino pin 8 |
| Cathode (−, short leg) | GND                        |

---

## Buttons

No resistors needed — the sketch uses `INPUT_PULLUP`.

| Button | Function   | Pin 1          | Pin 2 |
|--------|------------|----------------|-------|
| 1      | On a Call  | Arduino pin 7  | GND   |
| 2      | Locked In  | Arduino pin 6  | GND   |

---

## Pin summary

| Arduino Pin | Connected To     |
|-------------|------------------|
| 2           | LCD D7           |
| 3           | LCD D6           |
| 4           | LCD D5           |
| 5           | LCD D4           |
| 6           | Button 2         |
| 7           | Button 1         |
| 8           | LED              |
| 9           | HC-SR04 TRIG     |
| 10          | HC-SR04 ECHO     |
| 11          | LCD E            |
| 12          | LCD RS           |

---

## How it works

| Action | LCD | LED |
|--------|-----|-----|
| Boot | Blank | Off |
| Press button 1 | "On a Call" + live distance in inches | Solid on |
| Press button 1 again | Blank | Off |
| Press button 2 | "Locked In" | Flashing |
| Press button 2 again | Blank | Off |
| Press either button while other is active | Switches to new state | Updates accordingly |

Distance updates every 250ms while in "On a Call" mode.  
The LED flash interval is 500ms (configurable via `FLASH_INTERVAL` in the sketch).  
Buttons are debounced in software with a 50ms delay on the falling edge.

