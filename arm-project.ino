// demo code which takes input from rotary encoder and outputs to servo
#include <Servo.h>
Servo base;

const int CLK = 2; // encoder pin A
const int DT = 3; // encoder pin B

int counter = 90; // initial position at 90 degrees

int currStateCLK; // current state of A
int lastStateCLK; // last state of A
int servoPos = 90;

void setup() {
  // put your setup code here, to run once:
  pinMode(CLK, INPUT); // set pin as input
  pinMode(DT, INPUT); // set pin as input
  // unecessary
  Serial.begin(9600); // open serial channel

  base.attach(9); // attach servo to pin 9
  base.write(servoPos); // set initial angle of servo

  lastStateCLK = digitalRead(CLK);
}

// if 1 -> steps 5
// if 0 -> nothing
void loop() {
  currStateCLK = digitalRead(CLK); // set curr as actual current position

  if (currStateCLK != lastStateCLK && currStateCLK == 1) { 
    if (digitalRead(DT) != currStateCLK) {
      counter -= 5; // decrement by 5
    } else { 
      counter += 5; // increment by 5
    }

    servoPos = constrain(counter, 0, 180); 
    base.write(servoPos); 
    // unecessary
    Serial.print("Servo Angle: "); // display servo's angle
    Serial.println(servoPos); // display servo's angle
  }

  lastStateCLK = currStateCLK; // set equal to show they haven't moved
}


