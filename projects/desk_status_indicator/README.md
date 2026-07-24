# Desk Status Indicator

## Overview

A desk-mounted Arduino device that shows your current working status on a 16×2 LCD and signals it visually via an LED. Two buttons let you toggle between "In a Meeting" (solid LED, live distance readout) and "Locked In" (flashing LED) states.

## How It Works

| Action | LCD | LED |
|--------|-----|-----|
| Boot | Blank | Off |
| Press Button 1 | "In a Meeting" + live distance in inches | Solid on |
| Press Button 1 again | Blank | Off |
| Press Button 2 | "Locked In" | Flashing |
| Press Button 2 again | Blank | Off |
| Press either button while other is active | Switches to new state | Updates accordingly |

Distance updates every 250 ms while in "In a Meeting" mode. The LED flash interval is 500 ms (configurable via `FLASH_INTERVAL` in the sketch). Buttons are debounced in software with a 50 ms delay on the falling edge.

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
