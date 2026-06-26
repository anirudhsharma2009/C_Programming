#include <stdio.h>

int binary_search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void) {
    int size;
    printf("Enter number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d sorted integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    int result = binary_search(arr, size, key);
    if (result >= 0) {
        printf("Value found at index %d\n", result);
    } else {
        printf("Value not found\n");
    }

    return 0;
}
