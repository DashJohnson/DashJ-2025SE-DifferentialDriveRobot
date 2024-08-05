
const int SensorPin1 = 11;
const int SensorPin2 = 12;

class Interpreting_data {
  private:
  public:
  int value1;
  int value2;

  void BaseConnectionSensor() {
    pinMode(SensorPin1, INPUT);
    pinMode(SensorPin2, INPUT);
  }

  void Reading_Data() {
    value1 = digitalRead(SensorPin1);
    value2 = digitalRead(SensorPin2);
  }


};