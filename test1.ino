#include <Servo.h>            //加载文件库
Servo myservo;


void setup() {
  // put your setup code here, to run once:
    myservo.attach(9);
    pinMode (13,OUTPUT);
    pinMode (2,OUTPUT);
    pinMode(3,OUTPUT);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (500);
  myservo.write(0);
  digitalWrite (13,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  delay(500);
  myservo.write(90);
  digitalWrite (13,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
}
