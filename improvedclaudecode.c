#include <stdio.h>

#define MAX_ATTEMPTS 3

int main() {
    int secret = 7;
    int guess;
    int hasWon = 0;

    printf("Guess a number between 1 and 10.\n");

    for (int attempts = 1; attempts <= MAX_ATTEMPTS; attempts++) {
        printf("Attempt %d/%d. Enter your guess: ", attempts, MAX_ATTEMPTS);

        // Validate input; clear buffer on bad input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // clear invalid input
            attempts--;  // don't count this as a used attempt
            continue;
        }

        if (guess == secret) {
            printf("Correct! You win!\n");
            hasWon = 1;
            break;
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }
    }

    if (!hasWon) {
        printf("Sorry, you lose! The number was %d.\n", secret);
    }

    return 0;
}