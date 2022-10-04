#ifndef FSM_H
#define FSM_H

#define STATE_ON    1
#define STATE_OFF   0
#define DEBOUNCE_OFF 10
#define DEBOUNCE_ON 11

void delay(float num_seconds);

void fsm_toggle(int input, int *state, int *output, int *debounce_count);

#endif