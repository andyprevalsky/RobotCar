#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 50

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void insert(int data) {

   if(!isFull()) {
  
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];
  
   if(front == MAX) {
      front = 0;
   }
  
   itemCount--;
   return data;  
}


int intArray1[MAX];
int front1 = 0;
int rear1 = -1;
int itemCount1 = 0;

int peek1() {
   return intArray1[front1];
}

bool isEmpty1() {
   return itemCount1 == 0;
}

bool isFull1() {
   return itemCount1 == MAX;
}

int size1() {
   return itemCount1;
}  

void insert1(int data1) {

   if(!isFull1()) {
  
      if(rear1 == MAX-1) {
         rear1 = -1;            
      }       

      intArray1[++rear1] = data1;
      itemCount1++;
   }
}

int removeData1() {
   int data1 = intArray1[front1++];
  
   if(front1 == MAX) {
      front1 = 0;
   }
  
   itemCount1--;
   return data1;  
}

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
  /*int FrontIRSensor = analogRead(XX)
  if (FrontIRSensor < XX) {
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }*/
  Serial.println(analogRead(A0));

  int sum = 0;
  for(int i = 0; i < size(); i++){
    sum += intArray[i];
  }

  float mean = (float)sum / size();

  float sum1 = 0;
  for(int i = 0; i < size(); i++){
    sum1 += powf(intArray[i] - mean, 2); //(intArray[i] - mean)**2;
  }

  float mean1 = sum1 / size(); // mean1 is the variance

  float deviation = sqrt(mean1); // deviation is standard deviation

  if(size() == 50){
    if(abs(analogRead(A0) - mean) > deviation){
      if(analogRead(A0) < mean){ // ran into black tape
        digitalWrite(4, LOW); // turn right
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        delay(100);
      }
      else if(analogRead(A0) > mean){
        digitalWrite(4, HIGH); // go straight
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
      }
    }
  
    else if(abs(analogRead(A1) - mean) > deviation){
      if(analogRead(A1) < mean){ // ran into black tape
        digitalWrite(4, HIGH); // turn left
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(100);
      }
      else if(analogRead(A1) > mean){
        digitalWrite(4, HIGH); // go straight
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
      }
    }
  
    else{
      digitalWrite(4, HIGH); // go straight
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
  
    removeData();
  }
  insert(analogRead(A0));

  //digitalWrite(4, LOW);
  //digitalWrite(6, LOW);
  //digitalWrite(5, LOW);
  //digitalWrite(7, LOW);
}
