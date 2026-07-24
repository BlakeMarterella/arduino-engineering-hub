# Wiring Guide — Desk Status Indicator

## Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| 16×2 LCD (HD44780-compatible) | 1 |
| HC-SR04 Ultrasonic Distance Sensor | 1 |
| LED (any color) | 1 |
| Momentary push button | 2 |
| 10 kΩ potentiometer (LCD contrast) | 1 |
| 220 Ω resistor (LED current limiting) | 1 |
| Breadboard + jumper wires | — |

---

## Connections

### LCD (16×2 HD44780)

| Pin | Label | Connects To |
|-----|-------|-------------|
| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | V0 | Center wiper of 10 kΩ potentiometer |
| 4 | RS | Arduino pin 12 |
| 5 | RW | GND |
| 6 | E | Arduino pin 11 |
| 7–10 | D0–D3 | Not connected (4-bit mode) |
| 11 | D4 | Arduino pin 5 |
| 12 | D5 | Arduino pin 4 |
| 13 | D6 | Arduino pin 3 |
| 14 | D7 | Arduino pin 2 |
| 15 | LED+ | 5V (via 220 Ω resistor) |
| 16 | LED− | GND |

The LCD operates in 4-bit mode, so data pins D0–D3 are left unconnected. The contrast potentiometer outer pins connect to 5V and GND; the center wiper connects to LCD pin 3 (V0).

### HC-SR04 Ultrasonic Sensor

| Pin | Connects To |
|-----|-------------|
| VCC | 5V |
| GND | GND |
| TRIG | Arduino pin 9 |
| ECHO | Arduino pin 10 |

The sensor requires 5V — it will not work reliably at 3.3V. The ECHO pin outputs 5V, which is safe for the Arduino Uno but would damage a 3.3V board without a voltage divider. Minimum reliable range is 2 cm; maximum is 400 cm. Allow at least 60 ms between readings to avoid echo interference; the sketch reads every 250 ms.

### LED

| Pin | Label | Connects To |
|-----|-------|-------------|
| Anode | + (long leg) | 220 Ω resistor → Arduino pin 8 |
| Cathode | − (short leg) | GND |

The 220 Ω resistor limits current to a safe level for both the LED and the Arduino output pin.

### Button 1 (On a Call)

| Pin | Connects To |
|-----|-------------|
| Terminal 1 | Arduino pin 7 |
| Terminal 2 | GND |

The sketch uses `INPUT_PULLUP` — no external pull-up resistor is needed. The pin reads LOW when pressed.

### Button 2 (Locked In)

| Pin | Connects To |
|-----|-------------|
| Terminal 1 | Arduino pin 6 |
| Terminal 2 | GND |

Same wiring convention as Button 1.

---

## Pin Summary

| Arduino Pin | Connected To |
|-------------|--------------|
| 2 | LCD D7 |
| 3 | LCD D6 |
| 4 | LCD D5 |
| 5 | LCD D4 |
| 6 | Button 2 (Locked In) |
| 7 | Button 1 (On a Call) |
| 8 | LED |
| 9 | HC-SR04 TRIG |
| 10 | HC-SR04 ECHO |
| 11 | LCD E |
| 12 | LCD RS |
