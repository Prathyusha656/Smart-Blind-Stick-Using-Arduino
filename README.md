# Smart Blind Stick Using Arduino
## 📌 Introduction
The Smart Blind Stick is a low-cost, easy-to-build assistive device designed for visually impaired individuals. It helps detect obstacles in their path and provides alerts through vibrations and a buzzer, ensuring a safer and more independent movement.

This project is powered by an Arduino Nano and utilizes an ultrasonic sensor to measure the distance to nearby objects. If an obstacle is detected within a predefined range, the system activates the buzzer and vibration motor to alert the user.

## 🎯 Features
✅ Obstacle Detection – Uses an ultrasonic sensor to detect objects in the user’s path.
✅ Dual Alert System – Provides both vibration feedback and sound alerts.
✅ Compact & Lightweight – Can be attached to a walking stick for easy use.
✅ Adjustable Sensitivity – Distance threshold can be customized in the code.
✅ Low Power Consumption – Runs on a small battery for extended use.
✅ Affordable & Easy to Build – Uses common components and is ideal for DIY projects.

## 🔧 Components Required
Component	Specification	Quantity
Arduino Nano	Microcontroller	1
Ultrasonic Sensor (HC-SR04)	Distance measurement	1
Buzzer	Piezoelectric	1
Vibration Motor	Small DC motor	1
Battery	9V / Li-ion	1
Jumper Wires	Male-to-Female	As needed
Resistors	1KΩ (if needed)	1
## 📜 Working Principle
Distance Measurement

The HC-SR04 ultrasonic sensor sends out an ultrasonic wave.
The wave bounces off nearby obstacles and returns to the sensor.
The sensor calculates the distance based on the time taken for the wave to return.
Obstacle Detection & Alert

If an obstacle is detected within 30 cm, the buzzer and vibration motor are activated.
If the obstacle is farther than 30 cm, the alerts remain off.
## ⚡ Circuit Diagram
Wiring Connections
Component	Arduino Pin
Ultrasonic Sensor - VCC	5V
Ultrasonic Sensor - GND	GND
Ultrasonic Sensor - Trigger	D9
Ultrasonic Sensor - Echo	D10
Buzzer +ve	D3
Buzzer -ve	GND
Vibration Motor +ve	D4
Vibration Motor -ve	GND
📌 Tip: If you are using a high-power vibration motor, connect it through a transistor circuit.

![Circuit Diagram](/images/circuit.jpeg)


## 🖥️ Arduino Code
This Arduino sketch reads distance data from the ultrasonic sensor and activates the buzzer and vibration motor when an obstacle is detected within 30 cm.

#define trigPin 9
#define echoPin 10
#define buzzerPin 3
#define vibrationPin 4

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  long duration;
  int distance;
  
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure time taken for the pulse to return
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm
  
  Serial.println(distance);  // Debug output
  
  if (distance > 0 && distance < 30) {  // If obstacle is within 30cm
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(vibrationPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrationPin, LOW);
  }
  
  delay(100);
}
## 🔬 How to Use
Assemble the circuit as per the diagram.
Upload the code to the Arduino Nano using the Arduino IDE.
Power the system using a 9V battery or a rechargeable Li-ion battery.
Test the stick by placing objects in front of the sensor at different distances.
Fine-tune the code to adjust the sensitivity of obstacle detection.
🔧 Troubleshooting Guide
Issue	Possible Cause	Solution
No alerts	Wiring issue, incorrect pins	Check connections, verify code
False alarms	Interference, sensor angle	Adjust sensor position
Low vibration	Weak motor power	Use a transistor for power boost
No sound from buzzer	Buzzer failure	Test buzzer separately

## 🚀 Future Enhancements
✅ 360° Obstacle Detection – Add multiple ultrasonic sensors for detecting obstacles from all sides.
✅ Bluetooth Connectivity – Connect to a smartphone for additional accessibility options.
✅ GPS Integration – Provide location tracking and emergency alert features.
✅ Rechargeable Battery – Use a solar panel or USB charging to extend battery life.
✅ Voice Alerts – Implement a voice module to give audio cues instead of buzzer sounds.

##📸 Project Images

## Circuit Diagram
![Circuit Diagram](/images/image.jpg)

