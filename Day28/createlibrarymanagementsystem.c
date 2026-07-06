#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    int quantity;
} Book;

void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void addBook(void) {
    FILE *fp = fopen("library.dat", "ab");
    if (!fp) {
        perror("Unable to open file");
        return;
    }
    Book b;
    printf("Enter book ID: ");
    if (scanf("%d", &b.id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }
    clearInput();
    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Enter quantity: ");
    if (scanf("%d", &b.quantity) != 1) {
        clearInput();
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }
    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully.\n");
}

void displayBooks(void) {
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Book b;
    printf("\n%-6s %-30s %-20s %-8s\n", "ID", "Title", "Author", "Qty");
    printf("--------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        printf("%-6d %-30s %-20s %-8d\n", b.id, b.title, b.author, b.quantity);
    }
    fclose(fp);
}

void searchBook(void) {
    int id;
    printf("Enter book ID to search: ");
    if (scanf("%d", &id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        return;
    }
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.id == id) {
            printf("Book found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", b.id, b.title, b.author, b.quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

void updateBook(void) {
    int id;
    printf("Enter book ID to update: ");
    if (scanf("%d", &id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        return;
    }
    FILE *fp = fopen("library.dat", "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.id == id) {
            clearInput();
            printf("Enter new book title: ");
            fgets(b.title, sizeof(b.title), stdin);
            b.title[strcspn(b.title, "\n")] = '\0';
            printf("Enter new author name: ");
            fgets(b.author, sizeof(b.author), stdin);
            b.author[strcspn(b.author, "\n")] = '\0';
            printf("Enter new quantity: ");
            if (scanf("%d", &b.quantity) != 1) {
                clearInput();
                printf("Invalid input.\n");
                fclose(fp);
                return;
            }
            fseek(fp, -((long)sizeof(Book)), SEEK_CUR);
            fwrite(&b, sizeof(Book), 1, fp);
            found = 1;
            printf("Book updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

void deleteBook(void) {
    int id;
    printf("Enter book ID to delete: ");
    if (scanf("%d", &id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        return;
    }
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Unable to open temporary file");
        fclose(fp);
        return;
    }
    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.id == id) {
            found = 1;
            continue;
        }
        fwrite(&b, sizeof(Book), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    if (found) {
        remove("library.dat");
        rename("temp.dat", "library.dat");
        printf("Book deleted successfully.\n");
    } else {
        remove("temp.dat");
        printf("Book with ID %d not found.\n", id);
    }
}

void issueBook(void) {
    int id;
    printf("Enter book ID to issue: ");
    if (scanf("%d", &id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        return;
    }
    FILE *fp = fopen("library.dat", "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.id == id) {
            if (b.quantity > 0) {
                b.quantity--;
                fseek(fp, -((long)sizeof(Book)), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book issued successfully. Remaining quantity: %d\n", b.quantity);
            } else {
                printf("No copies available to issue.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

void returnBook(void) {
    int id;
    printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) {
        clearInput();
        printf("Invalid input.\n");
        return;
    }
    FILE *fp = fopen("library.dat", "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.id == id) {
            b.quantity++;
            fseek(fp, -((long)sizeof(Book)), SEEK_CUR);
            fwrite(&b, sizeof(Book), 1, fp);
            printf("Book returned successfully. Quantity now: %d\n", b.quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

int main(void) {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInput();
            choice = 0;
        }
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                issueBook();
                break;
            case 7:
                returnBook();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);
    return 0;
}
