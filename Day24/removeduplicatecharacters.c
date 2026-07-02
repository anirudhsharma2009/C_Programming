
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	if (fgets(str, sizeof str, stdin) == NULL) return 0;
	size_t len = strlen(str);
	if (len && str[len-1] == '\n') str[--len] = '\0';

	int seen[256] = {0};
	char out[1000];
	size_t j = 0;
	for (size_t i = 0; i < len; ++i) {
		unsigned char c = (unsigned char)str[i];
		if (!seen[c]) {
			seen[c] = 1;
			out[j++] = str[i];
		}
	}
	out[j] = '\0';
	puts(out);
	return 0;
}
