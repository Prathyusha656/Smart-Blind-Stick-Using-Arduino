# Smart Blind Stick Using Arduino

## Overview
The Smart Blind Stick uses an ultrasonic sensor to detect obstacles and alerts the user using a buzzer and vibration motor. It is a mobility aid for the visually impaired and an excellent learning project for robotics.

## Components
- Arduino Nano
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- Vibration Motor
- 9V Battery or Li-ion Battery
- Jumper Wires

## Circuit Diagram
![Circuit Diagram](/images/circuit.jpeg)

## Code
```cpp
#define trigPin 9
#define echoPin 10
#define buzzerPin 3
#define vibrationPin 4

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.println(distance);
  
  if (distance < 30) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(vibrationPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrationPin, LOW);
  }
  
  delay(100);
}
