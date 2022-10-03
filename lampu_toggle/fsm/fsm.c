#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"
#include <time.h>


void delay(int num_seconds){
    // Converting time into milli_seconds
    int ms = 1000 * num_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + ms);
}

void fsm_toggle(int input, int *state, int *debounce_count){
    switch (*state){
        case STATE_ON:
            if (!input){
                break;
            }
            else{
                *state = DEBOUNCE_OFF;
                *debounce_count = 0;
                break;
            }
        case DEBOUNCE_OFF:
            if (*debounce_count < 100){
                *debounce_count += 1;
                break;
            }
            else{
                *state = STATE_OFF;
                break;
            }
        
        case STATE_OFF:
            if(!input){
                break;
            }
            else{
                *state = DEBOUNCE_ON;
                *debounce_count = 0;
                break;
            }
        
        case DEBOUNCE_ON:
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