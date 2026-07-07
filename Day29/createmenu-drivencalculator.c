#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;
    double a, b, result;

    while (1) {
        printf("Menu-driven Calculator\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 5) {
            printf("Exiting calculator.\n");
            break;
        }

        printf("Enter first number: ");
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        printf("Enter second number: ");
        if (scanf("%lf", &b) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                result = a + b;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                result = a - b;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                result = a * b;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = a / b;
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
