# 🔒 Behavior-Based Intrusion Detection for Industrial Gateways Using a Smart Meter Prototype

## 📌 Overview

This project demonstrates a behavior-based intrusion detection system for Industrial IoT gateways using a Smart Meter prototype. Instead of relying only on traditional firewalls or signature-based detection, the system identifies abnormal behavior by monitoring changes in simulated energy consumption and unauthorized physical access.

A Smart Meter is used as a real-time implementation platform to simulate Industrial IoT gateway behavior.

---

## 🎯 Problem Statement

Traditional firewalls cannot detect modern IoT malware that mimics legitimate network traffic. Existing security systems mainly detect known attacks and fail to recognize new or behavior-based threats.

This project addresses that limitation by monitoring system behavior and detecting anomalies based on sudden changes in sensor readings and unauthorized access.

---

## 🎯 Objectives

- Simulate Industrial IoT gateway behavior using a Smart Meter.
- Detect abnormal behavior in real time.
- Differentiate between Normal, Anomaly, and Intrusion conditions.
- Provide visual and audio alerts.
- Demonstrate a low-cost IoT security solution.

---

## 🛠 Hardware Components

- Arduino Uno R4 WiFi
- 16x2 LCD with I2C Module
- PIR Motion Sensor
- Potentiometer
- Push Buttons
- Relay Module
- Green LED
- Red LED
- Active Buzzer
- Breadboard
- Jumper Wires

---

## 💻 Software Used

- Arduino IDE
- Embedded C++
- LiquidCrystal_I2C Library
- Serial Monitor

---

## ⚙ Working Principle

1. Potentiometer simulates smart meter readings.
2. Push buttons simulate different power usage levels.
3. PIR sensor detects unauthorized access.
4. Arduino continuously monitors behavior.
5. If readings remain within the threshold:
   - Green LED ON
   - LCD displays NORMAL
6. If sudden changes occur:
   - Red LED ON
   - Buzzer activates
   - LCD displays ANOMALY DETECTED
7. PIR activation triggers an INTRUSION alert.

---

## 📊 Features

- Real-time anomaly detection
- Intrusion detection using PIR
- LCD status monitoring
- LED status indication
- Audible buzzer alert
- Relay control
- Serial Monitor logging

---

## 📷 Hardware Prototype

(Add your project image here)

---

## 📈 Results

| Condition | Smart Meter Reading | System Status | Alert |
|------------|--------------------|---------------|-------|
| Normal | Stable | NORMAL | No |
| Sudden Increase | Large Change | ANOMALY DETECTED | Yes |
| PIR Triggered | Motion Detected | INTRUSION | Yes |

---

## 🚀 Future Enhancements

- Machine Learning based anomaly detection
- Blynk Integration
- ThingSpeak Cloud Monitoring
- Email/SMS Alerts
- Real Smart Meter Integration

---

## 👨‍💻 Team Members

- Your Name
- Member 2
- Member 3

---

## 📜 License

This project is developed for academic and educational purposes.
