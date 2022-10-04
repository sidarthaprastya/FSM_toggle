#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "fsm.h"

#define LED     GPIO_NUM_2
#define BUTTON  GPIO_NUM_13
const TickType_t xDelay = 1 / portTICK_PERIOD_MS;

void button_config()
{
    gpio_reset_pin(BUTTON);
    gpio_set_direction(BUTTON, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON);
}

void led_config()
{
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
}

void app_main()
{   
    int input, output, debounce_count, state, hold_count;
    button_config();
    led_config();

    debounce_count = 0;
    hold_count = 0;

    // Initial FSM State
    state = STATE_OFF;

    while (1) {
        if (gpio_get_level(BUTTON) == 1) { //PULLUP
            input = 0;
        }
        else{
            input = 1;
        }

        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
        gpio_set_level(LED, output);
        printf("%d, %d, %d\n", input, state, debounce_count); 
    }
}