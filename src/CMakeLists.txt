add_executable(${ProjectName}
    main.c
    drivers/gas_sensor/mq2_sensor.c
    drivers/light_sensor/light_sensor.c
    drivers/motor/motor.c
    drivers/ultrasonic/hc_sr04.c
    drivers/leds/leds.c
    drivers/buzzer/buzzer.c
)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4
    hardware_pwm
    hardware_adc 
    )

pico_add_extra_outputs(${ProjectName})