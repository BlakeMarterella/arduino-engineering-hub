# Momentary Push Button

## Overview

A momentary push button (tactile switch) is a normally-open switch that closes a circuit only while pressed. It is the standard way to provide manual input to an Arduino without additional circuitry when used with the built-in `INPUT_PULLUP` mode.

## Pin Layout (4-pin tactile switch)

Most common breadboard-compatible tactile switches have 4 pins arranged as two electrically connected pairs:

```
[1]---[2]
        (open)
[3]---[4]
```

Pins 1 & 2 are internally connected; pins 3 & 4 are internally connected. Pressing the button bridges the two pairs.

## Usage with Arduino (INPUT_PULLUP)

Wire one terminal to a digital pin and the other to GND. No external resistor is needed.

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);

// Pin reads HIGH when not pressed, LOW when pressed
bool pressed = (digitalRead(BUTTON_PIN) == LOW);
```

## Notes

- Always debounce in software (50 ms delay or state-machine approach) or hardware (100 nF capacitor across the switch) to prevent multiple triggers per press.
- `INPUT_PULLUP` uses the Arduino's internal ~20–50 kΩ pull-up resistor, eliminating the need for an external resistor.
- Standard tactile switches are rated for low current/voltage (typically 50 mA / 12V) — do not use them for mains switching.
