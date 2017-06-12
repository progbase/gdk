#include <Servo.h>

Servo servoMotor;

int servo_position = 0;

void setup() {
  servoMotor.attach(10);
}

void loop() {
  for (servo_position = 0; servo_position <= 90; servo_position++) {
    servoMotor.write(servo_position);
    delay(50);
  }
  
  for (servo_position = 90; servo_position >= 0; servo_position--) {
    servoMotor.write(servo_position);
    delay(50);
  }
}
