#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int input, state, prev_state;

    // Test input < 30 while OFF
    input = 20;
    state = STATE_OFF;
    prev_state = state;
    fsm(input, &state);
    printf("TEST 1 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input >= 30 while OFF
    input = 40;
    state = STATE_OFF;
    prev_state = state;
    fsm(input, &state);
    printf("TEST 2 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input < 30 while ON
    input = 20;
    state = STATE_ON;
    prev_state = state;
    fsm(input, &state);
    printf("TEST 3 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input >= 30 while ON
    input = 40;
    state = STATE_ON;
    prev_state = state;
    fsm(input, &state);
    printf("TEST 4 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    return 0;
}