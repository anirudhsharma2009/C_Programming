#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (!isalnum((unsigned char)str[left])) {
            left++;
            continue;
        }
        if (!isalnum((unsigned char)str[right])) {
            right--;
            continue;
        }
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main(void)
{
    char input[256];

    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (is_palindrome(input)) {
        printf("\"%s\" is a palindrome.\n", input);
    } else {
        printf("\"%s\" is not a palindrome.\n", input);
    }

    return 0;
}
