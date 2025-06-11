// Motor Pins
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 8;

// Distance threshold in centimeters
const int distanceThreshold = 20;

void setup() {
  // Motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start Serial Monitor (for debugging)
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Debug output
  Serial.print("Distance: ");
  Serial.println(distance);

  // Obstacle avoidance logic
  if (distance > 0 && distance < distanceThreshold) {
    stopMotors();
    delay(200);
    turnRight(); // You can change this to turnLeft() if needed
    delay(400);
  } else {
    moveForward();
  }

  delay(100);
}

// Move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn right (spin turn)
void turnRight() {
  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);   // Right motor reverse
  digitalWrite(IN4, LOW);
}

// Optional: Turn left (if you want it instead)
void turnLeft() {
  digitalWrite(IN1, LOW);   // Left motor reverse
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  // Right motor forward
  digitalWrite(IN4, HIGH  );
}

// Stop both motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
