#include <stdio.h>

void reverseNumber(int num) {
    if (num == 0) {
        return;
    }
    printf("%d", num % 10);
    reverseNumber(num / 10);
}

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Reversed number: ");
    reverseNumber(number);
    printf("\n");
    
    return 0;
}
