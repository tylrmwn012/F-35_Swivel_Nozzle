// this is my initial ARM project
#include <Servo.h>

Servo shoulderOne;
Servo shoulderTwo;
Servo elbow;
Servo wristOne;
Servo wristTwo;
Servo gripper;

void setup() {
  Serial.begin(9600);

  shoulderOne.attach(9);
  shoulderTwo.attach(8);
  elbow.attach(7);
  wristOne.attach(6);
  wristTwo.attach(5);
  gripper.attach(4);
}

void loop() {
  int shoulderValue = analogRead(A1);
  int elbowValue = analogRead(A2);
  int wristOneValue = analogRead(A3);
  int wristTwoValue = analogRead(A4);
  int gripperValue = analogRead(A5);

  shoulderOne.write((shoulderValue * 180 + 511) / 1023);
  shoulderTwo.write(-(shoulderValue * 180 + 511) / 1023);
  elbow.write((elbowValue * 180 + 511) / 1023);
  wristOne.write((wristOneValue * 180 + 511) / 1023);
  wristTwo.write((wristTwoValue * 180 + 511) / 1023);
  gripper.write((gripperValue * 180 + 511) / 1023);
  delay(1);
}