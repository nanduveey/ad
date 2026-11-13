#include <Servo.h>

Servo myServo;

const int irSensor = 2;
const int servoPin = 9;

int sensorValue;

void setup()
{
  pinMode(irSensor, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
  myServo.write(0);
}

void loop()
{
  sensorValue = digitalRead(irSensor);

  if (sensorValue == LOW)
  {
    myServo.write(90);
    Serial.println("Object Detected");
    Serial.println("Servo Angle: 90 Degree");
  }
  else
  {
    myServo.write(0);
    Serial.println("No Object Detected");
    Serial.println("Servo Angle: 0 Degree");
  }

  delay(500);
}
