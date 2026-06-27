# T-to-MO (Text to Morse-Code)

This project uses an ESP32 Wrover to receive text messages wirelessly over Bluetooth Classic (Serial Port Profile) and translate them into Morse code. The output is delivered physically via an LED and a buzzer connected to a single GPIO pin.

## Features
- **Bluetooth Serial Communication:** Receives text inputs wirelessly using Classic Bluetooth (SPP).
- **Morse Code Translation:** Automatically converts text characters (A-Z, 0-9) into dots and dashes.
- **Dual Physical Output:** Triggers an LED and a buzzer simultaneously from a single GPIO pin.
- **Serial Feedback:** Outputs the translated Morse symbols to both the hardware Serial monitor and the Bluetooth terminal.

## Hardware Requirements
- ESP32 Wrover (or compatible ESP32 development board)
- 1x LED
- 1x Resistor (e.g., 220Ω for the LED)
- 1x Buzzer (active or passive)
- Breadboard and jumper wires

### Wiring Diagram
Both the LED and the buzzer are connected to **GPIO 12**:
- **LED:** Connect the positive lead (anode) to **GPIO 12** via a resistor, and the negative lead (cathode) to GND.
- **Buzzer:** Connect the positive terminal to **GPIO 12** and the negative terminal to GND.

---

## Installation Guide

Follow these steps to set up and run the project on your ESP32.

### 1. Prerequisites
Ensure you have the following software installed:
- [Arduino IDE](https://www.arduino.cc/en/software) (version 2.x recommended) or [PlatformIO](https://platformio.org/).
- ESP32 Board Support:
  - In Arduino IDE, go to **File > Preferences** and add the following URL to *Additional Boards Manager URLs*:  
    `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
  - Go to **Tools > Board > Boards Manager**, search for "esp32", and install the package by Espressif Systems.

### 2. Download the Repository
Clone this repository to your local machine:
```bash
git clone https://github.com/jobrain1/T-to-MO.git
```
*(Or download the ZIP file from GitHub and extract it).*

### 3. Compilation and Upload
1. Open the project folder in your IDE.
2. Select your board under **Tools > Board > ESP32 Arduino > ESP32 Wrover Module** (or your specific ESP32 variant).
3. Connect your ESP32 to your computer using a USB cable.
4. Select the correct serial port under **Tools > Port**.
5. Click the **Upload** button to compile and flash the code to your ESP32.
6. Open the Serial Monitor (**Tools > Serial Monitor**) and set the baud rate to **115200** to view diagnostic logs.

---

## How to Use

1. **Power the Device:** Ensure the ESP32 is powered on.
2. **Connect via Bluetooth:**
   - On your smartphone or computer, open your Bluetooth settings and pair with the device named **`ESP32 T to MO`**.
   - Open a Bluetooth Serial terminal application (such as **Serial Bluetooth Terminal** for Android or **Bluetooth Terminal** for iOS/PC).
   - Connect to the paired **`ESP32 T to MO`** device within the app.
3. **Send Messages:**
   - Type a message in the app and press send. 
   - The ESP32 will receive the string, print the translation feedback to the terminal, and output the Morse code signals on GPIO 12 via the LED and buzzer.

---

## Authors

- [@Jo_brain](https://github.com/jobrain1)
