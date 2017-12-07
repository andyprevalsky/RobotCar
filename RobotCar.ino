

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
  int RigthPSensorBefore = analogRead(A0);
  int LeftPSensorBefore = analogRead(A1); //XX is pin connected to other photo resistor
  delay(100);
  int LeftPSensorAfter = analogRead(A0);
  int RightPSensorAfter = analogRead(A1);

  if (RightPSensorAfter + 30 < RigthPSensorBefore) {
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
    delay(900);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }

  if (LeftPSensorAfter + 30 < LeftPSensorBefore) {
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    delay(900);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}
