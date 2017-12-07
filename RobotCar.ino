void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

bool obstacle = false;

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(analogRead(A0));

  while (analogRead(A5) > 450) {
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    obstacle = true;
  }
 /* while (obstacle) {
    int beforeLeft = analogRead(A0);
    int beforeRight = analogRead(A1);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    delay(100);
    if (analogRead(A0) - beforeLeft > 10 || analogRead(A1) - beforeRight > 10) {
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      while(true)
      {
        delay(10000);
      }
    }
  }*/
  int RigthPSensorBefore = analogRead(A0);
  int LeftPSensorBefore = analogRead(A1);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  delay(50);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  int LeftPSensorAfter = analogRead(A0);
  int RightPSensorAfter = analogRead(A1);
  Serial.println(RightPSensorAfter - RigthPSensorBefore);

  if (RightPSensorAfter + 40 < RigthPSensorBefore) {
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
    delay(50);
    int counterRight = 0;
    while (analogRead(A1) + 40 < RigthPSensorBefore && counterRight < 3) {
      digitalWrite(4, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
      delay(50);
      Serial.println("1");
      Serial.println("2");
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      delay(500);
      counterRight = counterRight + 1;
      if (analogRead(A5) > 450)
        break;
    }
  } else if (LeftPSensorAfter + 15 < LeftPSensorBefore) {
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    delay(300);
    int counterLeft = 0;
    while (analogRead(A0) + 15 < LeftPSensorBefore && counterLeft < 3) {
      digitalWrite(4, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      Serial.println("1");
      Serial.println("2");
      delay(150);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      delay(500);
      counterLeft = counterLeft + 1;
      if (analogRead(A5) > 450)
        break;
    }
  } else {
    delay(500);
  }
}
