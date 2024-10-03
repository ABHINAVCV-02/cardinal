// Define pins for the ultrasonic sensor
const int trigPin = 7;  // Trigger pin
const int echoPin = 6;  // Echo pin

void setup() {
  // Start the Serial communication
  Serial.begin(9600);
  
  // Set the trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  
  // Set the echo pin as an INPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  // Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigger to HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin, duration is the time it takes for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm (speed of sound is 340 m/s or 29 microseconds per cm)
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Depth ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait a short time before the next measurement
  delay(500);
}
