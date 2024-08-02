#include <Servo.h>
#include <Arduino.h>
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

int br=115200;
int dt=10;


const int SensorPin2 = 4; // Define sensor pins as constants
const int SensorPin1 = 3;
const unsigned int DegreeOfMovement = 90;

byte frame1[8][12] = {
  {1,0,0,0,1,1,1,1},
  {1,1,0,0,0,0,1,0},
  {1,0,1,0,0,0,1,0},
  {1,0,1,0,0,0,1,0},
  {1,0,1,0,0,0,1,0},
  {1,0,1,0,0,0,1,0},
  {1,1,0,0,0,1,0,0},
  {1,0,0,0,1,0,0,0}
};
byte frame2[8][12] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};
byte frame3[8][12] = {
  {1,1,1,1,1,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0}
};
byte frame4[8][12] = {
  {1,1,1,1,1,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,1,1,1,0,0,0,0}
};
byte frame5[8][12] = {
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,0,0}
};
byte frame6[8][12] = {
  {1,1,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0},
  {1,0,1,0,0,0,0,0},
  {1,1,0,0,0,0,0,0},
  {1,0,1,0,0,0,0,0},
  {1,0,1,0,0,0,0,0},
  {1,0,1,0,0,0,0,0},
  {1,0,1,0,0,0,0,0}
};


class RobotBase {
  private:
    Servo servo2; // Declare servo2 as a member variable
    Servo servo1; // Declare servo1 as a member variable
    const int sensorPin1;
    const int sensorPin2;

  public:
    // Constructor with sensor pin arguments
    RobotBase(int pin1, int pin2) : sensorPin1(pin1), sensorPin2(pin2) {}

    void LED_MATRIX() {
      Serial.begin(br);
      matrix.begin();
      delay(dt);
      matrix.renderBitmap(frame1,8,12);
    }

    void baseConnections() {
      pinMode(sensorPin1, INPUT);
      pinMode(sensorPin2, INPUT);
      servo1.attach(9); // Attach the servo to pin 9
      servo2.attach(11); // Attach the second servo to pin 11
    }

    void MotorDrive() {
      int value1 = digitalRead(sensorPin2); // Read the value from the secondary sensor
      int value2 = digitalRead(sensorPin1); // Read the value from the primary sensor

      if (value1 == HIGH && value2 == HIGH) {
        servo1.write(DegreeOfMovement);
        servo2.write(DegreeOfMovement);
        delay(500);
        matrix.renderBitmap(frame2,8,12);
      } else if (value1 == LOW && value2 == LOW) {
        servo1.write(0);
        servo2.write(0);
        delay(500);
        matrix.renderBitmap(frame3,8,12);
      } else if (value1 == LOW && value2 == HIGH) {
        servo1.write(0);
        servo2.write(DegreeOfMovement);
        delay(500);
        matrix.renderBitmap(frame4,8,12);
      } else if (value1 == HIGH && value2 == LOW) {
        servo1.write(DegreeOfMovement);
        servo2.write(0);
        delay(500);
        matrix.renderBitmap(frame5,8,12);
      }
      delay(200);
    }

};

RobotBase sensor(SensorPin1, SensorPin2);

void setup() {
  sensor.baseConnections(); // Initialize the sensor
}

void loop() {
  sensor.MotorDrive(); // Check the line sensor and drive the motor accordingly
}
