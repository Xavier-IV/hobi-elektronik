#include <Servo.h>

#define INPUT_X A0
#define INPUT_Y A1
#define INPUT_BTN 2
#define SERVO_X 9
#define SERVO_Y 10

int btn, inX, inY;

Servo servo_x, servo_y;

void setup() {
  pinMode(INPUT_BTN, INPUT);
  servo_x.attach(SERVO_X);
  servo_y.attach(SERVO_Y);
  
  digitalWrite(INPUT_BTN, HIGH);
}

void loop() {
  btn = digitalRead(INPUT_BTN);

  inX = analogRead(INPUT_X);
  inY = analogRead(INPUT_Y);

  if (inX > 1000) { servo_x.write(180); }
  else if (inX < 20) { servo_x.write(0); }
  else { servo_x.write(90); }

  if (inY > 1000) { servo_y.write(180); }
  else if (inY < 20) { servo_y.write(0); }
  else { servo_y.write(90); }
}
