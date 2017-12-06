void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  delay(100);
  Serial.println(sensorValue);

  if (sensorValue < 120) {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}
