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

int rightBaseline = 0;
int leftBaseline = 0;
int forwardMoves = 0;
int leftTurns = 0;
int rightTurns = 0;
bool firstTurn = false; // false is left, true is right

// A0 is right photoresistor reading
// A1 is left photoresistor reading

void loop() {
  // put your main code here, to run repeatedly:
  if (forwardMoves > 6){
    leftTurns = 0;
    rightTurns = 0;
    forwardMoves = 0; // what does this line do?
  }

  if (forwardMoves = 0) {
    stopMoving();
    Serial.println("Setting baselines");
    rightBaseline = analogRead(A0);
    leftBaseline = analogRead(A1);
  }

  else if (analogRead(A5) > 450) {
    Serial.println("IR block detected");
    stopMoving();
  }

  else if (220 < analogRead(A0) && analogRead(A0) < 240 && 220 < analogRead(A1) && analogRead(A1) < 240){
    Serial.println("Red tape detected");
    stopMoving();
  }

  else if (leftTurns >= 20 && rightTurns >= 20){ // Do a sharp turn: go forward, then hard turn
    if (firstTurn){ // Sharp right
      // Move forward until the sensor has cleared the line.
      do {
        Serial.println("Sharp right");
        goStraight();
        delay(40);
        stopMoving();
        delay(50);
      } while (analogRead(A0) + 45 < rightBaseline);

      // Turn until the sensor has passed over the entire line.
      do {
        Serial.println("Sharp right");
        turnRight();
        delay(40);
        stopMoving();
        delay(50);
      } while (analogRead(A0) + 45 < rightBaseline);
    }

    else { // Sharp left
      // Move forward until the sensor has cleared the line.
      do {
        Serial.println("Sharp left");
        goStraight();
        delay(40);
        stopMoving();
        delay(50);
      } while (analogRead(A1) + 45 < leftBaseline);

      // Turn until the sensor has passed over the entire line.
      do {
        Serial.println("Sharp left");
        turnLeft();
        delay(40);
        stopMoving();
        delay(50);
      } while (analogRead(A1) + 45 < leftBaseline);
    }
    leftTurns = 0;
    rightTurns = 0;
  }

  else if (analogRead(A0) + 45 < rightBaseline) {
    turnRight();
    if (leftTurns == 0 && rightTurns == 0){
      firstTurn = true;
    }
    forwardMoves = 0;
    rightTurns++;
  }

  else if (analogRead(A1) + 45 < leftBaseline) {
    turnLeft();
    if (leftTurns == 0 && rightTurns == 0){
      firstTurn = false;
    }
    forwardMoves = 0;
    leftTurns++;
  }

  else {
    goStraight();
  }

  delay(40);

  stopMoving();

  delay(50);
}
