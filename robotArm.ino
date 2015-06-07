#include <Servo.h> //http://playground.arduino.cc/ComponentLib/Servo

/* 
 * First written on March 3rd 2015 by Tyler Adams
 * TODO:
 *  - get positions from servos by performing a read on their respective digital pins.
*/

// A simple human arm has 2 joints, one at the elbow and one at the shoulder.
Servo shoulderServo;
Servo elbowServo;

// Initialize DIGITAL pins to allow a connection between the Arduino and the Servos
int shoulderServoPin = 9; 
int elbowServoPin = 10; 

// Initialize rotation positions of servos.
int shoulderPos = 0;
int elbowPos = 0;

bool doneRotating = true;

// Attach servos.
void setup() {
    shoulderServo.attach(shoulderServoPin);
    elbowServo.attach(elbowServoPin);
}

// Rotate shoulder (entire arm) over robot's head and then rotate elbow behind head 
void simpleRotation() {
  doneRotating = false;
  
  // Rotate shoulder every 15 ms by 10 degrees.
  for (shoulderPos = 0; shoulderPos <= 180; shoulderPos += 10) {
    shoulderServo.write(shoulderPos);
    delay(150);
  }
  
  for (elbowPos = 0; elbowPos <= 180; elbowPos += 10) {                                
    elbowServo.write(elbowPos);
    delay(150);
  }
  
  doneRotating = true;
}

// Rotate elbow in front of head and then rotate shoulder (entire arm) below robot's head
void simpleReverseRotation() {
  doneRotating = false;
  
  // Rotate elbow every 15 ms by 10 degrees.
  for (elbowPos = 180; elbowPos >= 0; elbowPos -= 10) {                                
    elbowServo.write(elbowPos);
    delay(150);
  }  
  
  for (shoulderPos = 180; shoulderPos >= 0; shoulderPos -= 10) {
    shoulderServo.write(shoulderPos);
    delay(150);
  }
  
  doneRotating = true;
}

// Continously rotate robot's arm up 180 degrees and then down 180 degrees.
void loop() {
  if (doneRotating) {
    simpleRotation();
  } else {
    simpleReverseRotation();
  }
}

