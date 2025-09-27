# DIY Digital Multimeter with Arduino

![Arduino Digital Multimeter](https://circuitdigest.com/sites/default/files/projectimage_mic/arduino-meter.jpg)

## Project Overview

This project demonstrates how to build a low-cost digital multimeter using Arduino and basic electronic components. The multimeter can measure voltage up to 24V, test diodes, measure resistance, check LED voltage drop, and perform continuity testing with an audible buzzer.

**Source:** [CircuitDigest - DIY Digital Multimeter with Arduino](https://circuitdigest.com/microcontroller-projects/diy-digital-multimeter-with-arduino-for-measuring-voltage-and-resistance)

## Features

- **Voltage Measurement**: Up to 24V DC
- **Diode Testing**: Forward voltage drop measurement
- **Resistance Measurement**: Ohm meter functionality
- **LED Testing**: Voltage drop across LEDs
- **Continuity Testing**: With audible buzzer indication
- **OLED Display**: 0.91" 128x32 display for readings
- **Battery Powered**: Portable design with dual 3.7V batteries
- **Mode Selection**: Push button to cycle through different measurement modes

## Components Required

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Pro Micro | 1 | Main microcontroller |
| 0.91" [OLED Display](https://circuitdigest.com/microcontroller-projects/interfacing-oled-display-with-arduino) (128x32) | 1 | Display for measurements |
| Push Button | 1 | Mode selection |
| Toggle Switch | 1 | Power switch |
| Active Buzzer | 1 | Continuity indication |
| Banana Sockets | 4 | Test probe connections |
| 1K Resistor | 1 | Current limiting |
| 10K Resistor | 1 | Voltage divider |
| 4.7K Resistor | 2 | Voltage divider |
| AMS1117-5.0 | 1 | 5V voltage regulator |
| 3.7V Lithium Battery | 2 | Power supply (300mA) |
| Perfboard | 1 | Circuit assembly |
| Connecting Wires | As needed | Circuit connections |

## Circuit Diagram

The circuit uses Arduino as the main controller with:
- **Voltage divider network** (10K and parallel 4.7K resistors) for voltage measurement up to 24V
- **Two pairs of banana connectors** for different measurement types
- **OLED display** for data visualization
- **Push button** for mode switching
- **Dual battery setup** with 5V regulation

⚠️ **Warning**: Input voltage should not exceed 24V to prevent damage to the device.

## Pin Configuration

| Arduino Pin | Connection |
|-------------|------------|
| A0 | Voltage measurement input |
| A2 | Resistance/Diode test input |
| Pin 7 | Mode switch button (INPUT_PULLUP) |
| Pin 9 | Buzzer output |
| Pin 13 | Status LED |
| SDA/SCL | OLED Display |

## Software Setup

### Required Libraries

Install the following libraries in Arduino IDE:

```cpp
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
```

### Display Configuration

```cpp
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
```

## Operation Modes

### Mode 0: Voltage Measurement
- Measures DC voltage from 0-24V
- Uses voltage divider for safe measurement
- Displays result on OLED in volts

### Mode 1: Diode/LED Test
- Measures forward voltage drop
- Useful for testing diodes and LEDs
- Shows voltage drop across test component

### Mode 2: Resistance Measurement (Ohm Meter)
- Measures resistance values
- Displays in ohms or kiloohms
- Uses voltage divider principle

### Mode 3: Continuity Test
- Tests for electrical continuity
- Buzzer sounds if resistance < 100 ohms
- Visual and audible indication

## How to Use

1. **Power On**: Use the toggle switch to power the device
2. **Mode Selection**: Press the push button to cycle through modes:
   - Mode 0: Voltmeter
   - Mode 1: Diode/LED Test
   - Mode 2: Ohm Meter
   - Mode 3: Continuity Test
3. **Take Measurements**: Connect test probes to appropriate banana sockets
4. **Read Results**: View measurements on the OLED display

## Assembly Instructions

1. **Circuit Assembly**: Solder components on the perfboard according to the circuit diagram
2. **Display Connection**: Wire OLED display to Arduino I2C pins
3. **Battery Setup**: Connect dual 3.7V batteries in series through voltage regulator
4. **Enclosure**: Use provided STL files for 3D printed case
5. **Calibration**: May require minor calibration for accurate voltage readings

## 3D Printed Enclosure

A custom enclosure can be 3D printed to house the circuit and batteries professionally. The STL files are available for download from the source project.

## Calibration Notes

- The voltage measurement may show ±200mV difference compared to commercial multimeters
- Calibration can be done by adjusting the voltage divider resistor values in the code
- For better accuracy, use precision resistors (1% tolerance)

## Possible Improvements

- **Reduce connectors**: Use additional IC to reduce banana sockets to single pair
- **Wireless capability**: Replace Arduino with ESP32 for WiFi features
- **PCB design**: Create custom PCB for better mechanical stability
- **Auto-ranging**: Implement automatic range selection
- **Data logging**: Add SD card for measurement logging

## Code Structure

The main code consists of:
- **Setup()**: Initialise display, pins, and serial communication
- **Loop()**: Handle mode switching and measurements
- **Mode functions**: Separate logic for each measurement type
- **Display functions**: Update OLED with measurement data

## Safety Considerations

- Maximum input voltage: 24V DC
- Ensure proper polarity when measuring DC voltage
- Use appropriate test leads and probes
- Check battery voltage regularly for accurate readings

## Troubleshooting

| Issue | Solution |
|-------|----------|
| No display | Check OLED connections and I2C address |
| Incorrect readings | Verify resistor values and calibrate |
| No buzzer sound | Check buzzer polarity and pin connection |
| Mode not switching | Verify button connection and pull-up resistor |

## License

This project is based on the original work from CircuitDigest. Please take a look at their licensing terms for commercial use.

## Contributing

Please feel free to fix this project and submit any improvements. Some areas for enhancement:
- Code optimisation
- Additional measurement functions
- Improved user interface
- Better calibration methods

## Related Projects

- [IoT Based Electricity Energy Meter](https://circuitdigest.com/microcontroller-projects/iot-electricity-energy-meter-using-esp12-arduino)
- [Arduino Water Flow Sensor](https://circuitdigest.com/microcontroller-projects/arduino-based-water-flow-sensor)
- [Arduino GPS Speedometer](https://circuitdigest.com/microcontroller-projects/arduino-gps-speedometer-using-oled)
- [Arduino Frequency Counter](https://circuitdigest.com/microcontroller-projects/arduino-frequency-counter-circuit)
- [Arduino Projects](https://circuitdigest.com/arduino-projects)

---

**Project Source**: [CircuitDigest DIY Digital Multimeter](https://circuitdigest.com/microcontroller-projects/diy-digital-multimeter-with-arduino-for-measuring-voltage-and-resistance)

**Difficulty Level**: Intermediate  
**Estimated Build Time**: 4-6 hours  
**Cost**: $25-35 USD
