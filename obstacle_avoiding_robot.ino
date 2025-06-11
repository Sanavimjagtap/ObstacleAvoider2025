// Motor Driver Pins
const int IN1 = 2;   // Left Motor
const int IN2 = 3;
const int IN3 = 4;   // Right Motor
const int IN4 = 5;

// Enable Pins for Speed Control
const int ENA = 10;  // PWM pin for left motor
const int ENB = 11;  // PWM pin for right motor

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 8;

// Distance threshold in cm
const int distanceThreshold = 20;



void setup() {
  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start motors at set speed
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
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

  // Read echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < distanceThreshold) {
    // Obstacle detected - Turn Right
    turnRight();
    delay(300);
  } else {
    // No obstacle - Move Forward
    moveForward();
  }
}

void moveForward() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
