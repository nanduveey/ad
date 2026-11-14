
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

Servo myServo;

long duration;
float distance;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    myServo.attach(servoPin);
    Serial.begin(9600);

    myServo.write(0);
}

void loop()
{
    // Generate ultrasonic trigger pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    // Measure echo duration
    duration = pulseIn(echoPin, HIGH, 30000);

    // Calculate distance
    if (duration == 0)
    {
        Serial.println("No object detected");
    }
    else
    {
        distance = duration * 0.0343 / 2;

        // Display distance
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // Control servo motor
        if (distance <= 20)
        {
            myServo.write(90);
            Serial.println("Object detected - Servo at 90 degrees");
        }
        else
        {
            myServo.write(0);
            Serial.println("Object far - Servo at 0 degrees");
        }
    }

    delay(500);
}
