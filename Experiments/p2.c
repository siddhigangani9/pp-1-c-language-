#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    char category[30];
    float price;
    int isIssued; // 0 for available, 1 for issued
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayAllBooks();
void searchBook();
void issueBook();
void returnBook();
void displayAvailableBooks();
void displayIssuedBooks();
void loadFromFile();
void saveToFile();

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary database is full!\n");
        return;
    }
    struct Book b;
    b.id = bookCount + 1; // Auto-increment ID or manual input
    printf("\nEnter Book Title: ");
    getchar(); // clear newline
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;

    printf("Enter Category: ");
    fgets(b.category, sizeof(b.category), stdin);
    b.category[strcspn(b.category, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &b.price);

    b.isIssued = 0;
    library[bookCount++] = b;
    saveToFile();
    printf("\nBook added successfully! Assigned ID: %d\n", b.id);
}

void displayAllBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\n--- All Book Records ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Category: %s | Price: %.2f | Status: %s\n",
               library[i].id, library[i].title, library[i].author,
               library[i].category, library[i].price,
               library[i].isIssued ? "Issued" : "Available");
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books to search.\n");
        return;
    }
    int choice, id, found = 0;
    char query[50];

    printf("\nSearch by:\n1. ID\n2. Title\n3. Author\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        for (int i = 0; i < bookCount; i++) {
            if (library[i].id == id) {
                printf("Found: ID: %d | Title: %s | Author: %s | Status: %s\n",
                       library[i].id, library[i].title, library[i].author, library[i].isIssued ? "Issued" : "Available");
                found = 1;
                break;
            }
        }
    } else {
        printf("Enter search query: ");
        getchar();
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = 0;

        for (int i = 0; i < bookCount; i++) {
            if ((choice == 2 && strcasecmp(library[i].title, query) == 0) ||
                (choice == 3 && strcasecmp(library[i].author, query) == 0)) {
                printf("Found: ID: %d | Title: %s | Author: %s | Status: %s\n",
                       library[i].id, library[i].title, library[i].author, library[i].isIssued ? "Issued" : "Available");
                found = 1;
            }
        }
    }
    if (!found) printf("\nNo matching book found.\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued) {
                printf("\nBook is already issued!\n");
            } else {
                library[i].isIssued = 1;
                saveToFile();
                printf("\nBook issued successfully!\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].isIssued) {
                printf("\nBook was not issued!\n");
            } else {
                library[i].isIssued = 0;
                saveToFile();
                printf("\nBook returned successfully!\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}

void displayAvailableBooks() {
    printf("\n--- Available Books ---\n");
    int count = 0;
    for (int i = 0; i < bookCount; i++) {
        if (!library[i].isIssued) {
            printf("ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
            count++;
        }
    }
    if (count == 0) printf("No available books.\n");
}

void displayIssuedBooks() {
    printf("\n--- Issued Books ---\n");
    int count = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isIssued) {
            printf("ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
            count++;
        }
    }
    if (count == 0) printf("No issued books.\n");
}

void saveToFile() {
    FILE *file = fopen("library.dat", "wb");
    if (file) {
        fwrite(&bookCount, sizeof(int), 1, file);
        fwrite(library, sizeof(struct Book), bookCount, file);
        fclose(file);
    }
}

void loadFromFile() {
    FILE *file = fopen("library.dat", "rb");
    if (file) {
        fread(&bookCount, sizeof(int), 1, file);
        fread(library, sizeof(struct Book), bookCount, file);
        fclose(file);
    }
}

int main() {
    loadFromFile();
    int choice;
    do {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n2. Display All Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Display Available Books\n7. Display Issued Books\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayAllBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: displayAvailableBooks(); break;
            case 7: displayIssuedBooks(); break;
            case 8: printf("\nExiting program.\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 8);
    return 0;
}
