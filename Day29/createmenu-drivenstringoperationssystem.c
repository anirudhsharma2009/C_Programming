#include <stdio.h>
#include <string.h>
#include <ctype.h>

void readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void reverseString(char *s)
{
    size_t i, j;
    char temp;
    for (i = 0, j = strlen(s); j > 0 && i < j - 1; ++i, --j) {
        temp = s[i];
        s[i] = s[j - 1];
        s[j - 1] = temp;
    }
}

void toUpperCase(char *s)
{
    for (; *s != '\0'; ++s) {
        *s = toupper((unsigned char)*s);
    }
}

int main(void)
{
    char s1[256] = "";
    char s2[256] = "";
    int choice;
    int stringsEntered = 0;

    do {
        printf("\nMenu-driven String Operations System\n");
        printf("1. Enter strings\n");
        printf("2. Display strings\n");
        printf("3. Find length of strings\n");
        printf("4. Copy string 1 to string 2\n");
        printf("5. Concatenate strings\n");
        printf("6. Compare strings\n");
        printf("7. Reverse string 1\n");
        printf("8. Convert string 1 to uppercase\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        while (getchar() != '\n') {
        }

        switch (choice) {
            case 1:
                printf("Enter string 1: ");
                readLine(s1, sizeof(s1));
                printf("Enter string 2: ");
                readLine(s2, sizeof(s2));
                stringsEntered = 1;
                break;
            case 2:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    printf("String 1: %s\n", s1);
                    printf("String 2: %s\n", s2);
                }
                break;
            case 3:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    printf("Length of string 1: %zu\n", strlen(s1));
                    printf("Length of string 2: %zu\n", strlen(s2));
                }
                break;
            case 4:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    strcpy(s2, s1);
                    printf("String 2 after copy: %s\n", s2);
                }
                break;
            case 5:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    if (strlen(s1) + strlen(s2) < sizeof(s1)) {
                        strcat(s1, s2);
                        printf("Concatenated string 1: %s\n", s1);
                    } else {
                        printf("Result too long to concatenate into string 1.\n");
                    }
                }
                break;
            case 6:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    int cmp = strcmp(s1, s2);
                    if (cmp < 0) {
                        printf("String 1 is less than String 2.\n");
                    } else if (cmp > 0) {
                        printf("String 1 is greater than String 2.\n");
                    } else {
                        printf("String 1 is equal to String 2.\n");
                    }
                }
                break;
            case 7:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    reverseString(s1);
                    printf("Reversed string 1: %s\n", s1);
                }
                break;
            case 8:
                if (!stringsEntered) {
                    printf("Please enter strings first.\n");
                } else {
                    toUpperCase(s1);
                    printf("Uppercase string 1: %s\n", s1);
                }
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please choose a valid menu item.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
