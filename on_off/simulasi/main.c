#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int state = STATE_OFF; //Set OFF as initial state
    int input = 0;
    int output = 0;
    int debounce_count = 0;
    int hold_count = 0;
    int time_case[10] = {300, 1100, 500, 300, 1400, 1500, 250, 350, 3000, 800};
    for(int i = 0; i < 10; i++){
        // durasi time_case ditambah 300 agar faktor debounce tidak dimasukkan
        for (int j = 0; j < time_case[i] + 300; j++){
            fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
        }
        printf("Input: %d \t Period: %d \t State: %d\n", input, time_case[i], state);
        // Input bergantian antara HIGH dan LOW
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