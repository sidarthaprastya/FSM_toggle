#ifndef FSM_H
#define FSM_H

#define STATE_ON    1
#define STATE_OFF   0
#define STATE_HOLD  11
#define STATE_DEBOUNCE_OFF 3
#define STATE_DEBOUNCE_ON 13

void delay(float num_seconds);

void fsm_onoff(int input, int *state, int *output, int *debounce_count, int *hold_count);

#endif