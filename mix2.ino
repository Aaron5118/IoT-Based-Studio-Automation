#include <Servo.h>

Servo myservo;
int pir = 7;          // Digital pin for PIR motion sensor
int ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(pir, INPUT);
  myservo.attach(8);  // Digital pin for servo motor
}

void ledLoop() {
  while (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED turned on");
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned off");
    }
  }
}

void motorLoop() {
  int motionDetected = digitalRead(pir);
  Serial.println(motionDetected);  // Print PIR sensor state

  if (motionDetected == HIGH) {
    myservo.write(180);  // Move servo to 180 degrees when motion is detected
    delay(1000);         // Keep position for 1 second
  } else {
    myservo.write(0);    // Move servo back to 0 degrees when no motion is detected
  }

  delay(100);  // Short delay to stabilize sensor readings
}

void loop() {
  ledLoop();   // Check for LED control commands via Serial
  motorLoop(); // Check for motion and control the servo
}
