#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"
#include <time.h>


void delay(float num_seconds){
    // Converting time into milli_seconds
    float ms = 1000 * num_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + ms);
}

void fsm_toggle(int input, int *state, int *output, int *debounce_count){
    switch (*state){        
        case STATE_OFF:
            *output = 0;
            // Tombol dilepas
            if(!input && *debounce_count == 0){
                *state = DEBOUNCE_OFF;
            }
            // Tombol ditekan setelah debounce
            else if (input && *debounce_count >= 300){
                *state = STATE_ON;
                *debounce_count = 0;
            }
            break;
        
        case DEBOUNCE_OFF:
            // Debounce 300 ms
            if (*debounce_count < 300){
                *debounce_count += 1;
            }
            else{
                *state = STATE_OFF;
            }
            break;
        
        case STATE_ON:
            *output = 1;
            // Tombol dilepas
            if (!input && *debounce_count == 0){
                *state = DEBOUNCE_ON;
            }
            // Tombol ditekan setelah debounce
            else if (input && *debounce_count >= 300){
                *state = STATE_OFF;
                *debounce_count = 0;
            }
            break;

        case DEBOUNCE_ON:
            // Debounce 300 ms
            if (*debounce_count < 300){
                *debounce_count += 1;
            }
            else{
                *state = STATE_ON;
            }
            break;

        default:
            break;
    }

}