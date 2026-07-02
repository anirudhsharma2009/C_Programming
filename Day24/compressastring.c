
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simple run-length compression: consecutive characters are replaced by char+count
// Example: aaabb -> a3b2
int main(void) {
	char s[1000];
	if (!fgets(s, sizeof(s), stdin)) return 0;
	size_t len = strlen(s);
	if (len > 0 && s[len-1] == '\n') s[--len] = '\0';

	if (len == 0) {
		printf("\n");
		return 0;
	}

	char *out = malloc(len * 3 + 16);
	if (!out) return 1;
	size_t oi = 0;

	for (size_t i = 0; i < len; ) {
		char c = s[i];
		size_t j = i + 1;
		while (j < len && s[j] == c) j++;
		size_t count = j - i;
		out[oi++] = c;
		oi += sprintf(out + oi, "%zu", count);
		i = j;
	}
	out[oi] = '\0';
	printf("%s\n", out);
	free(out);
	return 0;
}

