# Smart Water Tank Monitoring and Control System Using LPC2129

## 1. Project Overview

The **Smart Water Tank Monitoring and Control System Using LPC2129** is an embedded systems project developed using the LPC2129 ARM7 microcontroller.

The project aims to monitor water tank level and temperature, display sensor readings on an LCD, control output devices, and support IoT-based monitoring through an ESP-01 Wi-Fi module and ThingSpeak.

The system integrates microcontroller peripherals such as the Analog-to-Digital Converter (ADC), UART, I²C, external interrupts, LCD interfacing, and relay control.

**Project Title:** Smart Water Tank Monitoring and Control System Using LPC2129  
**Microcontroller:** LPC2129 (ARM7)  
**Domain:** Embedded Systems and IoT  
**Developed at:** Vector India  
**Author:** Yash Pashime

---

## 2. Project Objectives

The main objectives of this project are:

- To monitor the water level in a tank using an analog input.
- To measure temperature using an LM35 temperature sensor.
- To display sensor readings and system status on an LCD.
- To interface external EEPROM using I²C communication.
- To establish serial communication using UART.
- To integrate an ESP-01 Wi-Fi module for IoT connectivity.
- To explore cloud-based data monitoring using ThingSpeak.
- To control output devices such as a pump, valve, and buzzer.
- To understand ARM7 microcontroller peripherals and embedded C programming.

---

## 3. Hardware Components

The project is designed around the following hardware components:

- **LPC2129 ARM7 Microcontroller:** Main controller responsible for executing the embedded application.
- **Water-Level Input:** Analog input used to represent the water level.
- **LM35 Temperature Sensor:** Provides an analog voltage corresponding to temperature.
- **16×2 LCD:** Displays water-level readings, temperature, and system status.
- **AT24C256 EEPROM:** External non-volatile memory for storing data.
- **ESP-01 Wi-Fi Module:** Provides Wi-Fi connectivity for IoT communication.
- **Relay Module:** Used to interface control signals with external loads.
- **Water Pump:** Represents the tank-filling control mechanism.
- **Valve:** Represents water-flow control.
- **Buzzer:** Provides an audible indication of selected system conditions.
- **Push Button:** Supports manual control or user input.

The final hardware configuration depends on the components actually connected to the microcontroller.

---

## 4. Software and Development Tools

The project uses the following software concepts and development tools:

- Embedded C programming
- LPC2129 ARM7 microcontroller programming
- ADC configuration and conversion
- UART serial communication
- I²C communication
- LCD interfacing
- External interrupt handling
- EEPROM interfacing
- ESP-01 Wi-Fi communication
- ThingSpeak IoT platform
- Linux command-line tools for project and source-code management

---

## 5. Project Directory Structure

The project source files are maintained in the following directory:

`ARM_project/smartwatertankmanagement/`

The directory contains the following files:


smartwatertankmanagement/
├── README.md
├── header.h
├── main1.c
├── maindelay.c
├── mainnrtc.c
├── eeprom_driver.c
├── esp_driver.c
├── ext.c
├── mainadc.c
├── mainlcd4bit.c
├── mainuart0.c
├── mainuart1.c
└── servorelay.c


**Note:** This structure represents the listed project files. Update it if you add, remove, or rename any files.

---

## 6. Source File Descriptions

### `main1.c`
Contains the main application code for the water tank monitoring system. Check this file to identify the main execution flow and integration of the different modules.

### `header.h`
Contains shared declarations, macros, and definitions used by the source files. The declarations must match the actual implementation.

### `maindelay.c`
Contains delay-related functions used for timing operations in the embedded application.

### `mainnrtc.c`
Contains I²C-related functions used for communication with compatible peripheral devices. Despite the filename, confirm its exact functionality by examining the source code.

### `eeprom_driver.c`
Contains functions associated with external EEPROM interfacing and memory operations.

### `esp_driver.c`
Contains ESP-01-related communication functions intended to support Wi-Fi and IoT integration.

### `ext.c`
Contains external interrupt-related code for handling interrupt events.

### `mainadc.c`
Contains ADC-related code used to acquire analog input values from connected sensors or test inputs.

### `mainlcd4bit.c`
Contains functions for interfacing an LCD in 4-bit mode.

### `mainuart0.c`
Contains UART0-related serial communication functions.

### `mainuart1.c`
Contains UART1-related serial communication functions.

### `servorelay.c`
Contains servo- and relay-related control code.

The exact functionality of each file should be confirmed against the corresponding source code.

---

## 7. System Architecture

The system is organized into several functional modules.

### Sensor Input Module
The analog water-level input and LM35 temperature sensor provide readings to the LPC2129 through its ADC peripheral.

### Processing Module
The LPC2129 processes the acquired sensor readings and determines the corresponding water-level percentage, temperature, and system status.

### Display Module
The LCD provides a local interface for displaying sensor readings and system information.

### Memory Module
The external AT24C256 EEPROM can be used to store selected information for later retrieval.

### Communication Module
UART interfaces support serial communication with external devices, including the ESP-01 where configured.

### Control Module
Relay outputs and associated control circuits can be used to operate the pump, valve, or other connected devices.

### IoT Module
The ESP-01 and ThingSpeak integration are intended to enable remote monitoring of selected sensor readings and system status.

---

## 8. Working Principle

The intended operation of the system follows these steps:

1. The LPC2129 initializes the required peripherals.
2. The ADC acquires the analog input representing the water level.
3. The ADC acquires the analog signal from the LM35 temperature sensor.
4. The microcontroller converts the ADC readings into meaningful values.
5. The LCD displays the measured values and relevant system status.
6. The control logic evaluates the readings against configured thresholds.
7. The corresponding output devices are controlled when the required conditions are met.
8. Selected data may be stored in external EEPROM.
9. The UART and ESP-01 communication path can transmit data for IoT monitoring when correctly configured.

The actual behavior depends on the implemented logic, peripheral configuration, and hardware connections.

---

## 9. ADC-Based Sensor Monitoring

The LPC2129 ADC peripheral converts analog input voltages into digital values that can be processed by the microcontroller.

### Water-Level Monitoring

The water-level input is read through an ADC channel. The digital reading is converted into a percentage using the scaling formula implemented in the project.

For a 10-bit ADC, the nominal digital output ranges from 0 to 1023.

The percentage calculation can be expressed as:

```c
water_level_percentage = (adc_value * 100) / 1023;
```

This calculation assumes that the analog input has been calibrated so that the ADC range corresponds to the intended water-level range.

### Temperature Monitoring

The LM35 provides an analog voltage proportional to temperature.

The ADC reads this voltage, and the application converts the reading into a temperature value using the appropriate ADC reference voltage and sensor conversion factor.

Accurate temperature measurement depends on the ADC configuration and the conversion formula used in the implementation.

---

## 10. LCD Display

The LCD provides local feedback by displaying information such as:

- Water-level percentage
- Temperature reading
- Pump or system status
- Relevant alerts

The project includes `mainlcd4bit.c`, which is associated with 4-bit LCD interfacing.

The actual displayed information depends on the LCD routines and application code.

---

## 11. UART Communication

UART provides asynchronous serial communication between the LPC2129 and compatible external devices.

The project contains separate UART-related source files:

- `mainuart0.c`
- `mainuart1.c`

These files are intended for UART0 and UART1 functionality.

UART configuration requires the correct peripheral settings, baud rate, pin configuration, and communication parameters.

When interfacing the ESP-01, the voltage levels and serial configuration must be compatible with the module.

---

## 12. I²C and External EEPROM

The project includes I²C-related code and an external AT24C256 EEPROM.

I²C is a serial communication protocol that typically uses two signal lines:

- SDA: Serial Data
- SCL: Serial Clock

The AT24C256 is a non-volatile memory device that retains stored data when power is removed.

Potential uses include storing selected readings or system information.

Successful EEPROM operation requires correct I²C initialization, device addressing, memory addressing, and read/write handling. The implemented driver should be tested against the actual hardware.

---

## 13. ESP-01 and ThingSpeak Integration

The ESP-01 Wi-Fi module is intended to provide network connectivity for IoT monitoring.

The project includes `esp_driver.c` for ESP-01-related functionality.

ThingSpeak can be used to visualize uploaded sensor data through time-series graphs.

### Intended Monitoring Fields

The proposed ThingSpeak channel can use the following fields:

- Field 1: Water-level percentage
- Field 2: Temperature
- Field 3: Pump status

These fields are a suggested channel configuration. They must match the actual data transmitted by the firmware.

### ThingSpeak Graphs

Once valid sensor data is uploaded to the configured channel, ThingSpeak can display time-series graphs showing changes in water level and temperature.

A pump-status field can represent the reported state of the pump if the firmware transmits that information.

**Important:** Graphs will only show actual measurements if the ESP-01 communication, network connection, channel configuration, and data-upload process are functioning correctly. Do not present sample data as measured hardware results.

Never publish Wi-Fi passwords, ThingSpeak write API keys, or other credentials in this repository.

---

## 14. Pump, Valve, and Buzzer Control

The control section is intended to operate output devices according to the application's logic.

Potential functions include:

- Activating the pump when the water level falls below a configured threshold.
- Stopping the pump when the desired water level is reached.
- Operating a valve according to the configured control conditions.
- Activating the buzzer when a specified alert condition occurs.
- Supporting manual control through a push button.

These are intended system behaviors. Confirm that the relevant thresholds, output pins, relay logic, and control conditions are implemented and tested before describing them as completed features.

**Hardware safety:** Test relay outputs with appropriate precautions. Ensure that mains-powered equipment is isolated and handled by a qualified person.

---

## 15. External Interrupt

External interrupts allow the microcontroller to respond to selected external events without continuously polling the relevant input.

The project includes `ext.c` for external interrupt-related functionality.

Possible applications include handling a manual input or triggering a specific control action.

The interrupt source, pin configuration, trigger condition, and interrupt service routine must be verified against the implementation.

---

## 16. Expected Results

When the relevant modules are correctly implemented and tested, the system is intended to provide:

- Analog water-level measurement
- Temperature measurement using the LM35
- Local display of sensor readings
- Serial communication through the configured UART interfaces
- I²C communication with external EEPROM
- Control of connected output devices
- IoT data transmission through the ESP-01
- Remote visualization of uploaded measurements through ThingSpeak

Actual results should be documented after testing the firmware on the target hardware.

---

## 17. Testing and Verification

The following checks can be used to evaluate the project:

1. Verify that the LPC2129 initializes correctly.
2. Check ADC readings using known input voltages.
3. Compare the water-level calculation against calibrated input values.
4. Compare the LM35 temperature reading against a reference thermometer.
5. Verify that the LCD displays the correct values.
6. Test UART communication using a suitable serial interface.
7. Test EEPROM read/write operations and confirm data retention.
8. Verify external interrupt behavior.
9. Test relay and other output controls under safe conditions.
10. Verify ESP-01 communication and network connectivity.
11. Confirm that ThingSpeak receives valid data and displays the intended fields.

Record actual test results rather than assuming that every module works as expected.

---

## 18. Future Enhancements

Potential improvements include:

- Calibrating the water-level sensor for improved measurement accuracy.
- Improving error handling for sensor and communication failures.
- Adding more robust pump-control logic.
- Implementing configurable high- and low-level alerts.
- Improving EEPROM data logging and retrieval.
- Adding reconnection handling for Wi-Fi failures.
- Enhancing the ThingSpeak dashboard.
- Adding manual and automatic operating modes.
- Integrating additional sensors if required.

These items are possible future enhancements, not necessarily features already implemented.

---

## 19. Learning Outcomes

This project provides practical experience with:

- ARM7 LPC2129 microcontroller architecture
- Embedded C programming
- ADC configuration and analog sensor interfacing
- LCD interfacing
- UART serial communication
- I²C communication
- External EEPROM interfacing
- External interrupts
- Relay and output control
- ESP-01 Wi-Fi communication
- IoT data visualization using ThingSpeak
- Modular embedded software development
- Hardware and firmware testing

---

## 20. Conclusion

The Smart Water Tank Monitoring and Control System Using LPC2129 is an embedded systems project that brings together sensor interfacing, microcontroller programming, serial communication, memory interfacing, and intended IoT monitoring.

The project provides a practical platform for understanding how embedded hardware and firmware modules can work together to monitor system conditions and control external devices.

Further testing, calibration, and integration can improve reliability and validate the complete system under real operating conditions.

---

## Author

Yash Pashime  
Embedded Systems Course  
Vector India
