#include <Servo.h>
#include <Arduino.h>

// LEFT VALUE WHITE = 27
// RIGHT VALUE WHITE = 25
// LEFT VALUE BLACK = 46
// RIGHT VALUE BLACK = 41



#define PINR 10
#define PINL 9
#define SensorPinL A2
#define SensorPinR A4


// Define a threshold for analog sensor readings
const int THRESHOLD = 900; // Adjust this value based on your sensors and environment

class RobotBase {
  private:
    Servo servo1; // Declare servo1 as a member variable
    Servo servo2; // Declare servo2 as a member variable
    const int sensorPin1;
    const int sensorPin2;

  public:
    RobotBase(int pin1, int pin2) : sensorPin1(pin1), sensorPin2(pin2) {}

    void baseConnections() {
      pinMode(sensorPin1, INPUT);
      pinMode(sensorPin2, INPUT);
      servo1.attach(PINR, 700, 2300); // Attach the servo to pin 10
      servo2.attach(PINL, 700, 2300); // Attach the second servo to pin 9
    }

    void MotorDrive() {
      int LVAL = analogRead(sensorPin1); // Read analog value from left sensor
      int RVAL = analogRead(sensorPin2); // Read analog value from right sensor


      if (LVAL < 40 && RVAL < 40) {
        // Both sensors dont see the line
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
};

RobotBase sensor(SensorPinL, SensorPinR);

void setup() {
  sensor.baseConnections();
}

void loop() {
  sensor.MotorDrive();
}
