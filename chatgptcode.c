#include <stdio.h>

int main() {
    int secret = 7;
    int guess;
    int attempts = 0;
    int correct = 0;

    printf("Guess a number between 1 and 10.\n");

    while (attempts < 3) {
        printf("Attempt %d/3. Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < secret) {
            printf("Too low! Try again.\n");
        }
        else if (guess > secret) {
            printf("Too high! Try again.\n");
        }
        else {
            printf("Correct! You win!\n");
            correct = 1;
            break;
        }

        attempts++;
    }

    if (!correct) {
        printf("You lose! The secret number was %d.\n", secret);
    }

    return 0;
}