#ifndef ROBOTBASE_H
#define ROBOTBASE_H

#include <Servo.h>
#include <Arduino.h>

// Pin definitions
#define PINR 10
#define PINL 9
#define SensorPinL A2
#define SensorPinR A4

class RobotBase {
  private:
    Servo servo1; // Declare servo1 as a member variable
    Servo servo2; // Declare servo2 as a member variable
    const int sensorPin1;
    const int sensorPin2;

  public:
    RobotBase(int pin1, int pin2); // Constructor declaration
    void baseConnections();
    void MotorDrive();
};

#endif
