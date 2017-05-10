#include <AFMotor.h>

AF_Stepper Stepper1(48, 2);
AF_Stepper Stepper2(48, 1);

void setup() {
Serial.begin(9600);
Serial.println("Start Test");
// put your setup code here, to run once:
Stepper1.setSpeed(30);
}

void loop() {
Serial.println("One Step");
Stepper1.step(100,FORWARD,SINGLE);
Stepper1.step(100,BACKWARD,SINGLE);

Stepper2.step(100,FORWARD,SINGLE);
Stepper2.step(100,BACKWARD,SINGLE);

Serial.println("Stop");
Stepper1.release();
Stepper2.release();
delay(2000);
}
