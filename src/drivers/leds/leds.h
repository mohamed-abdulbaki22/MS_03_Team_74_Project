#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"
#include "hardware/adc.h" // Include the header file for ADC functions
#include "hardware/pwm.h" // Include the header file for PWM functions

#define PWM_LIGHT_LED 15        // Output pin for PW
#define SMOKE_PIN 14       // GPIO pin for the LED

void setup_pwm_led();
void set_pwm_duty_cycle(uint16_t duty_cycle);
void setup_smoke_led();
void smoke_led_on();
void smoke_led_off();

#endif // LEDS_H