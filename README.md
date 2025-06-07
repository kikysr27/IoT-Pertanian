
# 🌐 IoT Sensor Monitoring System

A real-time IoT monitoring system for temperature, humidity, and distance using **Arduino**, **Python**, **Firebase Realtime Database**, and a **Flutter mobile application**.

## 📌 System Architecture

```
Sensor (Arduino UNO/Nano)
  └── DHT11/DHT22 for Temperature & Humidity
  └── HC-SR04 for Distance
        │
        ▼
Python Script (Serial Communication)
        │
        ▼
Firebase Realtime Database
        │
        ▼
Flutter Mobile App (Real-time Display)
```

---

## 🚀 Features

- 🌡️ **Real-time Temperature Monitoring** (°C)
- 💧 **Real-time Humidity Monitoring** (%)
- 📏 **Real-time Distance Monitoring** (cm)
- 🔄 Automatic periodic data updates
- 🕒 Live display with recent history log
- 🔔 Clean and responsive Flutter UI

---

## 🧰 Tech Stack

| Component       | Technology                        |
|------------------|------------------------------------|
| **Microcontroller** | Arduino UNO / Nano               |
| **Sensors**         | DHT11 / DHT22, HC-SR04           |
| **Middle Layer**    | Python (`pyserial`, `firebase-admin`) |
| **Backend**         | Firebase Realtime Database       |
| **Frontend**        | Flutter Mobile App               |

---

## 📁 Project Structure

```
/arduino/
  └── sensor_monitor.ino           # Arduino sketch to read sensor data
/python/
  └── firebase_uploader.py         # Python script for serial read and upload to Firebase
/flutter_app/
  ├── lib/
  │   ├── main.dart
  │   └── services/firebase_service.dart
  └── pubspec.yaml                 # Flutter dependencies
README.md
```

---

## 🔧 Setup & Installation

### 1. Arduino Setup
- Upload `sensor_monitor.ino` to your Arduino board using the Arduino IDE.
- Ensure correct COM port is selected.

### 2. Python Script
- Install dependencies:
  ```bash
  pip install pyserial firebase-admin
  ```
- Set up Firebase Admin SDK (`serviceAccountKey.json`).
- Run the script:
  ```bash
  python firebase_uploader.py
  ```

### 3. Flutter App
- Set up Flutter SDK: [https://flutter.dev/docs/get-started/install](https://flutter.dev/docs/get-started/install)
- Add `google-services.json` to `android/app/`.
- Install packages:
  ```bash
  flutter pub get
  ```
- Run the app:
  ```bash
  flutter run
  ```

---

## 📷 UI Preview

- **Temperature**: `28.1°C`
- **Humidity**: `68.1%`
- **Distance**: `16.0 cm`
- **Last Update**: `08 June 2025, 06:03:39`

---

## 📄 License

This project is licensed under the MIT License.

---

## 🤝 Contributions

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
