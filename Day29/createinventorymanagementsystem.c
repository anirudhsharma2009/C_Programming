#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    printf("\n--- Add Item ---\n");
    printf("Enter Item ID: ");
    scanf("%d", &inventory[itemCount].id);
    
    printf("Enter Item Name: ");
    scanf(" %[^\n]", inventory[itemCount].name);
    
    printf("Enter Quantity: ");
    scanf("%d", &inventory[itemCount].quantity);
    
    printf("Enter Price: ");
    scanf("%f", &inventory[itemCount].price);
    
    itemCount++;
    printf("Item added successfully!\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("%-5s %-20s %-10s %-10s\n", "---", "----", "--------", "-----");
    
    for (int i = 0; i < itemCount; i++) {
        printf("%-5d %-20s %-10d $%.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void searchItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    
    printf("\n--- Search Item ---\n");
    int searchId;
    printf("Enter Item ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void updateItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    
    printf("\n--- Update Item ---\n");
    int searchId;
    printf("Enter Item ID to update: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    
    printf("\n--- Delete Item ---\n");
    int searchId;
    printf("Enter Item ID to delete: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void menu() {
    int choice;
    
    while (1) {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("\nExiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
