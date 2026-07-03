#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq1[26] = {0}, freq2[26] = {0};
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    // Count frequency of characters in first string
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            freq1[str1[i] - 'a']++;
        } else if (str1[i] >= 'A' && str1[i] <= 'Z') {
            freq1[str1[i] - 'A']++;
        }
    }
    
    // Count frequency of characters in second string
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            freq2[str2[i] - 'a']++;
        } else if (str2[i] >= 'A' && str2[i] <= 'Z') {
            freq2[str2[i] - 'A']++;
        }
    }
    
    // Find and print common characters
    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            printf("%c ", 'a' + i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No common characters found");
    }
    printf("\n");
    
    return 0;
}