#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int input, state, prev_state;
    int debounce_count = 0;

    // Test input 0 while OFF
    input = 0;
    state = STATE_OFF;
    prev_state = state;
    fsm_toggle(input, &state, &debounce_count);
    while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
        fsm_toggle(input, &state, &debounce_count);
    }
    printf("TEST 1 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input 1 while OFF
    input = 1;
    state = STATE_OFF;
    prev_state = state;
    fsm_toggle(input, &state, &debounce_count);
    while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
        fsm_toggle(input, &state, &debounce_count);
    }
    printf("TEST 2 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input 0 while ON
    input = 0;
    state = STATE_ON;
    prev_state = state;
    fsm_toggle(input, &state, &debounce_count);
    while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
        fsm_toggle(input, &state, &debounce_count);
    }
    printf("TEST 3 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    // Test input 1 while OFF
    input = 1;
    state = STATE_ON;
    prev_state = state;
    fsm_toggle(input, &state, &debounce_count);
    while (state == DEBOUNCE_OFF || state == DEBOUNCE_ON){
        fsm_toggle(input, &state, &debounce_count);
    }
    printf("TEST 4 \t (PREV STATE: %d, INPUT: %d, CURRENT STATE: %d)\n", prev_state, input, state);

    return 0;
}