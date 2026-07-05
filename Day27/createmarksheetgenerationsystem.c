#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100], regno[50];
    int marks[6];
    const char *subjects[6] = {"Mathematics", "Physics", "Chemistry", "English", "Computer", "Biology"};
    int i, total = 0;
    float percentage;
    char grade[3];

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    if (name[strlen(name)-1] == '\n') name[strlen(name)-1] = '\0';

    printf("Enter registration no: ");
    if (!fgets(regno, sizeof(regno), stdin)) return 0;
    if (regno[strlen(regno)-1] == '\n') regno[strlen(regno)-1] = '\0';

    for (i = 0; i < 6; ++i) {
        do {
            printf("Enter marks for %s (0-100): ", subjects[i]);
            if (scanf("%d", &marks[i]) != 1) {
                // clear invalid input
                int c; while ((c = getchar()) != EOF && c != '\n');
                marks[i] = -1;
            }
        } while (marks[i] < 0 || marks[i] > 100);
        total += marks[i];
    }

    percentage = (float)total / 6.0f;

    if (percentage >= 90) strcpy(grade, "A+");
    else if (percentage >= 80) strcpy(grade, "A");
    else if (percentage >= 70) strcpy(grade, "B+");
    else if (percentage >= 60) strcpy(grade, "B");
    else if (percentage >= 50) strcpy(grade, "C");
    else if (percentage >= 40) strcpy(grade, "D");
    else strcpy(grade, "F");

    printf("\n================= MARKSHEET =================\n");
    printf("Name       : %s\n", name);
    printf("Reg. No.   : %s\n", regno);
    printf("--------------------------------------------\n");
    printf("%-15s %-10s\n", "Subject", "Marks");
    printf("--------------------------------------------\n");
    for (i = 0; i < 6; ++i) {
        printf("%-15s %3d/100\n", subjects[i], marks[i]);
    }
    printf("--------------------------------------------\n");
    printf("Total      : %3d/600\n", total);
    printf("Percentage : %.2f%%\n", percentage);
    printf("Grade      : %s\n", grade);
    printf("============================================\n");

    return 0;
}
