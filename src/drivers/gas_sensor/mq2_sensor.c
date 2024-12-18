#include "mq2_sensor.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "../leds/leds.h"

void init_pins_gas(void)
{
    // Initialize the MQ2 DO pin as input
    adc_init();
    adc_gpio_init(MQ2_AO_PIN);
    adc_select_input(0); // Select ADC0 (GP26) as the input

    // Initialize the LED pin as output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    // gpio_put(LED_PIN, 1);  // Turn OFF the LED
}

void check_gas_and_control_led(void)
{
    adc_select_input(0); // Select ADC0 (GP26) as the input
    // Read the MQ2 sensor digital output
    uint16_t raw_value = adc_read();
    float gas_detected = (raw_value * 3.3) / 4095;

    // Control the LED based on the sensor output
    if (gas_detected > 0.5)
    {
        smoke_led_on();
    }
    else
    {
        smoke_led_off();
    }
}
