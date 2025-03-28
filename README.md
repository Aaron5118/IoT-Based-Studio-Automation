# IoT-Based-Studio-Automation


## Overview
The Studio Automation System is designed to automate lighting and motion-based control using an Arduino. This project integrates a PIR motion sensor, a servo motor, and an LED system to enhance the automation of a studio environment. The system operates based on motion detection and user input via serial communication.

## Features
- **Motion Detection:** Uses a PIR sensor to detect movement.
- **Servo Motor Control:** Moves a servo motor based on motion detection.
- **LED Control:** Allows turning an LED on or off via serial commands.
- **Serial Communication:** Enables remote control of LED status through commands ('1' to turn ON, '0' to turn OFF).

## Components Used
- Arduino Board
- PIR Motion Sensor
- Servo Motor
- LED
- Resistors and connecting wires

## Installation and Setup
1. Connect the components to the Arduino as per the wiring diagram:
   - PIR sensor to digital pin 7
   - Servo motor to digital pin 8
   - LED to digital pin 3 (with a resistor in series)
2. Upload the provided Arduino code to the board.
3. Open the Serial Monitor in the Arduino IDE to control the LED.
4. Observe the servo movement in response to motion detection.

## Code Explanation
The system consists of two main functions:
- **ledLoop():**
  - Reads input from the serial monitor.
  - Turns the LED ON ('1') or OFF ('0').
- **motorLoop():**
  - Reads the PIR sensor state.
  - Moves the servo to 180 degrees when motion is detected and resets to 0 degrees otherwise.

### Code Snippet
```cpp
#include <Servo.h>

Servo myservo;
int pir = 7;
int ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(pir, INPUT);
  myservo.attach(8);
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
  Serial.println(motionDetected);
  if (motionDetected == HIGH) {
    myservo.write(180);
    delay(1000);
  } else {
    myservo.write(0);
  }
  delay(100);
}

void loop() {
  ledLoop();
  motorLoop();
}
```

## How to Use
1. **Turn the LED On/Off:**
   - Open the Serial Monitor in the Arduino IDE.
   - Enter '1' to turn on the LED.
   - Enter '0' to turn off the LED.
2. **Motion Detection & Servo Movement:**
   - The servo motor moves when motion is detected by the PIR sensor.
   - If motion is detected, the servo moves to 180°; otherwise, it returns to 0°.

## Future Enhancements
- Adding a buzzer for audio alerts.
- Integration with IoT platforms for remote monitoring.
- Adding a mobile application for better control.

## Conclusion
The Studio Automation System is a simple yet effective automation solution for controlling lights and motion-based actions in a studio setup. This project demonstrates fundamental automation concepts using Arduino.

## Author
**Aaron Cardozo**

---
### License
This project is licensed under the ISC License.

