#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fsm.h"

void delay(int num_seconds){
    // Converting time into milli_seconds
    int ms = 1000 * num_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + ms);
}

void fsm(int input, int *state){
    switch (*state){
        case STATE_ON:
            if (input < 30){ //counter sebagai pengganti waktu
                break;
            }
            else{
                *state = STATE_OFF;
                break;
            }
        
        case STATE_OFF:
            if(input < 30){
                *state = STATE_ON;
                break;
            }
            else{
                break;
            }

        default:
            break;
    }
}