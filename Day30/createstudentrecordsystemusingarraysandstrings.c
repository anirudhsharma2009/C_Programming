#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int rollNo;
    char name[MAX_NAME_LEN];
    float marks;
    char grade;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    
    printf("\nEnter Student Details:\n");
    printf("Roll Number: ");
    scanf("%d", &students[*count].rollNo);
    
    getchar();
    printf("Name: ");
    fgets(students[*count].name, MAX_NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;
    
    printf("Marks: ");
    scanf("%f", &students[*count].marks);
    
    if (students[*count].marks >= 90) {
        students[*count].grade = 'A';
    } else if (students[*count].marks >= 80) {
        students[*count].grade = 'B';
    } else if (students[*count].marks >= 70) {
        students[*count].grade = 'C';
    } else if (students[*count].marks >= 60) {
        students[*count].grade = 'D';
    } else {
        students[*count].grade = 'F';
    }
    
    (*count)++;
    printf("Student added successfully!\n");
}

void displayAllStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    
    printf("\n========== Student Records ==========\n");
    printf("%-5s %-20s %-10s %-8s\n", "Roll", "Name", "Marks", "Grade");
    printf("=====================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10.2f %-8c\n", 
               students[i].rollNo, students[i].name, 
               students[i].marks, students[i].grade);
    }
    printf("=====================================\n");
}

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    
    int rollNo;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\n========== Student Found ==========\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("Grade: %c\n", students[i].grade);
            printf("====================================\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", rollNo);
}

void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    
    int rollNo;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNo);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    printf("========== Student Record System ==========\n");
    
    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayAllStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                printf("\nThank you for using Student Record System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}