#include "light_sensor.h"
#include "hardware/adc.h" // Include the header file for ADC functions
#include "pico/stdlib.h"  // Include the header file for standard library functions

void setup_adc_light()
{
    adc_init();
    adc_gpio_init(LIGHT_SENSOR_PIN);
    adc_select_input(1); // Select ADC1 (GP27) as the input
}

uint16_t read_adc_light() {
    // Select the ADC input channel
    adc_select_input(1);
    
    // Perform a blocking ADC read
    uint16_t result = adc_read();
    return result;
}

// void setup_pwm()
// {
//     gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);       // Set PWM function for the pin
//     uint slice_num = pwm_gpio_to_slice_num(PWM_PIN); // Get PWM slice number
//     pwm_set_wrap(slice_num, 4095);                   // Set the PWM counter wrap value (12-bit resolution)
//     pwm_set_enabled(slice_num, true);
// }

// void set_pwm_duty_cycle(uint16_t duty_cycle)
// {
//     uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
//     pwm_set_gpio_level(PWM_PIN, duty_cycle); // Set duty cycle
// }
