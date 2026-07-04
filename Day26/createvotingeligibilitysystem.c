/* Voting Eligibility System
   Simple console program to determine if applicants are eligible to vote.
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    printf("How many applicants? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // consume leftover newline after reading integer
    int ch = getchar();
    (void)ch;

    for (int i = 0; i < n; ++i) {
        char name[100];
        int age;
        char citizen[10];
        char convicted[10];

        printf("\nApplicant %d:\n", i+1);
        printf("Name: ");
        if (!fgets(name, sizeof(name), stdin)) break;
        name[strcspn(name, "\r\n")] = '\0';

        printf("Age: ");
        if (scanf("%d", &age) != 1) { printf("Invalid age.\n"); return 1; }

        printf("Are you a citizen? (yes/no): ");
        if (scanf("%9s", citizen) != 1) { printf("Input error.\n"); return 1; }

        printf("Are you currently serving a sentence or convicted of disenfranchising crime? (yes/no): ");
        if (scanf("%9s", convicted) != 1) { printf("Input error.\n"); return 1; }

        // clear input buffer before next fgets
        while ((ch = getchar()) != '\n' && ch != EOF) ;

        int isCitizen = (strcmp(citizen, "yes") == 0 || strcmp(citizen, "Yes") == 0);
        int isConvicted = (strcmp(convicted, "yes") == 0 || strcmp(convicted, "Yes") == 0);

        printf("\nResult for %s:\n", name);
        if (age < 18) {
            printf("Not eligible to vote: must be at least 18 years old.\n");
        } else if (!isCitizen) {
            printf("Not eligible to vote: citizenship required.\n");
        } else if (isConvicted) {
            printf("Not eligible to vote: convicted and disenfranchised.\n");
        } else {
            printf("Eligible to vote.\n");
        }
    }

    return 0;
}
