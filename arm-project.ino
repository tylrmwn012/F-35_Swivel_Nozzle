#include <Servo.h>
Servo serOne;
Servo serTwo;
Servo serThree;

const int CLKone = 13; // encoder pin A
const int DTone = 12; // encoder pin B

const int CLKtwo = 11; // encoder pin A
const int DTtwo = 10; // encoder pin B

const int CLKthree = 9; // encoder pin A
const int DTthree = 8; // encoder pin B

int counterOne = 90; // initial position at 90 degrees
int counterTwo = 90; // initial position at 90 degrees
int counterThree = 90; // initial position at 90 degrees

int currStateCLKone; // current state of A
int lastStateCLKone; // last state of A
int servoPosOne = 90;

int currStateCLKtwo; // current state of A
int lastStateCLKtwo; // last state of A
int servoPosTwo = 90;

int currStateCLKthree; // current state of A
int lastStateCLKthree; // last state of A
int servoPosThree = 90;

void setup() {
// rotary encoders
  // one
  pinMode(CLKone, INPUT); // set pin as input
  pinMode(DTone, INPUT); // set pin as input

  // two
  pinMode(CLKtwo, INPUT); // set pin as input
  pinMode(DTtwo, INPUT); // set pin as input

  // three
  pinMode(CLKthree, INPUT); // set pin as input
  pinMode(DTthree, INPUT); // set pin as input

// servos
  serOne.attach(7); // attach servo to pin 9
  serOne.write(servoPosOne); // set initial angle of servo

  serTwo.attach(6); // attach servo to pin 9
  serTwo.write(servoPosTwo); // set initial angle of servo

  serThree.attach(5); // attach servo to pin 9
  serThree.write(servoPosThree); // set initial angle of servo

  lastStateCLKone = digitalRead(CLKone);
  lastStateCLKtwo = digitalRead(CLKtwo);
  lastStateCLKthree = digitalRead(CLKthree);

}

void state(int &currStateCLK, int &lastStateCLK, int CLK, int DT, int &counter, int &servoPos, Servo &servo) {
  currStateCLK = digitalRead(CLK); // set curr as actual current position

  if (currStateCLK != lastStateCLK && currStateCLK == 1) { 
    if (digitalRead(DT) != currStateCLK) {
      counter -= 5; // decrement by 5
    } else { 
      counter += 5; // increment by 5
    }

    servoPos = constrain(counter, 0, 180); 
    serOne.write(servoPos); 
  }

  lastStateCLK = currStateCLK; // set equal to show they haven't moved
}

void loop() {
  // one
  state(currStateCLKone, lastStateCLKone, CLKone, DTone, counterOne, servoPosOne, serOne);

  // two
  state(currStateCLKtwo, lastStateCLKtwo, CLKtwo, DTtwo, counterTwo, servoPosTwo, serTwo);

  // three
  state(currStateCLKthree, lastStateCLKthree, CLKthree, DTthree, counterThree, servoPosThree, serThree);
}


