void turnLeft(){
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
}

void turnRight(){
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
}

void goStraight(){
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void stopMoving(){
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

  if (forwardMoves == 0) {
    stopMoving();
    Serial.println("Stopping, setting baselines");
    rightBaseline = analogRead(A0);
    leftBaseline = analogRead(A1);
  }

  else if (analogRead(A5) > 350) {
    Serial.println("IR block detected, stopping");
    stopMoving();
  }

  else if (220 < analogRead(A0) && analogRead(A0) < 225 && 220 < analogRead(A1) && analogRead(A1) < 225){
    Serial.println("Red tape detected, stopping");
    stopMoving();
  }

  else if (leftTurns >= 20 && rightTurns >= 20){ // Do a sharp turn: go forward, then hard turn
    Serial.println("Sharp right");
    if (firstTurn){ // Sharp right
      // Move forward until the sensor has cleared the line.
      Serial.println("Clear the tape");
      do {
        goStraight();
        delay(25);
        stopMoving();
        delay(50);
      } while (analogRead(A0) + 35 < rightBaseline);

      goStraight();
      delay(500); // this is a speed (and thus battery level) dependent setting that places the center of the car over the tape
      stopMoving();
      delay(50);

      // Turn until the sensor has passed over the entire line.
      Serial.println("Turn to find the tape");
      while (analogRead(A0) + 35 > rightBaseline){ // turn while sensor is on white until touching tape
        turnRight();
        delay(25);
        stopMoving();
        delay(50);
      }
      Serial.println("Turn over the tape");
      while (analogRead(A0) + 35 < rightBaseline){ // turn over the tape
        turnRight();
        delay(25);
        stopMoving();
        delay(50);
      }
    }

    else { // Sharp left
      Serial.println("Sharp left");
      // Move forward until the sensor has cleared the line.
      Serial.println("Clear the tape");
      do {
        goStraight();
        delay(25);
        stopMoving();
        delay(50);
      } while (analogRead(A1) + 35 < leftBaseline);

      goStraight();
      delay(500); // this is a speed (and thus battery level) dependent setting that places the center of the car over the tape
      stopMoving();
      delay(50);

      // Turn until the sensor has passed over the entire line.
      Serial.println("Turn to find the tape");
      while (analogRead(A1) + 35 > leftBaseline){ // turn while sensor is on white until touching tape
        turnLeft();
        delay(25);
        stopMoving();
        delay(50);
      }
      Serial.println("Turn over the tape");
      while (analogRead(A1) + 35 < leftBaseline){ // turn over the tape
        turnLeft();
        delay(25);
        stopMoving();
        delay(50);
      }
    }
    leftTurns = 0;
    rightTurns = 0;
  }

  else if (analogRead(A0) + 35 < rightBaseline) {
    Serial.println("Turn right");
    turnRight();
    if (leftTurns == 0 && rightTurns == 0){
      firstTurn = true;
    }
    forwardMoves = 0;
    rightTurns++;
  }

  else if (analogRead(A1) + 35 < leftBaseline) {
    Serial.println("Turn left");
    turnLeft();
    if (leftTurns == 0 && rightTurns == 0){
      firstTurn = false;
    }
    forwardMoves = 0;
    leftTurns++;
  }

  else {
    Serial.println("Go straight");
    goStraight();
    forwardMoves++;
  }

  delay(25);

  Serial.println("Stopping");
  stopMoving();

  delay(50);
}
