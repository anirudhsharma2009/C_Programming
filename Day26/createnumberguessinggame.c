/* Number Guessing Game
 * Simple console-based game where the player tries to guess
 * a randomly generated number within a range.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secret, guess, attempts = 0;
    const int MIN = 1;
    const int MAX = 100;

    /* initialize random seed */
    srand((unsigned)time(NULL));
    secret = (rand() % (MAX - MIN + 1)) + MIN;

    printf("Welcome to Number Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d.\n", MIN, MAX);
    printf("Enter your guesses. Type 0 to quit.\n");

    while (1) {
        printf("Your guess: ");
        if (scanf("%d", &guess) != 1) {
            /* invalid input - clear stdin and continue */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Please enter a valid integer.\n");
            continue;
        }

        if (guess == 0) {
            printf("You quit. The number was %d.\n", secret);
            break;
        }

        attempts++;

        if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed it in %d attempt%s.\n",
                   attempts, attempts == 1 ? "" : "s");
            break;
        }
    }

    return 0;
}
