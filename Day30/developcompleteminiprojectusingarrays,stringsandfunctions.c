/*
 Mini Project: Student Record Management
 Features:
 - Use arrays, strings and functions
 - Add student records
 - Display all records
 - Search by ID or name
 - Update and delete records
 - Sort by name
 - Simple file save/load
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define FILENAME "students.dat"

typedef struct {
	int id;
	char name[NAME_LEN];
	int age;
	float gpa;
	int valid; // 1 = used, 0 = empty/deleted
} Student;

Student db[MAX_STUDENTS];
int count = 0;

void init_db() {
	for (int i = 0; i < MAX_STUDENTS; ++i) db[i].valid = 0;
	count = 0;
}

int find_free_index() {
	for (int i = 0; i < MAX_STUDENTS; ++i) if (!db[i].valid) return i;
	return -1;
}

void add_student() {
	int idx = find_free_index();
	if (idx == -1) { printf("Database full.\n"); return; }
	Student s;
	printf("Enter ID: "); if (scanf("%d", &s.id) != 1) { while (getchar()!='\n'); printf("Invalid input\n"); return; }
	getchar();
	printf("Enter name: "); fgets(s.name, NAME_LEN, stdin); s.name[strcspn(s.name, "\n")] = '\0';
	printf("Enter age: "); if (scanf("%d", &s.age) != 1) { while (getchar()!='\n'); printf("Invalid input\n"); return; }
	printf("Enter GPA: "); if (scanf("%f", &s.gpa) != 1) { while (getchar()!='\n'); printf("Invalid input\n"); return; }
	s.valid = 1;
	db[idx] = s;
	count++;
	printf("Student added.\n");
}

void display_student(const Student *s) {
	if (!s || !s->valid) return;
	printf("ID: %d\nName: %s\nAge: %d\nGPA: %.2f\n-----------------\n", s->id, s->name, s->age, s->gpa);
}

void display_all() {
	int found = 0;
	for (int i = 0; i < MAX_STUDENTS; ++i) if (db[i].valid) { display_student(&db[i]); found = 1; }
	if (!found) printf("No records.\n");
}

int search_by_id(int id) {
	for (int i = 0; i < MAX_STUDENTS; ++i) if (db[i].valid && db[i].id == id) return i;
	return -1;
}

void search_menu() {
	int choice; printf("Search by: 1) ID 2) Name\nChoice: "); if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); return; }
	getchar();
	if (choice == 1) {
		int id; printf("Enter ID: "); if (scanf("%d", &id) != 1) { while (getchar()!='\n'); return; }
		int idx = search_by_id(id);
		if (idx == -1) printf("Not found.\n"); else display_student(&db[idx]);
	} else if (choice == 2) {
		char q[NAME_LEN]; printf("Enter name (substring): "); fgets(q, NAME_LEN, stdin); q[strcspn(q, "\n")]='\0';
		int found = 0;
		for (int i = 0; i < MAX_STUDENTS; ++i) if (db[i].valid && strstr(db[i].name, q)) { display_student(&db[i]); found = 1; }
		if (!found) printf("No matches.\n");
	}
}

void update_student() {
	int id; printf("Enter ID to update: "); if (scanf("%d", &id) != 1) { while (getchar()!='\n'); return; }
	int idx = search_by_id(id);
	if (idx == -1) { printf("Not found.\n"); return; }
	getchar();
	printf("Enter new name (blank to keep): "); char tmp[NAME_LEN]; fgets(tmp, NAME_LEN, stdin); tmp[strcspn(tmp, "\n")]='\0'; if (strlen(tmp)) strcpy(db[idx].name, tmp);
	printf("Enter new age (0 to keep): "); int a; if (scanf("%d", &a) == 1 && a>0) db[idx].age = a;
	printf("Enter new GPA (-1 to keep): "); float g; if (scanf("%f", &g) == 1 && g>=0.0f) db[idx].gpa = g;
	printf("Updated.\n");
}

void delete_student() {
	int id; printf("Enter ID to delete: "); if (scanf("%d", &id) != 1) { while (getchar()!='\n'); return; }
	int idx = search_by_id(id);
	if (idx == -1) { printf("Not found.\n"); return; }
	db[idx].valid = 0; count--;
	printf("Deleted.\n");
}

int cmp_name(const void *a, const void *b) {
	const Student *sa = (const Student*)a; const Student *sb = (const Student*)b;
	if (!sa->valid && !sb->valid) return 0;
	if (!sa->valid) return 1;
	if (!sb->valid) return -1;
	return strcasecmp(sa->name, sb->name);
}

void sort_by_name() {
	qsort(db, MAX_STUDENTS, sizeof(Student), cmp_name);
	printf("Sorted by name.\n");
}

void save_file() {
	FILE *f = fopen(FILENAME, "wb");
	if (!f) { printf("Save failed.\n"); return; }
	fwrite(db, sizeof(Student), MAX_STUDENTS, f);
	fclose(f); printf("Saved to %s\n", FILENAME);
}

void load_file() {
	FILE *f = fopen(FILENAME, "rb");
	if (!f) { printf("No save found.\n"); return; }
	fread(db, sizeof(Student), MAX_STUDENTS, f);
	fclose(f);
	int c = 0; for (int i=0;i<MAX_STUDENTS;++i) if (db[i].valid) c++;
	count = c;
	printf("Loaded %d records.\n", count);
}

void menu() {
	for (;;) {
		printf("\n--- Student DB ---\n1) Add\n2) Display All\n3) Search\n4) Update\n5) Delete\n6) Sort by name\n7) Save\n8) Load\n9) Exit\nChoose: ");
		int ch; if (scanf("%d", &ch) != 1) { while (getchar()!='\n'); continue; }
		getchar();
		switch (ch) {
			case 1: add_student(); break;
			case 2: display_all(); break;
			case 3: search_menu(); break;
			case 4: update_student(); break;
			case 5: delete_student(); break;
			case 6: sort_by_name(); break;
			case 7: save_file(); break;
			case 8: load_file(); break;
			case 9: printf("Exiting.\n"); return;
			default: printf("Invalid.\n");
		}
	}
}

int main(void) {
	init_db();
	printf("Complete Mini Project Using Arrays, Strings, and Functions\n");
	menu();
	return 0;
}
