#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define DATA_FILE "library.dat"

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
    int available; // 1 = available, 0 = borrowed
} Book;

Book books[MAX_BOOKS];
int count = 0;
int next_id = 1;

void trim_newline(char *s) {
    size_t l = strlen(s);
    if (l > 0 && s[l-1] == '\n') s[l-1] = '\0';
}

void load_data() {
    FILE *f = fopen(DATA_FILE, "rb");
    if (!f) return;
    if (fread(&count, sizeof(count), 1, f) != 1) { fclose(f); return; }
    if (fread(&next_id, sizeof(next_id), 1, f) != 1) { fclose(f); return; }
    if (count > 0 && count <= MAX_BOOKS) {
        fread(books, sizeof(Book), count, f);
    }
    fclose(f);
}

void save_data() {
    FILE *f = fopen(DATA_FILE, "wb");
    if (!f) return;
    fwrite(&count, sizeof(count), 1, f);
    fwrite(&next_id, sizeof(next_id), 1, f);
    if (count > 0) fwrite(books, sizeof(Book), count, f);
    fclose(f);
}

void add_book() {
    if (count >= MAX_BOOKS) { printf("Library full.\n"); return; }
    Book b;
    b.id = next_id++;
    printf("Enter title: ");
    fgets(b.title, TITLE_LEN, stdin); trim_newline(b.title);
    printf("Enter author: ");
    fgets(b.author, AUTHOR_LEN, stdin); trim_newline(b.author);
    printf("Enter year: ");
    if (scanf("%d", &b.year) != 1) { while (getchar()!='\n'); b.year = 0; }
    while (getchar()!='\n');
    b.available = 1;
    books[count++] = b;
    printf("Book added with ID %d\n", b.id);
}

void list_books() {
    if (count == 0) { printf("No books in library.\n"); return; }
    printf("%-4s %-30s %-20s %-6s %-10s\n", "ID", "Title", "Author", "Year", "Status");
    for (int i = 0; i < count; ++i) {
        printf("%-4d %-30.30s %-20.20s %-6d %-10s\n", books[i].id, books[i].title, books[i].author, books[i].year, books[i].available?"Available":"Borrowed");
    }
}

int find_index_by_id(int id) {
    for (int i = 0; i < count; ++i) if (books[i].id == id) return i;
    return -1;
}

void search_book() {
    char term[TITLE_LEN];
    printf("Enter title or part of title to search: ");
    fgets(term, TITLE_LEN, stdin); trim_newline(term);
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (strcasestr(books[i].title, term) != NULL) {
            if (!found) printf("Matches:\n");
            printf("%d: %s by %s (%d) - %s\n", books[i].id, books[i].title, books[i].author, books[i].year, books[i].available?"Available":"Borrowed");
            found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}

void borrow_book() {
    int id; printf("Enter book ID to borrow: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); printf("Invalid input.\n"); return; }
    while (getchar()!='\n');
    int idx = find_index_by_id(id);
    if (idx < 0) { printf("Book not found.\n"); return; }
    if (!books[idx].available) { printf("Book already borrowed.\n"); return; }
    books[idx].available = 0; printf("Book borrowed.\n");
}

void return_book() {
    int id; printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); printf("Invalid input.\n"); return; }
    while (getchar()!='\n');
    int idx = find_index_by_id(id);
    if (idx < 0) { printf("Book not found.\n"); return; }
    if (books[idx].available) { printf("Book is not marked borrowed.\n"); return; }
    books[idx].available = 1; printf("Book returned.\n");
}

void remove_book() {
    int id; printf("Enter book ID to remove: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); printf("Invalid input.\n"); return; }
    while (getchar()!='\n');
    int idx = find_index_by_id(id);
    if (idx < 0) { printf("Book not found.\n"); return; }
    for (int i = idx; i < count-1; ++i) books[i] = books[i+1];
    count--; printf("Book removed.\n");
}

int menu() {
    printf("\nMini Library System\n");
    printf("1. Add book\n2. List books\n3. Search by title\n4. Borrow book\n5. Return book\n6. Remove book\n7. Exit\n");
    printf("Choose option: ");
    int opt; if (scanf("%d", &opt) != 1) { while (getchar()!='\n'); return -1; }
    while (getchar()!='\n');
    return opt;
}

int main(void) {
    load_data();
    int opt;
    while (1) {
        opt = menu();
        if (opt == 1) add_book();
        else if (opt == 2) list_books();
        else if (opt == 3) search_book();
        else if (opt == 4) borrow_book();
        else if (opt == 5) return_book();
        else if (opt == 6) remove_book();
        else if (opt == 7) { save_data(); break; }
        else printf("Invalid option.\n");
    }
    return 0;
}
