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
  
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time from the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Calculate distance in cm
  
  // Output distance data to the serial monitor
  Serial.println(distance);
  
  // If an obstacle is within 30 cm, trigger the alert
  if (distance < 30) {
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    digitalWrite(vibrationPin, HIGH);  // Turn on the vibration motor
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    digitalWrite(vibrationPin, LOW);  // Turn off the vibration motor
  }
  
  delay(100);  // Wait for a short period before measuring again
}
