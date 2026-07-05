// Salary Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "salary_data.dat"
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    double salary;
} Employee;

void add_employee();
void list_employees();
void search_employee();
void update_salary();
void delete_employee();

int main() {
    int choice;
    while (1) {
        printf("\nSalary Management System\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { getchar(); continue; }
        switch (choice) {
            case 1: add_employee(); break;
            case 2: list_employees(); break;
            case 3: search_employee(); break;
            case 4: update_salary(); break;
            case 5: delete_employee(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void add_employee() {
    Employee emp;
    FILE *fp = fopen(DATA_FILE, "ab");
    if (!fp) { perror("Unable to open data file"); return; }
    printf("Enter ID: ");
    if (scanf("%d", &emp.id) != 1) { fclose(fp); printf("Invalid input\n"); return; }
    getchar();
    printf("Enter name: ");
    fgets(emp.name, MAX_NAME, stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';
    printf("Enter salary: ");
    if (scanf("%lf", &emp.salary) != 1) { fclose(fp); printf("Invalid input\n"); return; }
    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added.\n");
}

void list_employees() {
    Employee emp;
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) { printf("No records found.\n"); return; }
    printf("\n%-6s %-20s %-10s\n", "ID", "Name", "Salary");
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-6d %-20s %-10.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(fp);
}

void search_employee() {
    int id; Employee emp; int found = 0;
    printf("Enter ID to search: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input\n"); return; }
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) { printf("No records found.\n"); return; }
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) {
            printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1; break;
        }
    }
    if (!found) printf("Employee not found.\n");
    fclose(fp);
}

void update_salary() {
    int id; double newSalary; Employee emp; int found = 0;
    printf("Enter ID to update: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input\n"); return; }
    FILE *fp = fopen(DATA_FILE, "r+b");
    if (!fp) { printf("No records found.\n"); return; }
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) {
            printf("Current salary: %.2f\nEnter new salary: ", emp.salary);
            if (scanf("%lf", &newSalary) != 1) { printf("Invalid input\n"); break; }
            emp.salary = newSalary;
            fseek(fp, -((long)sizeof(Employee)), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            found = 1; break;
        }
    }
    if (!found) printf("Employee not found.\n"); else printf("Salary updated.\n");
    fclose(fp);
}

void delete_employee() {
    int id; Employee emp; int found = 0;
    printf("Enter ID to delete: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input\n"); return; }
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) { printf("No records found.\n"); return; }
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) { fclose(fp); perror("Unable to create temp file"); return; }
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) { found = 1; continue; }
        fwrite(&emp, sizeof(Employee), 1, temp);
    }
    fclose(fp); fclose(temp);
    if (found) {
        remove(DATA_FILE);
        rename("temp.dat", DATA_FILE);
        printf("Employee deleted.\n");
    } else {
        remove("temp.dat");
        printf("Employee not found.\n");
    }
}
