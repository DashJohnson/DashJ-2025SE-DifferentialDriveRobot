#include "RobotBase.h"

// Create an instance of the RobotBase class
RobotBase sensor(SensorPinL, SensorPinR);

void setup() {
  sensor.baseConnections();
}

void loop() {
  sensor.MotorDrive();
}
