
#include "pins_config.h"

void drive_forward()
{
  digitalWrite(front_L_pin, HIGH);
  digitalWrite(front_R_pin, HIGH);
  digitalWrite(back_L_pin, LOW);
  digitalWrite(back_R_pin, LOW);
}
void drive_backward()
{
  digitalWrite(front_L_pin, LOW);
  digitalWrite(front_R_pin, LOW);
  digitalWrite(back_L_pin, HIGH);
  digitalWrite(back_R_pin, HIGH);
}
void drive_left()
{
  digitalWrite(front_L_pin, HIGH);
  digitalWrite(front_R_pin, LOW);
  digitalWrite(back_L_pin, LOW);
  digitalWrite(back_R_pin, HIGH);
}
void drive_right()
{
  digitalWrite(front_L_pin, LOW);
  digitalWrite(front_R_pin, HIGH);
  digitalWrite(back_L_pin, HIGH);
  digitalWrite(back_R_pin, LOW);
}
void car_stop()
{
  digitalWrite(front_L_pin, LOW);
  digitalWrite(front_R_pin, LOW);
  digitalWrite(back_L_pin, LOW);
  digitalWrite(back_R_pin, LOW);
}

void GPIO_init()
{
  //initialize pins for motor directions
  pinMode(front_L_pin, OUTPUT);
  pinMode(front_R_pin, OUTPUT);
  pinMode(back_L_pin, OUTPUT);
  pinMode(back_R_pin, OUTPUT);
  car_stop();
}

void motor_speed(int L_speed, int R_speed)
{
  analogWrite(L_pin_speed, L_speed);
  analogWrite(R_pin_speed, R_speed);
}

void setup()
{
  GPIO_init();
  drive_forward();
  motor_speed(255, 255);
  delay(2000);  

  GPIO_init();
  drive_backward();
  motor_speed(255, 255);
  delay(2000); 

  GPIO_init();
  drive_left();
  motor_speed(255, 255);
  delay(2000);  

  GPIO_init();
  drive_right();
  motor_speed(255, 255);
  delay(2000);  

  car_stop();
}

void loop()
{
}
