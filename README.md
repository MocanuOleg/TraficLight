# TraficLight

This project implements a traffic light system using a state machine on an Arduino. The traffic light goes through a sequence of states with specified behaviors for each state, and user inputs (buttons) allow specific transitions based on predefined rules.

The traffic light has 5 states, each representing different light conditions:

State 1 (Red): Red light is ON for 5 seconds.
State 2 (Red Blinking): Red light blinks 3 times.
State 3 (Yellow): Yellow light is ON for 3 seconds.
State 4 (Green): Green light is ON for 5 seconds.
State 5 (Green Blinking): Green light blinks 3 times.

The state transitions follow this specific sequence:

[1] → [2] → [3] → [4] → [5] → [3] → [1]

Buttons Behavior
In [1]:

RED button does nothing.
GREEN button immediately switches to [2] and continues the sequence.
In [3]:

RED button switches back to [1] after the timeout.
GREEN button switches to [4] after the timeout.
In [4]:

RED button switches to [5], then to [3], and continues the sequence.
GREEN button does nothing.
In [2] and [5]:

Both buttons switch the system to Yellow and the opposite color state.
