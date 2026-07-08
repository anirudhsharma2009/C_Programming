#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    Employee emp;
    emp.id = (*count == 0) ? 1 : employees[*count - 1].id + 1;

    printf("Enter employee name: ");
    getchar();
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter salary: ");
    scanf("%f", &emp.salary);

    employees[*count] = emp;
    (*count)++;

    printf("Employee added successfully with ID %d.\n", emp.id);
}

void displayAll(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-15s %.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

int findEmployeeById(Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchEmployee(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees available.\n");
        return;
    }

    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
    } else {
        printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n",
               employees[index].id,
               employees[index].name,
               employees[index].department,
               employees[index].salary);
    }
}

void updateEmployee(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees available to update.\n");
        return;
    }

    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    printf("Enter new name (leave blank to keep current): ");
    getchar();
    char input[50];
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(employees[index].name, input);
    }

    printf("Enter new department (leave blank to keep current): ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(employees[index].department, input);
    }

    printf("Enter new salary (0 to keep current): ");
    float salary;
    scanf("%f", &salary);
    if (salary > 0) {
        employees[index].salary = salary;
    }

    printf("Employee record updated successfully.\n");
}

void deleteEmployee(Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employees available to delete.\n");
        return;
    }

    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    int index = findEmployeeById(employees, *count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    (*count)--;

    printf("Employee deleted successfully.\n");
}

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\nMini Employee Management System\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Update employee\n");
        printf("5. Delete employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayAll(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                updateEmployee(employees, count);
                break;
            case 5:
                deleteEmployee(employees, &count);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
