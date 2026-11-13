#define IR_SENSOR A2

void setup() {
  Serial.begin(9600);
  Serial.println("IR Sensor Test Started...");
}

void loop() {
  int sensorValue = analogRead(IR_SENSOR);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  delay(500);
}
