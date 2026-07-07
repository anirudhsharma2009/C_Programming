#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertAt(int arr[], int *n, int pos, int value) {
    if (*n >= MAX_SIZE) {
        return 0;
    }
    if (pos < 0 || pos > *n) {
        return 0;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    return 1;
}

int deleteAt(int arr[], int *n, int pos, int *deleted) {
    if (*n == 0 || pos < 0 || pos >= *n) {
        return 0;
    }
    *deleted = arr[pos];
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 1;
}

int search(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;
    int value;
    int pos;
    int deleted;

    while (1) {
        printf("\nMenu-driven array operations system\n");
        printf("1. Create array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Sort ascending\n");
        printf("6. Sort descending\n");
        printf("7. Display array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter number of elements (max %d): ", MAX_SIZE);
                if (scanf("%d", &n) != 1 || n < 0 || n > MAX_SIZE) {
                    printf("Invalid size.\n");
                    n = 0;
                } else {
                    for (int i = 0; i < n; i++) {
                        printf("Enter element %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                if (insertAt(arr, &n, pos, value)) {
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Insertion failed. Check position or array capacity.\n");
                }
                break;
            case 3:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (deleteAt(arr, &n, pos, &deleted)) {
                    printf("Deleted element %d from position %d.\n", deleted, pos);
                } else {
                    printf("Deletion failed. Check position or empty array.\n");
                }
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(arr, n, value);
                if (pos >= 0) {
                    printf("Element found at position %d.\n", pos);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;
            case 5:
                sortAscending(arr, n);
                printf("Array sorted in ascending order.\n");
                break;
            case 6:
                sortDescending(arr, n);
                printf("Array sorted in descending order.\n");
                break;
            case 7:
                display(arr, n);
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
