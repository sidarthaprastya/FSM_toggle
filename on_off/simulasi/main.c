#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int state = STATE_OFF; //Set OFF as initial state
    int input = 0;
    int time_case[10] = {50, 10, 5, 30, 40, 15, 25, 35, 100, 80};
    for(int i = 0; i < 10; i++){
        input = time_case[i];
        fsm(input, &state);
        printf("Input: %d \t State: %d\n", input, state);
    }
    printf("DONE");
    return 0;
}