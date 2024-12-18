#include "motor.h"

// Initialize the motor pins and set up PWM for speed control
void init_pins_motor(void) {
    // Initialize motor control pins as outputs
    gpio_init(MOTOR_PIN_1);
    gpio_set_dir(MOTOR_PIN_1, GPIO_OUT);
    gpio_put(MOTOR_PIN_1, 0);

    gpio_init(MOTOR_PIN_2);
    gpio_set_dir(MOTOR_PIN_2, GPIO_OUT);
    gpio_put(MOTOR_PIN_2, 0);

    gpio_init(MOTOR_PIN_3);
    gpio_set_dir(MOTOR_PIN_3, GPIO_OUT);
    gpio_put(MOTOR_PIN_3, 0);

    gpio_init(MOTOR_PIN_4);
    gpio_set_dir(MOTOR_PIN_4, GPIO_OUT);
    gpio_put(MOTOR_PIN_4, 0);

    // Initialize enable pins for PWM
    gpio_set_function(ENABLE_PIN1, GPIO_FUNC_PWM);
    gpio_set_function(ENABLE_PIN2, GPIO_FUNC_PWM);

    // Get PWM slice numbers for the enable pins
    uint slice_num1 = pwm_gpio_to_slice_num(ENABLE_PIN1);
    uint slice_num2 = pwm_gpio_to_slice_num(ENABLE_PIN2);

    // Configure PWM for both slices
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f); // Set clock divider for slower PWM frequency

    pwm_init(slice_num1, &config, true);
    pwm_init(slice_num2, &config, true);

    // Set duty cycle to 30% (0.3 * 65535)
    uint16_t level = (uint16_t)(0.3f * 65535);
    pwm_set_gpio_level(ENABLE_PIN1, level);
    pwm_set_gpio_level(ENABLE_PIN2, level);
}

// Turn on the motor by activating the control pins
void turn_on_motor(void) {
    gpio_put(MOTOR_PIN_1, 1);
    gpio_put(MOTOR_PIN_2, 0);
    gpio_put(MOTOR_PIN_3, 1);
    gpio_put(MOTOR_PIN_4, 0);
}

// Turn off the motor by deactivating the control pins
void turn_off_motor(void) {
    gpio_put(MOTOR_PIN_1, 0);
    gpio_put(MOTOR_PIN_2, 0);
    gpio_put(MOTOR_PIN_3, 0);
    gpio_put(MOTOR_PIN_4, 0);
}
