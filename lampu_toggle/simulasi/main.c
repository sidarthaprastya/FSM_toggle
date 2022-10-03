#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int state = STATE_OFF; //Set OFF as initial state
    int input = 0;
    int debounce_count = 0;
    for(int i = 0; i < 10; i++){
        
        fsm_toggle(input, &state, &debounce_count);
        while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
            fsm_toggle(input, &state, &debounce_count);
        }
        printf("Input: %d \t State: %d\n", input, state);
        if (!input){
            input = 1;
        }
        else{
            input = 0;
        }
        // delay(0.5);
    }
    printf("DONE");
    return 0;
}