#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../fsm/fsm.h"

#define LED_RED GPIO_NUM_2

#define BTN_RED GPIO_NUM_13

#define TIMER_DIVIDER         16  
#define TIMER_SCALE           (TIMER_BASE_CLK /TIMER_DIVIDER)  
#define DELAY_S               0.25
#define TIMER1_INTERVAL_SEC   (DELAY_S)
 
volatile bool button_pressed = false;
double current_time_sec = 0, last_time_sec = 0, last_reset_time = 0;

static void IRAM_ATTR gpio_isr_handler (void* arg) {
    timer_get_counter_time_sec(0, 0, &current_time_sec);
    if (current_time_sec - last_time_sec > DELAY_S) {
        
        last_time_sec = current_time_sec;
    }
    
    
}

// static void gpio_isr_handler(void* arg) 
// {
//     button_pressed = true;
// }

void button_config()
{
    gpio_install_isr_service(0);
    printf("configuring button\n");
    gpio_reset_pin(BTN_RED);
    gpio_set_direction(BTN_RED, GPIO_MODE_INPUT);
    gpio_pullup_en(BTN_RED);
    gpio_set_intr_type(BTN_RED, GPIO_INTR_POSEDGE);
    gpio_isr_handler_add(BTN_RED, gpio_isr_handler, NULL);
    printf("config complete\n");
}

void led_config()
{
    gpio_reset_pin(LED_RED);
    gpio_set_direction(LED_RED, GPIO_MODE_OUTPUT);
}

void app_main()
{   
    uint8_t led_value = 0;

    button_config();
    led_config();

    while (1) {
        if (button_pressed) {
            printf("*\n");
            button_pressed = false;
            led_value = !led_value;
            gpio_set_level(LED_RED, led_value);
        }
        vTaskDelay(DELAY_TIME / portTICK_PERIOD_MS);
    }
}