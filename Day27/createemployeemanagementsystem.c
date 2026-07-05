#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE "employees.dat"
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[NAME_LEN];
    double salary;
} Employee;

void clear_stdin(void) { int c; while ((c = getchar()) != '\n' && c != EOF); }

int get_next_id(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    return (int)(size / sizeof(Employee)) + 1;
}

void add_employee() {
    FILE *fp = fopen(DATAFILE, "ab+");
    if (!fp) { perror("Unable to open data file"); return; }

    Employee e;
    e.id = get_next_id(fp);

    printf("Enter name: ");
    if (!fgets(e.name, NAME_LEN, stdin)) { fclose(fp); return; }
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter department: ");
    if (!fgets(e.department, NAME_LEN, stdin)) { fclose(fp); return; }
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter salary: ");
    if (scanf("%lf", &e.salary) != 1) { clear_stdin(); fclose(fp); printf("Invalid salary.\n"); return; }
    clear_stdin();

    if (fwrite(&e, sizeof(Employee), 1, fp) != 1) perror("Write error");
    else printf("Employee added with ID %d\n", e.id);
    fclose(fp);
}

void list_employees() {
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No records found.\n"); return; }
    Employee e;
    printf("%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("--------------------------------------------------------\n");
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        printf("%-5d %-20s %-15s %-10.2f\n", e.id, e.name, e.department, e.salary);
    }
    fclose(fp);
}

long find_offset_by_id(FILE *fp, int id) {
    rewind(fp);
    Employee e;
    long idx = 0;
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.id == id) return idx * sizeof(Employee);
        idx++;
    }
    return -1;
}

void view_employee() {
    int id;
    printf("Enter employee ID to view: ");
    if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid ID.\n"); return; }
    clear_stdin();
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No records.\n"); return; }
    long off = find_offset_by_id(fp, id);
    if (off < 0) { printf("Employee not found.\n"); fclose(fp); return; }
    fseek(fp, off, SEEK_SET);
    Employee e;
    fread(&e, sizeof(Employee), 1, fp);
    printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", e.id, e.name, e.department, e.salary);
    fclose(fp);
}

void update_employee() {
    int id;
    printf("Enter employee ID to update: ");
    if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid ID.\n"); return; }
    clear_stdin();
    FILE *fp = fopen(DATAFILE, "rb+");
    if (!fp) { printf("No records.\n"); return; }
    long off = find_offset_by_id(fp, id);
    if (off < 0) { printf("Employee not found.\n"); fclose(fp); return; }
    fseek(fp, off, SEEK_SET);
    Employee e;
    fread(&e, sizeof(Employee), 1, fp);

    printf("Updating employee (leave blank to keep current)\n");
    char buffer[NAME_LEN];
    printf("Name [%s]: ", e.name);
    if (fgets(buffer, NAME_LEN, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer)) strncpy(e.name, buffer, NAME_LEN);
    }
    printf("Department [%s]: ", e.department);
    if (fgets(buffer, NAME_LEN, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer)) strncpy(e.department, buffer, NAME_LEN);
    }
    printf("Salary [%.2f]: ", e.salary);
    if (fgets(buffer, NAME_LEN, stdin)) {
        if (sscanf(buffer, "%lf", &e.salary) != 1 && strlen(buffer) > 0) printf("Invalid salary input; keeping old value.\n");
    }
    fseek(fp, off, SEEK_SET);
    if (fwrite(&e, sizeof(Employee), 1, fp) != 1) perror("Update error");
    else printf("Employee updated.\n");
    fclose(fp);
}

void delete_employee() {
    int id;
    printf("Enter employee ID to delete: ");
    if (scanf("%d", &id) != 1) { clear_stdin(); printf("Invalid ID.\n"); return; }
    clear_stdin();
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No records.\n"); return; }
    FILE *tmp = fopen(".tmp_employees", "wb");
    if (!tmp) { fclose(fp); perror("Unable to create temp file"); return; }
    Employee e; int found = 0;
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.id == id) { found = 1; continue; }
        fwrite(&e, sizeof(Employee), 1, tmp);
    }
    fclose(fp); fclose(tmp);
    if (!found) { remove(".tmp_employees"); printf("Employee not found.\n"); return; }
    remove(DATAFILE);
    rename(".tmp_employees", DATAFILE);
    printf("Employee deleted.\n");
}

int main(void) {
    int choice;
    for (;;) {
        printf("\nEmployee Management System\n");
        printf("1. Add employee\n2. List employees\n3. View employee\n4. Update employee\n5. Delete employee\n6. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) { clear_stdin(); printf("Invalid choice.\n"); continue; }
        clear_stdin();
        switch (choice) {
            case 1: add_employee(); break;
            case 2: list_employees(); break;
            case 3: view_employee(); break;
            case 4: update_employee(); break;
            case 5: delete_employee(); break;
            case 6: printf("Goodbye.\n"); return 0;
            default: printf("Invalid option.\n");
        }
    }
    return 0;
}
