#include <stdio.h>
#include <ctype.h>

int main(void) {
    char sentence[1000];
    int count = 0;
    int inWord = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isspace((unsigned char)sentence[i])) {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        count++;
    }

    printf("Number of words: %d\n", count);
    return 0;
}
