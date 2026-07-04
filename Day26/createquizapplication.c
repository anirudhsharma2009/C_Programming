
/* Simple Quiz Application */
#include <stdio.h>
#include <string.h>

#define MAX_Q 10

typedef struct {
	const char *question;
	const char *options[4];
	int correct; /* 0-based index */
} Question;

int main(void) {
	Question quiz[] = {
		{"What is the capital of France?", {"A) Berlin","B) Madrid","C) Paris","D) Rome"}, 2},
		{"Which language is primarily used for system programming?", {"A) Python","B) C","C) JavaScript","D) HTML"}, 1},
		{"Which planet is known as the Red Planet?", {"A) Earth","B) Mars","C) Jupiter","D) Venus"}, 1},
		{"What does 'CPU' stand for?", {"A) Central Program Unit","B) Central Processing Unit","C) Computer Processing Unit","D) Central Performance Unit"}, 1},
		{"Which data structure uses FIFO order?", {"A) Stack","B) Queue","C) Tree","D) Graph"}, 1}
	};

	int total = sizeof(quiz) / sizeof(quiz[0]);
	char name[100];
	int score = 0;

	printf("=== Quiz Application ===\n");
	printf("Enter your name: ");
	if (!fgets(name, sizeof(name), stdin)) return 0;
	/* remove newline */
	name[strcspn(name, "\n")] = '\0';

	printf("Hello, %s! There are %d questions. Choose A-D for each.\n\n", name, total);

	for (int i = 0; i < total; ++i) {
		printf("Question %d: %s\n", i+1, quiz[i].question);
		for (int j = 0; j < 4; ++j) printf("  %s\n", quiz[i].options[j]);

		char line[32];
		int answer = -1;
		while (1) {
			printf("Your answer: ");
			if (!fgets(line, sizeof(line), stdin)) return 0;
			if (line[0] >= 'A' && line[0] <= 'D') answer = line[0] - 'A';
			else if (line[0] >= 'a' && line[0] <= 'd') answer = line[0] - 'a';
			if (answer >=0 && answer < 4) break;
			printf("Please enter A, B, C or D.\n");
		}

		if (answer == quiz[i].correct) {
			printf("Correct!\n\n");
			score++;
		} else {
			printf("Wrong. Correct answer: %c)\n\n", (char)('A' + quiz[i].correct));
		}
	}

	printf("Quiz finished. %s, your score: %d/%d (%.1f%%)\n", name, score, total, (score * 100.0) / total);

	if (score == total) printf("Excellent! You got all answers right.\n");
	else if (score >= total/2) printf("Good job!\n");
	else printf("Keep practicing.\n");

	return 0;
}
