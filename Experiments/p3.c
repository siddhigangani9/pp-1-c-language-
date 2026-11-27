#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MIN_STOCK_LEVEL 5
#define FILE_NAME "inventory.dat"

struct Product {
    int id;
    char name[50];
    char category[30];
    int quantity;
    float unitPrice;
    char stockStatus[20];
};

void updateStockStatus(struct Product *p) {
    if (p->quantity <= 0) {
        strcpy(p->stockStatus, "Out of Stock");
    } else if (p->quantity <= MIN_STOCK_LEVEL) {
        strcpy(p->stockStatus, "Low Stock");
    } else {
        strcpy(p->stockStatus, "In Stock");
    }
}

void saveToFile(struct Product products[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(products, sizeof(struct Product), count, file);
        fclose(file);
    }
}

int loadFromFile(struct Product products[]) {
    int count = 0;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        fread(&count, sizeof(int), 1, file);
        fread(products, sizeof(struct Product), count, file);
        fclose(file);
    }
    return count;
}

void addProduct(struct Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    struct Product p;
    p.id = *count + 1; // Auto-generate ID
    printf("Enter Product Name: ");
    scanf(" %[^\n]s", p.name);
    printf("Enter Category: ");
    scanf(" %[^\n]s", p.category);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Unit Price: ");
    scanf("%f", &p.unitPrice);

    updateStockStatus(&p);
    products[*count] = p;
    (*count)++;
    saveToFile(products, *count);
    printf("Product added successfully! Assigned ID: %d\n", p.id);
}

void displayProducts(struct Product products[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n%-5s %-20s %-15s %-10s %-12s %-15s\n", "ID", "Name", "Category", "Qty", "Price", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        updateStockStatus(&products[i]);
        printf("%-5d %-20s %-15s %-10d %-12.2f %-15s\n",
            products[i].id, products[i].name, products[i].category,
            products[i].quantity, products[i].unitPrice, products[i].stockStatus);
    }
}

void searchProduct(struct Product products[], int count) {
    int choice, id, found = 0;
    char name[50];
    printf("Search by: 1. ID  2. Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Product ID: ");
        scanf("%d", &id);
        for (int i = 0; i < count; i++) {
            if (products[i].id == id) {
                printf("\nFound: ID: %d | Name: %s | Qty: %d | Price: %.2f | Status: %s\n",
                    products[i].id, products[i].name, products[i].quantity, products[i].unitPrice, products[i].stockStatus);
                found = 1;
                break;
            }
        }
    } else {
        printf("Enter Product Name: ");
        scanf(" %[^\n]s", name);
        for (int i = 0; i < count; i++) {
            if (strcasecmp(products[i].name, name) == 0) {
                printf("\nFound: ID: %d | Name: %s | Qty: %d | Price: %.2f | Status: %s\n",
                    products[i].id, products[i].name, products[i].quantity, products[i].unitPrice, products[i].stockStatus);
                found = 1;
            }
        }
    }
    if (!found) printf("Product not found.\n");
}

void updateStock(struct Product products[], int count) {
    int id, qtyChange;
    printf("Enter Product ID to update stock: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Current Quantity: %d\nEnter quantity to add (positive) or remove (negative): ", products[i].quantity);
            scanf("%d", &qtyChange);
            products[i].quantity += qtyChange;
            if (products[i].quantity < 0) products[i].quantity = 0;
            updateStockStatus(&products[i]);
            saveToFile(products, count);
            printf("Stock updated successfully! New Qty: %d\n", products[i].quantity);
            return;
        }
    }
    printf("Product ID not found.\n");
}

void checkLowStock(struct Product products[], int count) {
    int found = 0;
    printf("\n--- Low Stock / Out of Stock Alerts ---\n");
    for (int i = 0; i < count; i++) {
        updateStockStatus(&products[i]);
        if (products[i].quantity <= MIN_STOCK_LEVEL) {
            printf("ID: %d | Name: %s | Qty Left: %d | Status: %s\n",
                products[i].id, products[i].name, products[i].quantity, products[i].stockStatus);
            found = 1;
        }
    }
    if (!found) printf("All stock levels are adequate.\n");
}

void generateBill(struct Product products[], int count) {
    int id, qty, more = 1;
    float grandTotal = 0;

    printf("\n===== CUSTOMER BILL =====\n");
    printf("%-20s %-10s %-12s %-12s\n", "Item", "Qty", "Price", "Total");
    printf("--------------------------------------------------\n");

    while (more) {
        printf("Enter Product ID to purchase: ");
        scanf("%d", &id);
        printf("Enter Quantity: ");
        scanf("%d", &qty);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (products[i].id == id) {
                found = 1;
                if (products[i].quantity >= qty) {
                    products[i].quantity -= qty;
                    float totalCost = qty * products[i].unitPrice;
                    grandTotal += totalCost;
                    printf("%-20s %-10d %-12.2f %-12.2f\n", products[i].name, qty, products[i].unitPrice, totalCost);
                    updateStockStatus(&products[i]);
                } else {
                    printf("Insufficient stock! Available: %d\n", products[i].quantity);
                }
                break;
            }
        }
        if (!found) printf("Invalid Product ID.\n");

        printf("Add another item? (1 for Yes, 0 for No): ");
        scanf("%d", &more);
    }

    saveToFile(products, count);
    printf("--------------------------------------------------\n");
    printf("GRAND TOTAL: %.2f\n", grandTotal);
    printf("==================================================\n");
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int count = loadFromFile(products);
    int choice;

    do {
        printf("\n--- Shop Inventory & Billing System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Check Low Stock\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(products, &count); break;
            case 2: displayProducts(products, count); break;
            case 3: searchProduct(products, count); break;
            case 4: updateStock(products, count); break;
            case 5: checkLowStock(products, count); break;
            case 6: generateBill(products, count); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
