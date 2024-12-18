#include "hc_sr04.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Initialize the HC-SR04 sensor
void hc_sr04_init(void) {
    // Configure the trigger pin as output
    gpio_init(HC_SR04_TRIGGER_PIN);
    gpio_set_dir(HC_SR04_TRIGGER_PIN, GPIO_OUT);
    gpio_put(HC_SR04_TRIGGER_PIN, 0);

    // Configure the echo pin as input
    gpio_init(HC_SR04_ECHO_PIN);
    gpio_set_dir(HC_SR04_ECHO_PIN, GPIO_IN);
}

// Get the distance in cm
float hc_sr04_get_distance(void) {
    // Send a 10-microsecond pulse to the trigger pin
    gpio_put(HC_SR04_TRIGGER_PIN, 1);
    sleep_us(10);
    gpio_put(HC_SR04_TRIGGER_PIN, 0);

    // Wait for the echo pin to go high
    absolute_time_t timeout = make_timeout_time_us(200000); // 200 ms timeout
    while (!gpio_get(HC_SR04_ECHO_PIN)) {
        if (absolute_time_diff_us(get_absolute_time(), timeout) <= 0) {
            return -1.0f; // Timeout, no echo detected
        }
    }

    // Record the start time
    absolute_time_t start_time = get_absolute_time();

    // Wait for the echo pin to go low
    while (gpio_get(HC_SR04_ECHO_PIN)) {
        if (absolute_time_diff_us(get_absolute_time(), timeout) <= 0) {
            return -1.0f; // Timeout, echo signal too long
        }
    }

    // Record the end time
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration of the echo pulse in microseconds
    int64_t pulse_duration_us = absolute_time_diff_us(start_time, end_time);

    // Convert the duration to distance in cm
    // Speed of sound = 343 m/s or 34300 cm/s
    // Distance = (duration / 2) * (speed of sound)
    float distance_cm = (pulse_duration_us / 2.0f) * 0.0343f;

    return distance_cm;
}
