# Gate Motor State Machine Simulation

This project implements a state machine in C to simulate the behavior of a gate motor with different states: `OPEN`, `CLOSED`, `OPENING`, `CLOSING`, and `EMERGENCY`. The program provides a command-line interface for interacting with the state machine and allows the user to move between states based on logical transitions.

## Features

- **States:**
  - `CLOSED`: The gate is completely closed, and the motor is off.
  - `CLOSING`: The gate is in the process of closing, and the motor is active.
  - `OPEN`: The gate is completely open, and the motor is off.
  - `OPENING`: The gate is in the process of opening, and the motor is active.
  - `EMERGENCY`: The gate has stopped due to an emergency, and the motor is off.

- **Transitions:**
  - From `OPEN`, you can transition to `CLOSING` or `EMERGENCY`.
  - From `CLOSING`, you can transition to `CLOSED` or `EMERGENCY`.
  - From `CLOSED`, you can transition to `OPENING` or `EMERGENCY`.
  - From `OPENING`, you can transition to `OPEN` or `EMERGENCY`.
  - From `EMERGENCY`, you can only transition to `OPENING`.

- **Motor Status:**
  - The motor is active when the gate is in the `CLOSING` or `OPENING` state.
  - The motor is inactive when the gate is in `CLOSED`, `OPEN`, or `EMERGENCY`.

- **Emergency Handling:**
  - When `EMERGENCY` is activated, the motor stops immediately.
  - After leaving the `EMERGENCY` state, the system transitions to `OPENING`, and the emergency status (`Sr_Emerg`) is reset.
