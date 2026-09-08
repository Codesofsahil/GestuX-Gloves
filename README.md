# GestuX Gloves 🧤

**GestuX Gloves** is a wearable assistive communication system designed to convert predefined hand gestures into **text and speech**, helping bridge the communication gap between sign-language users and people unfamiliar with sign language.

The system uses a combination of **finger-contact detection and motion sensing** to recognize gestures. An Arduino Uno processes the inputs, displays the corresponding message on a 16×2 LCD, and wirelessly transmits the message to an Android application through an HC-05 Bluetooth module. The mobile application then converts the received text into speech using Text-to-Speech (TTS).

## 🚀 Key Features

- 🧤 Wearable glove-based gesture recognition
- 👆 Finger gesture detection using a combinational contact-based circuit
- 📐 Hand orientation and motion detection using MPU6050
- 🧠 Predefined gesture-to-message mapping
- 📺 Real-time message display using a 16×2 LCD
- 📡 Wireless communication using HC-05 Bluetooth
- 📱 Android mobile application
- 🔊 Text-to-Speech voice output
- 💰 Cost-effective alternative to flex-sensor-based systems
- ⚡ Real-time gesture processing

## 🛠️ Tech Stack

### Hardware
- Arduino Uno
- MPU6050 Accelerometer & Gyroscope
- HC-05 Bluetooth Module
- 16×2 LCD Display
- Combinational Contact-Based Finger Circuit
- Metal Contact Plates
- Rechargeable Battery & Charging Module

### Software
- Embedded C/C++
- Arduino IDE
- MIT App Inventor
- Android Text-to-Speech (TTS)
- I2C Communication
- Serial/Bluetooth Communication

## ⚙️ How It Works

1. The user performs a predefined finger or motion gesture.
2. Metal contact points detect finger combinations while the MPU6050 detects hand orientation and movement.
3. The Arduino Uno processes the sensor inputs and matches them against predefined gesture logic.
4. The corresponding message is displayed on the 16×2 LCD.
5. The same message is transmitted wirelessly through the HC-05 Bluetooth module.
6. The Android application receives the message and converts it into audible speech using TTS.

```text
Hand Gesture
     ↓
Contact + Motion Detection
     ↓
Arduino Uno
     ↓
Gesture Matching
     ↓
 ┌───────────────┐
 ↓               ↓
LCD Display    HC-05 Bluetooth
                 ↓
          Android Application
                 ↓
            Text-to-Speech
                 ↓
             Voice Output
