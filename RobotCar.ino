void setup() {
  Serial.begin(9600);
  pinMode(P2_2, OUTPUT);
  pinMode(P3_0, OUTPUT);
  pinMode(P3_3, OUTPUT);
  pinMode(P6_6, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
   digitalWrite(P2_2, HIGH);
   digitalWrite(P3_3, HIGH);
   digitalWrite(P3_0, LOW);
   digitalWrite(P6_6, LOW);
  // put your main code here, to run repeatedly: 
  
}
