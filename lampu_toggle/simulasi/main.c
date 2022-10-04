#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int state = STATE_OFF; //Set OFF as initial state
    int input = 0;
    int output = 0;
    int debounce_count = 0;
    for(int i = 0; i < 10; i++){
        
        fsm_toggle(input, &state, &output, &debounce_count);
        // State saat debounce dibuat agar menghiraukan frekuensi input
        while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
            fsm_toggle(input, &state, &output, &debounce_count);
        }
        printf("Input: %d \t State: %d\n", input, state);
        
        // Input dibuat bergantian 1/0
        if (!input){
            input = 1;
        }
        else{
            input = 0;
        }
    }
    printf("DONE");
    return 0;
}