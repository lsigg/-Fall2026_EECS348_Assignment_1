#include <stdio.h>

int main() {
    int secret = 7;   // fixed secret number
    int guess;
    int attempts = 3;

    printf("Guess a number between 1 and 10.\n");

    int i;
    for (i = 1; i <= attempts; i++) {
        printf("Attempt %d/%d. Enter your guess: ", i, attempts);
        scanf("%d", &guess);

        if (guess == secret) {
            printf("Correct! You win!\n");
            break;
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }
    }

    if (i > attempts) {
        printf("Sorry, you lose! The number was %d.\n", secret);
    }

    return 0;
}