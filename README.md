# Temperature Monitor System

## Introduction
This README provides an overview of the Temperature Monitor Project using the STM32F401CCG6 microprocessor. This project is designed to monitor temperature using an LM35 sensor, display the temperature on an LCD screen, communicate with a receiver via UART, and control a fan and motor based on temperature thresholds.

## Project Components
- **Microcontroller**: STM32F401CCG6
- **Temperature Sensor**: LM35
- **Peripherals**: LCD, UART, ADC, Timer
- **Actuators**: Fan and Motor (Receiver), LCD and LM35 (Sender)

## Project Overview
The Temperature Monitor Project involves two main components: the Sender and the Receiver. The Sender is responsible for measuring and sending temperature data, while the Receiver receives this data and controls the fan and motor based on temperature thresholds.

### Sender (STM32F401CCG6)
- **LM35 Sensor**: Measures the temperature.
- **LCD**: Displays the current temperature.
- **UART**: Communicates temperature data to the Receiver.
- **Timer**: Manages periodic temperature readings and UART communication.

### Receiver (STM32F401CCG6)
- **UART**: Receives temperature data from the Sender.
- **Fan**: Turns on if the temperature exceeds 90°C.
- **Motor**: deactivate when the temperature remains high for a certain time, initiating AutoParking.
- **LCD**: Can be used to display temperature or system status.

## Project Workflow
Here's the sequence of events for the Temperature Monitor Project:

1. **Monitoring the Temperature**:
   - The Sender continuously measures the temperature using the LM35 sensor.
   - The temperature reading is displayed on the LCD.

2. **Temperature Threshold Check**:
   - If the temperature exceeds 90°C, the Sender sends this data to the Receiver via UART.

3. **Fan Activation**:
   - The Receiver receives the temperature data and checks if it's above 90°C.
   - If the temperature is high, the Receiver activates the fan.

4. **AutoParking (Optional)**:
   - If the temperature remains high after the fan is activated, AutoParking starts.
   - This step may involve additional hardware and logic, such as stopping a car or taking other safety measures.

5. **Temperature Decreases**:
   - When the temperature decreases to below 90°C, the Sender sends this data to the Receiver via UART.

6. **Fan Deactivation**:
   - The Receiver receives the lower temperature reading and deactivates the fan.

## Installation and Setup
To implement this project, you will need to:
- Set up the development environment for STM32 microcontrollers.
- Connect the LM35 sensor, LCD, UART, and other peripherals according to your circuit diagram.
- Write and compile code for both the Sender and Receiver based on the project specifications.
- Load the compiled code onto the respective microcontrollers.
- Ensure proper power supply and connectivity between the Sender and Receiver.

## Project Customization
You can further customize this project by adjusting temperature thresholds, implementing additional safety measures, or adding features such as logging data or remote control.

## Conclusion
The Temperature Monitor Project using the STM32F401CCG6 microcontroller is designed to monitor temperature, control a fan and motor based on temperature thresholds, and communicate between the Sender and Receiver via UART. Customize and expand upon this project to suit your specific requirements and applications.
[Click here to watch the video](https://drive.google.com/file/d/1p9pdvVeNDMJok9A_2910w6CVKsSAX-Ua/view?usp=sharing)

