#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

int main(){
    int input, state, prev_state, output, debounce_count, hold_count;
    int duration;

    // Test input HIGH dengan t < 1000 while OFF
    input = 1;
    state = STATE_OFF;
    prev_state = state;
    duration = 800;
    debounce_count = 300; // Debounce diberi 300 karena dianggap ideal
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 1 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input HIGH dengan t >= 1000 while OFF
    input = 1;
    state = STATE_OFF;
    prev_state = state;
    duration = 1200;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 2 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input LOW dengan t < 1000 while OFF
    input = 0;
    state = STATE_OFF;
    prev_state = state;
    duration = 800;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 3 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input LOW dengan t >= 1000 while OFF
    input = 0;
    state = STATE_OFF;
    prev_state = state;
    duration = 1200;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 4 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input HIGH dengan t < 1000 while ON
    input = 1;
    state = STATE_ON;
    prev_state = state;
    duration = 800;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 5 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input HIGH dengan t >= 1000 while ON
    input = 1;
    state = STATE_ON;
    prev_state = state;
    duration = 1200;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 6 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input LOW dengan t < 1000 while ON
    input = 0;
    state = STATE_ON;
    prev_state = state;
    duration = 800;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 7 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    // Test input LOW dengan t >= 1000 while ON
    input = 0;
    state = STATE_ON;
    prev_state = state;
    duration = 1200;
    debounce_count = 300;
    hold_count = 0;
    for (int j = 0; j < duration; j++){
        fsm_onoff(input, &state, &output, &debounce_count, &hold_count);
    }
    printf("TEST 8 \t (PREV STATE: %d, INPUT: %d, DURASI: %d, CURRENT STATE: %d)\n", prev_state, input, duration, state);

    return 0;
}