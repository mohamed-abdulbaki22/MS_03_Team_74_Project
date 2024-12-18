#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "drivers/gas_sensor/mq2_sensor.h"
#include "drivers/light_sensor/light_sensor.h"
#include "drivers/ultrasonic/hc_sr04.h"
#include "drivers/motor/motor.h"
#include "drivers/buzzer/buzzer.h"
#include "drivers/leds/leds.h"

void init()
{
    stdio_init_all();
    init_pins_gas();
    // Initialize the HC-SR04 pins
    hc_sr04_init();
    // Initialize the PWM pin
    setup_adc_light();
    setup_pwm_led();
    // Initialize the motor pins
    init_pins_motor();
    buzzer_init();
    setup_smoke_led();
}

void led_task()
{
    // const uint LED_PIN = 15;
    gpio_init(15);
    gpio_set_dir(15, GPIO_OUT);
    while (true)
    {
        gpio_put(15, 1);
        vTaskDelay(1000);
        gpio_put(15, 0);
        vTaskDelay(1000);
    }
}

void gas_task()
{
    while (true)
    {
        check_gas_and_control_led();
        vTaskDelay(500);
    }
}

void light_task()
{
    while (true)
    {
        uint16_t light_level = read_adc_light();

        // Invert and scale the duty cycle for PWM
        uint16_t duty_cycle = light_level;

        set_pwm_duty_cycle(duty_cycle);
        vTaskDelay(pdMS_TO_TICKS(500)); // 500ms delay
    }
}

void ultrasonic_task()
{
    while (true)
    {
        float distance = hc_sr04_get_distance();
        if (distance < DETECTION_THRESHOLD)
        {
            turn_off_motor();
            buzzer_on();
            vTaskDelay(distance * 25); // Adjust beep duration based on distance
            buzzer_off();
        }
        else
        {
            turn_on_motor();
            buzzer_off();
        }
        printf("Distance: %.2f cm\n", distance);
        vTaskDelay(500);
    }
}

int main()
{
    init();

    // xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(gas_task, "GAS_Task", 256, NULL, 1, NULL);
    xTaskCreate(ultrasonic_task, "ULTRUSONIC_Task", 256, NULL, 1, NULL);
    xTaskCreate(light_task, "LIGHT_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1)
    {
    };
}