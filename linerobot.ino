#include <AFMotor.h>

AF_DCMotor leftMotor(3);
AF_DCMotor rightMotor(4);

const int leftIR = A3;
const int midIR = A5;
const int rightIR = A4;

const int FtrigPin = A1;
const int FechoPin = A2;

// variables
int left_motor_speed = 0;
int right_motor_speed = 0;

int state_left;
int state_mid;
int state_right;

int objFrontDist = 0;


float readUltrasonicCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  long dur = pulseIn(echoPin, HIGH, 30000);
  if (!dur) {
    return 255;

  } else {
    return (dur * 0.0343) / 2.0;
  }

}

void setup () {
      pinMode(leftIR, INPUT);
      pinMode(midIR, INPUT);
      pinMode(rightIR, INPUT);

      pinMode(FtrigPin, OUTPUT);
      pinMode(FechoPin, INPUT);

}

void turnLeft() {
      leftMotor.setSpeed(120);
      rightMotor.setSpeed(195);

      leftMotor.run(FORWARD);
      rightMotor.run(BACKWARD);
}

void turnRight() {
      leftMotor.setSpeed(195);
      rightMotor.setSpeed(120);

      leftMotor.run(BACKWARD);
      rightMotor.run(FORWARD);
}

void goStraight() {
      leftMotor.setSpeed(185);
      rightMotor.setSpeed(180);

      leftMotor.run(BACKWARD);
      rightMotor.run(BACKWARD);

}

void stopMotors() {
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(0);
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}

void loop () {
      objFrontDist = readUltrasonicCM(FtrigPin, FechoPin);

      if (objFrontDist <= 12) {
            stopMotors();
            turnRight();
            delay(300);
            goStraight();
            delay(400);
            turnLeft();
            delay(300);
            goStraight(); 
            delay(400);
            turnLeft();
            delay(300);
            goStraight();
            delay(500);
            turnRight();
            delay(300);
            return;
      }

      state_left = digitalRead(leftIR);
      state_mid = digitalRead(midIR);
      state_right = digitalRead(rightIR);

      if (state_mid == 0 && state_left == 0 && state_right == 0) {
            goStraight();
      }
      else if (state_left == 1) {
            turnLeft();
      }
      else if (state_right == 1) {
            turnRight();
      }
      else {
            stopMotors();     
      }
}
