
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
  
void setup()
{
  GPIO_init();
  

}

void loop()
{
}
