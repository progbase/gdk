#include <AFMotor.h>
#include <Servo.h>

// plotter interface

class Plotter {
    Servo servoMotor;
    AF_Stepper StepperY;
    AF_Stepper StepperX;
  public:
    Plotter(int sX, int sY) : StepperY(48, sY), StepperX(48, sX) { }
    void setSpeed(int speed);
    void attachPen(int controlPin);
    void penUp();
    void penDown();
    void moveTo(int x, int y);
    void shift(float dx, float dy);
};

// main

Plotter plotter(1, 2);

void setup() {
  plotter.setSpeed(200);
  plotter.attachPen(10);
  plotter.penUp();

  int WIDTH = 200;
  int HEIGHT = 200;
  int cX = WIDTH / 2;
  int cY = HEIGHT / 2;

  float x = 0;
  float y = 0;
  int r = 100;

  float t = 0;

  int k = 4;
  rose(&x, &y, t, r, k);
  plotter.moveTo(x, y);  
  plotter.penDown();

  for (int deg = 0; deg <= 360; deg+=1) {
    t = deg * PI / 180.0;
    
    float newX = 0;
    float newY = 0;
    
    // circle(&newX, &newY, t, r);
    rose(&newX, &newY, t, r, k);
    newX += cX;
    newY += cY;
    
    float dx = newX - x;
    float dy = newY - y;
    plotter.shift(dx, dy);
    
    x = newX;
    y = newY;
  }

  plotter.penUp();
}

void circle(float * x, float * y, float t, float r) {
  *x = r * cos(t);
  *y = r * sin(t);
}

void rose(float * x, float * y, float t, float r, int k) {
  *x = r * cos(k * t) * cos(t);
  *y = r * cos(k * t) * sin(t);
}

void loop() {

}

// plotter impl

void Plotter::setSpeed(int speed) {
  StepperY.setSpeed(speed);
  StepperX.setSpeed(speed);
}

void Plotter::moveTo(int x, int y) {
  StepperX.step(x, FORWARD, SINGLE);
  delay(400);
  StepperY.step(y, FORWARD, SINGLE);
  delay(400);
}

void Plotter::shift(float dx, float dy) {
  StepperX.step(round(fabs(dx)), dx > 0 ? FORWARD : BACKWARD, SINGLE);
  delay(5); 
  StepperY.step(round(fabs(dy)), dy > 0 ? FORWARD : BACKWARD, SINGLE);
  delay(5);
}

void Plotter::attachPen(int controlPin) { servoMotor.attach(controlPin); }
void Plotter::penUp() { servoMotor.write(0); }
void Plotter::penDown() { servoMotor.write(20); }
