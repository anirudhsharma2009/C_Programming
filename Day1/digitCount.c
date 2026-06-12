#include <stdio.h>

int countDigits(int num) {
    if (num == 0) {
        return 1;
    }
    
    int count = 0;
    num = (num < 0) ? -num : num;  // Handle negative numbers
    
    while (num > 0) {
        count++;
        num /= 10;
    }
    
    return count;
}

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Number of digits: %d\n", countDigits(number));
    
    return 0;
}