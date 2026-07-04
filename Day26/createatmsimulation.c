#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

int main(void) {
    double balance = 1000.00; /* initial balance */
    char pin[10] = "1234";    /* default PIN */
    char entered[32];
    int attempts = 3;

    printf("Welcome to Simple ATM Simulation\n");

    while (attempts > 0) {
        printf("Enter PIN: ");
        if (fgets(entered, sizeof(entered), stdin) == NULL) return 0;
        /* strip newline */
        entered[strcspn(entered, "\n")] = '\0';

        if (strcmp(entered, pin) == 0) break;
        attempts--;
        printf("Invalid PIN. Attempts left: %d\n", attempts);
    }

    if (attempts == 0) {
        printf("Too many failed attempts. Card blocked.\n");
        return 0;
    }

    for (;;) {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clear_input();
            continue;
        }
        clear_input();

        if (choice == 1) {
            printf("Current balance: $%.2f\n", balance);
        } else if (choice == 2) {
            double amt;
            printf("Enter amount to withdraw: $");
            if (scanf("%lf", &amt) != 1) {
                printf("Invalid amount.\n");
                clear_input();
                continue;
            }
            clear_input();
            if (amt <= 0) {
                printf("Enter a positive amount.\n");
            } else if (amt > balance) {
                printf("Insufficient funds.\n");
            } else {
                balance -= amt;
                printf("Please collect your cash. New balance: $%.2f\n", balance);
            }
        } else if (choice == 3) {
            double amt;
            printf("Enter amount to deposit: $");
            if (scanf("%lf", &amt) != 1) {
                printf("Invalid amount.\n");
                clear_input();
                continue;
            }
            clear_input();
            if (amt <= 0) {
                printf("Enter a positive amount.\n");
            } else {
                balance += amt;
                printf("Deposit successful. New balance: $%.2f\n", balance);
            }
        } else if (choice == 4) {
            char old[32], nw[32], nw2[32];
            printf("Enter current PIN: ");
            if (fgets(old, sizeof(old), stdin) == NULL) continue;
            old[strcspn(old, "\n")] = '\0';
            if (strcmp(old, pin) != 0) {
                printf("Incorrect PIN.\n");
                continue;
            }
            printf("Enter new PIN: ");
            if (fgets(nw, sizeof(nw), stdin) == NULL) continue;
            nw[strcspn(nw, "\n")] = '\0';
            printf("Confirm new PIN: ");
            if (fgets(nw2, sizeof(nw2), stdin) == NULL) continue;
            nw2[strcspn(nw2, "\n")] = '\0';
            if (strcmp(nw, nw2) != 0) {
                printf("PINs do not match.\n");
            } else if (strlen(nw) == 0) {
                printf("PIN cannot be empty.\n");
            } else {
                strncpy(pin, nw, sizeof(pin)-1);
                pin[sizeof(pin)-1] = '\0';
                printf("PIN changed successfully.\n");
            }
        } else if (choice == 5) {
            printf("Thank you. Goodbye.\n");
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
