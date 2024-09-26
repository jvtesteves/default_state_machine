#include <stdio.h>

// Definition of states
typedef enum {
    CLOSED,
    CLOSING,
    OPEN,
    OPENING,
    EMERGENCY
} State;

// Global variables
State currentState = CLOSED;  // Initial state
int motor = 0;                // Motor state
int Sr_Emerg = 0;             // Emergency state

// Function to update the state machine
void updateState() {
    switch (currentState) {
        case OPEN:
            motor = 0;
            break;

        case CLOSING:
            motor = 1;
            break;

        case CLOSED:
            motor = 0;
            break;

        case OPENING:
            motor = 2;
            break;

        case EMERGENCY:
            motor = 0;
            Sr_Emerg = 1;  // Emergency activated
            break;

        default:
            break;
    }
}

// Function to display the current state, motor, and Sr_Emerg
void displayState() {
    switch (currentState) {
        case OPEN:
            printf("Current state: OPEN\n");
            break;
        case CLOSING:
            printf("Current state: CLOSING\n");
            break;
        case CLOSED:
            printf("Current state: CLOSED\n");
            break;
        case OPENING:
            printf("Current state: OPENING\n");
            break;
        case EMERGENCY:
            printf("Current state: EMERGENCY\n");
            break;
        default:
            printf("Unknown state\n");
            break;
    }

    // Display the status of the motor and Sr_Emerg
    printf("Motor status: %d\n", motor);
    printf("Sr_Emerg status: %d\n", Sr_Emerg);
}

int main() {
    int option;

    while (1) {
        // Display the current state of the gate, motor, and Sr_Emerg
        displayState();

        // Display options for the user
        printf("\nChoose an action:\n");
        printf("1. Move to CLOSED (only from CLOSING)\n");
        printf("2. Move to OPEN (only from OPENING)\n");
        printf("3. Move to CLOSING (only from OPEN)\n");
        printf("4. Move to OPENING (only from CLOSED or EMERGENCY)\n");
        printf("5. Move to EMERGENCY\n");
        printf("6. Stop and exit the program\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:  // Move to CLOSED
                if (currentState == CLOSING) {
                    currentState = CLOSED;
                    printf("Gate completely closed.\n");
                } else {
                    printf("Invalid action! The gate needs to be in CLOSING to move to CLOSED.\n");
                }
                break;

            case 2:  // Move to OPEN
                if (currentState == OPENING) {
                    currentState = OPEN;
                    printf("Gate completely open.\n");
                } else {
                    printf("Invalid action! The gate needs to be in OPENING to move to OPEN.\n");
                }
                break;

            case 3:  // Move to CLOSING
                if (currentState == OPEN) {
                    currentState = CLOSING;
                    printf("Gate is closing...\n");
                } else {
                    printf("Invalid action! The gate needs to be in OPEN to move to CLOSING.\n");
                }
                break;

            case 4:  // Move to OPENING
                if (currentState == CLOSED || currentState == EMERGENCY) {
                    currentState = OPENING;
                    printf("Gate is opening...\n");
                    Sr_Emerg = 0;  // Reset Sr_Emerg when exiting EMERGENCY
                } else {
                    printf("Invalid action! The gate needs to be in CLOSED or EMERGENCY to move to OPENING.\n");
                }
                break;

            case 5:  // Move to EMERGENCY
                currentState = EMERGENCY;
                printf("Emergency activated! Gate stopped.\n");
                break;

            case 6:  // Stop and exit the program
                printf("Exiting the program...\n");
                return 0;  // Exit the program

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }

        // Update the gate state and motor
        updateState();
    }

    return 0;
}
