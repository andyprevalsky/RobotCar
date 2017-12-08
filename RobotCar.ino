void turnLeft(){
  Serial.println("Turn left");
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
}

void turnRight(){
  Serial.println("Turn right");
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
}

void goStraight(){
  Serial.println("Go straight");
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void stopMoving(){
  Serial.println("Stop");
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

int baseline = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (baseline == 0) {
    Serial.println("Setting baseline");
    baseline = analogRead(A0);
  }

  else if (analogRead(A5) > 450) {
    Serial.println("IR block detected");
    stopMoving();
  }

  else if (220 < analogRead(A0) && analogRead(A0) < 240 && 220 < analogRead(A1) && analogRead(A1) < 240){
    Serial.println("Red tape detected");
    stopMoving();
  }

  else if (analogRead(A0) + 35 < baseline) {
    turnRight();
  }

  else if (analogRead(A1) + 35 < baseline) {
    turnLeft();
  }

  else {
    goStraight();
  }

  delay(25);

  stopMoving();

  delay(50);
}
