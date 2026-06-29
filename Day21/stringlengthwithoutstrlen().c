#include <stdio.h>

int main() {
    char str[100];
    int length = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Calculate length without using strlen()
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n') {  // Exclude newline character from count
            length++;
        }
    }
    
    printf("Length of string: %d\n", length);
    
    return 0;
}
