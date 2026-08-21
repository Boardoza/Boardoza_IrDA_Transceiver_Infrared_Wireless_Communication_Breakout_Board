# Boardoza IrDA Transceiver Breakout Board

The **Boardoza IrDA Transceiver** is a compact infrared communication breakout board designed for reliable short-range wireless data transfer using modulated infrared light. The board integrates both an infrared transmitter and a demodulating infrared receiver, enabling digital data transmission and reception through a simple TXD/RXD interface. It supports operation with both **3.3V and 5V systems**, making it compatible with a wide range of microcontroller platforms.

The onboard hardware-driven LED indicators provide instant visual feedback for power, transmission, and reception activities, making debugging and communication monitoring extremely convenient during development. With its compact footprint and integrated infrared communication circuitry, this board is ideal for **embedded wireless links, short-range wireless control systems, educational electronics projects, robotics, and custom infrared serial communication applications**.

## [Click here to purchase!](https://www.ozdisan.com/ureticiler/boardoza)

| Front Side | Back Side |
|:---:|:---:|
| ![Boardoza IrDA Transceiver Front](./assets/IrDA%20Transceiver%20Front.png) | ![Boardoza IrDA Transceiver Back](./assets/IrDA%20Transceiver%20Back.png) |

---

## Key Features

- **38 kHz Infrared Communication:** Supports reliable infrared wireless data transfer using a 38 kHz modulated carrier frequency.
- **Integrated IR Receiver Circuit:** Features a built-in demodulating infrared receiver for clean and stable digital signal output.
- **Wide Voltage Compatibility:** Operates seamlessly with both 3.3V and 5V microcontroller platforms.
- **Real-Time Status Indicators:** Dedicated hardware LEDs provide instant visual feedback for data reception (D2) and data transmission (D3) activity.  
- **Simple Digital TXD/RXD Interface:** Provides straightforward MCU communication through TXD input and RXD output pins.
- **TX Echo Functionality:** Transmitted data is internally echoed to the RX output for easier debugging and monitoring.

---

## Technical Specifications

**Model:** IrDA Transceiver   
**Manufactorer:** Boardoza  
**Functions:** Infrared Data Transmitter & Receiver  
**Input Voltage:** 3.3V – 5V  
**Communication Type:** Asynchronous Serial  
**Carrier Frequency:** 38 kHz  
**Maximum Data Rate:** Up to 1250 bps  
**Infrared LED Wavelength:** 940 nm  
**Transmission Range (3.3V):** Up to 430 cm  
**Transmission Range (5V):** Up to 600 cm  
**Indicator LEDs:** RX (Yellow), TX (Green)  
**Receiver Type:** Demodulating IR Receiver Module  
**Operating Temperature:** -40°C to +85°C  
**Board Dimensions:** 20mm x 20mm  

> Warning: The TXD pin directly controls the IR transmitter stage and must only be driven with short data pulses. Applying a continuous HIGH level to TXD may cause excessive current through the IR LED/driver circuit and can permanently damage the board.

---

## Board Pinout

### ( J1 ) Communication Connector

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | VCC | Power Supply Input |
| 2 | RXD | Data Receive Output |
| 3 | TXD | Data Transmit Input |
| 4 | GND | Ground |

---

## Board Dimensions

<img src="./assets/IrDA Transceiver Dimensions.png" alt="Board Dimensions" width="450"/>

---

## Step Files

[Boardoza IrDA Transceiver.step](./assets/IrDA%20Transceiver%20Step.step)

---

## Datasheet

[VSMB10940 Datasheet.pdf](./assets/VSMB10940%20Datasheet.pdf)

[IR Receiver Module Datasheet.pdf](./assets/DMO-0000008%20Datasheet.pdf)

---

## Version History

- V1.0.0 - Initial Release

---

## Support

- If you have any questions or need support, please contact support@boardoza.com

---

## **License**

This repository contains both hardware and software components:

### **Hardware Design**

[![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

All hardware design files are licensed under [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### **Software/Firmware**

[![BSD-3-Clause][bsd-shield]][bsd]

All software and firmware are licensed under [BSD 3-Clause License][bsd].

[bsd]: https://opensource.org/licenses/BSD-3-Clause
[bsd-shield]: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
