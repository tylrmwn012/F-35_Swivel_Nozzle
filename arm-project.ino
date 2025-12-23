#include <Servo.h>
Servo serOne, serTwo, serThree;

// rotary encoder one
const int CLKone = 13, DTone = 12; 

int currStateCLKone, lastStateCLKone; 
int servoPosOne = 90;

// rotary encoder two
const int CLKtwo = 11, DTtwo = 10; 

int currStateCLKtwo, lastStateCLKtwo; 
int servoPosTwo = 90;

// rotary encoder three
const int CLKthree = 9, DTthree = 8; 

int currStateCLKthree, lastStateCLKthree;
int servoPosThree = 90;

// counters
int counterOne = 90, counterTwo = 90, counterThree = 90; 

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
  // Servo One State
  state(currStateCLKone, lastStateCLKone, CLKone, DTone, counterOne, servoPosOne, serOne);

  // Servo Two State
  state(currStateCLKtwo, lastStateCLKtwo, CLKtwo, DTtwo, counterTwo, servoPosTwo, serTwo);

  // Servo Three State
  state(currStateCLKthree, lastStateCLKthree, CLKthree, DTthree, counterThree, servoPosThree, serThree);
}
