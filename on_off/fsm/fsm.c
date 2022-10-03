#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fsm.h"

void delay(float num_seconds){
    // Converting time into milli_seconds
    float ms = 1000 * num_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + ms);
}

void fsm_onoff(int input, int *state, int *debounce_count, int *hold_count){
    switch (*state){
        case STATE_ON:
            if (!input){
                break;
            }
            else{
                *state = STATE_HOLD;
                *hold_count = 0;
                break;
            }
        case STATE_HOLD:
            if (*hold_count < 1000 && input){
                *hold_count += 1;
                break;
            }
            else if (*hold_count >= 1000 && input){
                *state = STATE_OFF;
                break;
            }
            else{
                *state = STATE_ON;
                break;
            }
        
        case STATE_OFF:
            if(!input){
                *hold_count = 0;
                break;
            }
            else if (input && *hold_count == 0){
                *state = STATE_DEBOUNCE;
                *debounce_count = 0;
                break;
            }
        
        case STATE_DEBOUNCE:
            if (*debounce_count < 100){
                *debounce_count += 1;
                break;
            }
            else{
                *state = STATE_ON;
                break;
            }

        default:
            break;
    }

}