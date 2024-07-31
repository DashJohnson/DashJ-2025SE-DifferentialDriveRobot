#include <Servo.h>
#include <Arduino.h>
//written by Dash Johnson
const int SensorPin2 = 4;//define sensorpin as a constant
const int SensorPin1 = 3;// define sensorpin as a constant
int value;
const unsigned int DegreeOfMovement = (180);


class RobotBase {
  private:
  Servo servo2;//declare servo2 as a member variable
  Servo servo1;//declare servo1 as a member variable
  const int sensorPin1;
  const int sensorPin2;
  public:
  // Constructor with sensor pin argument
   RobotBase(int pin1, int pin2) : sensorPin1(pin1), sensorPin2(pin2) {}


  void baseConnections() {
    pinMode(sensorPin1, INPUT);
    pinMode(sensorPin2, INPUT);
    servo1.attach(9);//attaching the servo to pin 9
    servo2.attach(11);// setting the pins 1 space apart to avoid noise and interference
    }
  void MotorDrive() {
    
    int value1 = digitalRead(sensorPin2);//reading the value derrived from the secondary sensor aswell
    int value2 = digitalRead(sensorPin1);//reading the value derrived from sensor
    
    
    if (value1 == HIGH && value2 == HIGH) {
    servo1.write(DegreeOfMovement);
    servo2.write(DegreeOfMovement);
    delay(200);
    } else if (value1 == LOW && value2 == LOW) {
      servo1.write(0);
      servo2.write(0);
      delay(200);
    } else if (value1 == LOW && value2 == HIGH) {
      servo1.write(0);
      servo2.write(DegreeOfMovement);
      delay(200);
    } else if (value1 == HIGH && value2 == LOW) {
      servo1.write(DegreeOfMovement);
      servo2.write(0);
      delay(200);
    }

  }

};


RobotBase sensor(SensorPin1, SensorPin2);

void setup() {
  sensor.baseConnections(); // Initialize the sensor
}

void loop() {
  sensor.MotorDrive(); // Check the line sensor and drive the motor accordingly
}