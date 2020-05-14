#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "pins_config.h"


LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F,16,2);
long duration;
int distance;
char command;

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

  pinMode(Echo_pin, INPUT);
  pinMode(Trig_pin, OUTPUT);
  car_stop();
}

void motor_speed(int L_speed, int R_speed)
{
  analogWrite(L_pin_speed, L_speed);
  analogWrite(R_pin_speed, R_speed);
}

void car_management(char command)
{
  if(command == '1')
  {
    drive_forward();
    motor_speed(255, 255);
    delay(100);
    
  }
  else if(command == '2')
  {
    drive_backward();
    motor_speed(255, 255);
    delay(100);
    
  }
  else if(command == '3')
  {
    drive_left();
    motor_speed(255, 255);
    delay(100);
  }
  else if(command == '4')
  {
    drive_right();
    motor_speed(255, 255);
    delay(100);
  }
  else if(command == '5')
  {
    car_stop();
  }
  delay(100);
}

void buzzer_on()   //open buzzer
{
  digitalWrite(buzzer_pin, LOW);
}
void buzzer_off()  //close buzzer
{
  digitalWrite(buzzer_pin, HIGH);
}

void setup()
{
  buzzer_off();
  
  //Wi-Fi or bluetooth connection via android apps
  //wifi connection: IP address: 192.168.4.1 port: 9000
  GPIO_init();
  
  Serial.begin(9600); // serial communication at baudrate 9600
  
//  drive_forward();
//  motor_speed(255, 255);
//  delay(2000);  
//
//  GPIO_init();
//  drive_backward();
//  motor_speed(255, 255);
//  delay(2000); 
//
//  GPIO_init();]
//  
//  drive_left();
//  motor_speed(255, 255);
//  delay(2000);  
//
//  GPIO_init();
//  drive_right();
//  motor_speed(255, 255);
//  delay(2000);  
//
//  car_stop();
} 

void loop()
{
  buzzer_off();
  if(Serial.available())
  {
    command = Serial.read();
    Serial.println(command);
  }
  car_management(command);

  // ultrasonic sensor config
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(5);

  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);

  duration = pulseIn(Echo_pin, HIGH);
  distance = duration * 0.034 / 2;
  if(distance  < 8)
  {
    buzzer_on();
  }

//  Serial.print("Distance = ");
//  Serial.print(duration/100.00);
//  Serial.println(" cm");
//  delay(50);

  // start the LCD display:
  lcd.begin();
  lcd.backlight();
  
  lcd.clear(); //clear the screen
  lcd.setCursor(0,0); // Set the cursor to column 1, line 1 (counting starts at zero)
  
  // prints the distance, measured by ultrasonic sensor, on the LCD display
  lcd.print("    Distance    "); // put this string on the middle of the line

  //go on the next line
  lcd.setCursor(6,1);  
  lcd.print(distance); 
  lcd.print("cm"); 
  
  delay(50);

}
