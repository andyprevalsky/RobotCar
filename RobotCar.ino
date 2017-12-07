void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

bool obstacle = false;
bool start = true;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));

  if (analogRead(A5) > 450) {
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }

  if (baseline == 0) {
    baseline = analogRead(A0)
  }

  else if (analogRead(A0) + 30 < baseline && analogRead(A1) + 30 < baseline){
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }

  else if (analogRead(A0) + 40 < baseline) {
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
  }

  else if (analogRead(A1) + 40 < baseline) {
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
  }

  else {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }

  delay(500);

  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}
