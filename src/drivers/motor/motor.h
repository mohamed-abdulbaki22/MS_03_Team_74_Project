#ifndef MOTOR_H
#define MOTOR_H

#include "pico/stdlib.h"
#include "hardware/pwm.h" // Include the header file for PWM functions

#define MOTOR_PIN_1 0
#define MOTOR_PIN_2 1
#define MOTOR_PIN_3 2
#define MOTOR_PIN_4 3
#define ENABLE_PIN1 9
#define ENABLE_PIN2 10
void init_pins_motor(void);
void turn_on_motor(void);
void turn_off_motor(void);

#endif