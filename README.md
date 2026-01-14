# Digispark → Heltec WiFi LoRa 32 Reset Interface via PC817 Optocoupler

This project demonstrates how to use a **PC817 optocoupler** to safely trigger a **reset signal** on a Heltec WiFi LoRa 32 (ESP32) board, controlled by a **Digispark (ATtiny85)**.  
Both devices share the same battery power source, and the PC817 provides logical isolation and level adaptation between 5 V and 3.3 V logic.

![Circuit Diagram](/res/schematic.jpg)

[![Demo video](/res/vid_preview.JPG)](https://youtu.be/a9msRpQNriQ?si=zAMqpEiD6hS0AUDT)

<a href="https://youtu.be/a9msRpQNriQ?si=zAMqpEiD6hS0AUDT" target="_blank">DEMONSTRATION VIDEO</a>

![Example 1](/res/example1.jpg)
![Example 2](/res/example2.jpg)
![Example 3](/res/example3.jpg)

---

## 🧩 Overview

The Digispark sends a digital signal to the PC817’s internal LED through a 470 Ω resistor.  
When the LED inside the optocoupler turns ON, the phototransistor on the output side pulls the **RESET** pin of the Heltec board LOW, effectively performing a hardware reset.

This setup is useful when the Heltec board needs to be remotely reset or restarted under program control from the Digispark.

---

## ⚙️ Circuit Description

### Components
| Component | Description |
|------------|-------------|
| **Digispark (ATtiny85)** | Microcontroller board, 5 V logic |
| **Heltec WiFi LoRa 32 V3** | ESP32-based board, 3.3 V logic |
| **PC817** | Optocoupler (LED + phototransistor) |
| **470 Ω resistor** | Current-limiting resistor for the optocoupler LED |
| **Battery** | Shared power source for both boards |

### Connections

| PC817 Pin | Function | Connected To |
|------------|-----------|---------------|
| **1 (Anode)** | Input LED (+) | Digispark pin P0 through 470 Ω resistor |
| **2 (Cathode)** | Input LED (–) | GND (shared) |
| **3 (Emitter)** | Output transistor | GND (Heltec side) |
| **4 (Collector)** | Output transistor | Heltec RESET pin |

---

## 🔌 Power Configuration

Both the Digispark and the Heltec board are powered by the same **battery**.  
Since they share the same GND, there is **no galvanic isolation**, but the PC817 still protects the Heltec from 5 V logic and provides electrical buffering.

---

## 🧠 Working Principle

1. `digitalWrite(P0, HIGH)` on the Digispark → drives 8 mA into the optocoupler LED.  
2. The LED light activates the phototransistor, connecting the Heltec RESET pin to GND.  
3. The Heltec detects a LOW on RESET → board resets.  
4. When the Digispark output returns LOW → the transistor turns OFF → Heltec resumes normal operation.

---

