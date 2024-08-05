#include <Arduino.h>
#include <Servo.h>
#include "Sensor.h"

class SERVOMOVE {
  private:
    Servo servo1;
    Servo servo2;
    static const unsigned MovementDegree = 90;

  public:
    void Servo_Connections() {
      servo1.attach(9);
      servo2.attach(10);
    }

    void MoveServoFowards(int value1, int value2) {
      if (value1 == 1 && value2 == 1) {
        servo1.write(0);
        servo2.write(0);
        delay(250);
        servo1.write(MovementDegree);
        servo2.write(MovementDegree);
      }
    }

    void STOP(int value1, int value2) {
      if (value1 == 0 && value2 == 0) {
        servo1.write(0);
        servo2.write(0);
        delay(250);
      }
    }
    
    void TURNLEFT(int value1, int value2) {
      if (value1 == 0 && value2 == 1) {
      servo1.write(0);
      servo2.write(0);
      delay(250);
      servo1.write(MovementDegree);
      servo2.write(0);
      }
    } 
       
    void TURNRIGHT(int value1, int value2) {
      if (value1 == 1 && value2 == 0) {
      servo1.write(0);
      servo2.write(0);
      delay(250);
      servo1.write(0);
      servo2.write(MovementDegree);
    }


      }
    
};

// Instantiate the classes
Interpreting_data sensor;
SERVOMOVE servos;

void setup() {
  sensor.BaseConnectionSensor();
  servos.Servo_Connections();
}

void loop() {
  sensor.Reading_Data();
  servos.MoveServoFowards(sensor.value1, sensor.value2);
  servos.STOP(sensor.value1, sensor.value2);
  servos.TURNLEFT(sensor.value1, sensor.value2);
  servos.TURNRIGHT(sensor.value1, sensor.value2);
  delay(100); // Add some delay to avoid rapid polling
}