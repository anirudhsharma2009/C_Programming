#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void addContact(struct Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("Enter name: ");
    readLine(contacts[*count].name, sizeof(contacts[*count].name));
    printf("Enter phone: ");
    readLine(contacts[*count].phone, sizeof(contacts[*count].phone));
    printf("Enter email: ");
    readLine(contacts[*count].email, sizeof(contacts[*count].email));
    printf("Enter address: ");
    readLine(contacts[*count].address, sizeof(contacts[*count].address));

    (*count)++;
    printf("Contact added successfully.\n\n");
}

void listContacts(const struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s\n", i + 1, contacts[i].name);
        printf("   Phone: %s\n", contacts[i].phone);
        printf("   Email: %s\n", contacts[i].email);
        printf("   Address: %s\n\n", contacts[i].address);
    }
}

void searchContact(const struct Contact contacts[], int count) {
    char query[50];
    printf("Enter name to search: ");
    readLine(query, sizeof(query));

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, query) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n\n", contacts[i].address);
            return;
        }
    }

    printf("Contact not found.\n\n");
}

void deleteContact(struct Contact contacts[], int *count) {
    if (*count == 0) {
        printf("No contacts to delete.\n\n");
        return;
    }

    char query[50];
    printf("Enter name to delete: ");
    readLine(query, sizeof(query));

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(contacts[i].name, query) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully.\n\n");
            return;
        }
    }

    printf("Contact not found.\n\n");
}

int main(void) {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("Contact Management System\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            scanf("%*s");
            choice = 0;
        }
        getchar();

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                listContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}
