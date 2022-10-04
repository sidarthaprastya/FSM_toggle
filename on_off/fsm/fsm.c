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

void fsm_onoff(int input, int *state, int *output, int *debounce_count, int *hold_count){
    switch (*state){
        case STATE_OFF:
            *output = 0;
            if(!input){
                // debounce dihitung mulai saat tombol dilepas
                *debounce_count += 1;
                // membatasi debounce agar tidak overflow
                if (*debounce_count >= 200000){
                   *debounce_count = 300;
                }
            }
            // debounce saat menekan tombol
            else if (input && *debounce_count >= 300){
                *state = STATE_ON;
                *output = 1;
                *debounce_count = 0;
                
            }
            break;
        case STATE_ON:
            if (!input){
                // debounce dihitung mulai saat tombol dilepas
                *debounce_count += 1;
                // membatasi debounce agar tidak overflow
                if (*debounce_count >= 200000){
                   *debounce_count = 300;
                }
            }
            // Tombol ditekan dan debounce telah melebihi
            else if (input && *debounce_count >= 300){
                *state = STATE_HOLD;
                *hold_count = 0;
            }
            break;
        
        case STATE_HOLD:
            // tombol ditekan kurang dari 1 detik
            if (input && *hold_count < 1000){
                *hold_count += 1;
            }
            // tombol ditekan lebih dari 1 detik
            else if (input && *hold_count >= 1000){
                *state = STATE_OFF;
                *output = 0;
                *debounce_count = 0;
            }
            // tombol dilepas saat kurang dari 1 detik
            else if (!input && *hold_count < 1000){
                *state = STATE_ON;
                *output = 1;
            }
            break;
		
    }
}