#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left = 0, right;

    printf("Enter a string: ");
    scanf("%s", str);

    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            printf("Not a palindrome\n");
            return 0;
        }
        left++;
        right--;
    }

    printf("Palindrome\n");
    return 0;
}
