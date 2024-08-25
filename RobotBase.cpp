#include "RobotBase.h"

// Constructor definition
RobotBase::RobotBase(int pin1, int pin2) : sensorPin1(pin1), sensorPin2(pin2) {}

// Initializes pins and attaches servos
void RobotBase::baseConnections() {
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  servo1.attach(PINR, 700, 2300); // Attach the servo to pin 10
  servo2.attach(PINL, 700, 2300); // Attach the second servo to pin 9
}

// Controls the motors based on sensor readings
void RobotBase::MotorDrive() {
  int LVAL = analogRead(sensorPin1); // Read analog value from left sensor
  int RVAL = analogRead(sensorPin2); // Read analog value from right sensor

  if (LVAL < 40 && RVAL < 40) {
    // Both sensors don't see the line
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(1500);
  } else if (LVAL >= 40 && RVAL < 40) {
    // Left sensor does not see the line, right sensor does
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(2300);
  } else if (LVAL < 40 && RVAL >= 41) {
    // Left sensor does not see the line, right sensor does
    servo1.writeMicroseconds(700);
    servo2.writeMicroseconds(1500);
  } else if (LVAL >= 40 && LVAL >= 41) {
    // Both sensors see the line
    servo1.writeMicroseconds(700);
    servo2.writeMicroseconds(2300);
  } else if (LVAL > 100 && RVAL > 100) {
    servo1.write(1500);
    servo2.write(1500);
    delay(100);
  }

  delay(100); // Adjust delay as needed
}
