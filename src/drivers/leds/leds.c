#include "leds.h"
#include "hardware/gpio.h"
// #include "hardware/timer.h"
#include "pico/stdlib.h"

void setup_pwm_led()
{
    gpio_set_function(PWM_LIGHT_LED, GPIO_FUNC_PWM);       // Set PWM function for the pin
    uint slice_num = pwm_gpio_to_slice_num(PWM_LIGHT_LED); // Get PWM slice number
    pwm_set_wrap(slice_num, 4095);                   // Set the PWM counter wrap value (12-bit resolution)
    pwm_set_enabled(slice_num, true);
}

void set_pwm_duty_cycle(uint16_t duty_cycle)
{
    uint slice_num = pwm_gpio_to_slice_num(PWM_LIGHT_LED);
    pwm_set_gpio_level(PWM_LIGHT_LED, duty_cycle); // Set duty cycle
}

void setup_smoke_led()
{
    gpio_init(SMOKE_PIN);
    gpio_set_dir(SMOKE_PIN, GPIO_OUT);
    gpio_put(SMOKE_PIN, 0);  // Ensure the LED is OFF initially
}

void smoke_led_on()
{
    gpio_put(SMOKE_PIN, 1);
}

void smoke_led_off()
{
    gpio_put(SMOKE_PIN, 0);
}

