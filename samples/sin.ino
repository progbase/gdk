#include <AFMotor.h>
#include <Servo.h>

class Pen {
    Servo servoMotor;
  public:
    void attach(int controlPin);
    void up();
    void down();
};

AF_Stepper StepperY(48, 2);
AF_Stepper StepperX(48, 1);
Pen pen;

void setup() {
  pen.attach(10);

  // reset
  pen.up();
  
  StepperY.setSpeed(200);
  StepperX.setSpeed(200);
  
  int sX = 200 / 2;

  StepperY.step(sX, FORWARD, SINGLE);
  delay(100);
  pen.down();
  
  int dirY = BACKWARD;
  int amp = 50;
  int a = 0;
  
  for (int i = 0; i < 200; i++) {
    int thisY = (sX - a);
    a = amp * sin(2 * PI / 200.0 * i);
    int newY = (sX - a);
    StepperX.step(1, FORWARD, SINGLE);
    int move = (int) (newY - thisY);
    StepperY.step(abs(move), move > 0 ? FORWARD : BACKWARD, SINGLE);
    delay(10);
  }

  pen.up();
}

void Pen::attach(int controlPin) { servoMotor.attach(controlPin); }
void Pen::up() { servoMotor.write(10); }
void Pen::down() { servoMotor.write(60); }

void loop() {

}
