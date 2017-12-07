

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  //float voltage = sensorValue * (5.0 / 1023.0);
  // put your main code here, to run repeatedly:
  int RigthSensorBefore = analogRead(A0);
  delay(100);
  int RightSensorAfter = analogRead(A0);

  if (RightSensorAfter + 30 < RigthSensorBefore) {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    delay(900);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}
