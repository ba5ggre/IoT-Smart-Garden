#include <ESP32Servo.h>

#define SERVO_PIN 13
Servo shadeServo;

void initServo() {
  ESP32PWM::allocateTimer(0);
  shadeServo.setPeriodHertz(50); 
  shadeServo.attach(SERVO_PIN, 500, 2400); 
}

void moveShield(int angle) {
  shadeServo.write(angle);
}