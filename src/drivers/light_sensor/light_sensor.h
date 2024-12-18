#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "pico/stdlib.h"
#include "hardware/adc.h" // Include the header file for ADC functions
#include "hardware/pwm.h" // Include the header file for PWM functions

#define LIGHT_SENSOR_PIN 27 // ADC1 (GP26)
#define PWM_PIN 15          // Output pin for PW

void setup_adc_light();
uint16_t read_adc_light();
// void setup_pwm();
// void set_pwm_duty_cycle(uint16_t duty_cycle);

#endif