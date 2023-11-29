#include "Arduino.h"
#include <HardwareSerial.h>
int in1 = 2;
int in2 = 4;
int inA = 3;

int in3 = 5;
int in4 = 7;
int inB = 6;

void left(int time)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(inA, 100);
  digitalWrite(inB, 100);
  delay(time);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(inA, 100);
  digitalWrite(inB, 100);
  Serial.write("left\n");
}

void right(int time)
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(inA, 100);
    digitalWrite(inB, 100);
    delay(time);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(inA, 100);
    digitalWrite(inB, 100);
    Serial.write("right\n");
}

void move(int time)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(inA, 100);
  digitalWrite(inB, 100);
  delay(time);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(inA, 100);
  digitalWrite(inB, 100);
  Serial.write("move\n");
}

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(inA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(inB, OUTPUT);
  digitalWrite(in1, LOW);//initialize
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(inA, 100);
  digitalWrite(inB, 100);
}
void loop(){
  while(Serial.available() > 0)//detect sighal
  {
    
    if(Serial.read() == '1')//input "1" ,move
      move(1000);//move
    else if(Serial.read() == '2')//input "2",left
      left(1000);//left
    else if(Serial.read() == '3')//input "3",right
      right(1000);//right
    else Serial.write("error\n");//input other words,error
  }
  //Serial.write("no Signal\n");
  delay(50);
}

/*
input "1",move
input "2",left
input "3",right
input other words,error
*/