#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    for (i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        
        if ((ch >= 'a' && ch <= 'z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    
    return 0;
}
