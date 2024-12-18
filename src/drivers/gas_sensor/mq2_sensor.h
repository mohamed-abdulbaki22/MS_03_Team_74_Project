#ifndef MQ2_SENSOR_H
#define MQ2_SENSOR_H

#include "pico/stdlib.h"

// Pin definitions
#define MQ2_AO_PIN 26  // GP26 for the MQ2 digital output
#define LED_PIN 14     // GP14 for the LED

// Function prototypes
void init_pins_gas(void);         // Initialize pins for the sensor and LED
void check_gas_and_control_led(void);  // Read MQ2 and control the LED accordingly

#endif  // MQ2_TEST_H