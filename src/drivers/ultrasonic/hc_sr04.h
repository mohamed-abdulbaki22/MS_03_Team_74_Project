#ifndef HC_SR04_H
#define HC_SR04_H

#include "pico/stdlib.h"

// Pin definitions
#define HC_SR04_TRIGGER_PIN 20  // GPIO pin for trigger
#define HC_SR04_ECHO_PIN 28     // GPIO pin for echo
#define DETECTION_THRESHOLD 30.0 // Distance in cm to turn on the LED

// Function prototypes
void hc_sr04_init(void);
float hc_sr04_get_distance(void);

#endif
