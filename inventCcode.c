#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a product
typedef struct {
    char name[50];
    int id;
    int stock;
    float price;
} Product;

// Define an array to store products
Product inventory[50];
int num_products = 0;

// Function to add a new product to the inventory
void add_product() {
    Product new_product;
    printf("Enter the product name: ");
    scanf("%s", new_product.name);
    printf("Enter the product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter the product price: ");
    scanf("%f", &new_product.price);
    printf("Enter the product stock level: ");
    scanf("%d", &new_product.stock);
    inventory[num_products] = new_product;
    num_products++;
    printf("Product added successfully!\n");
}

// Function to update the stock level of a product
void update_stock() {
    int product_id;
    int new_stock;
    printf("Enter the product ID: ");
    scanf("%d", &product_id);
    printf("Enter the new stock level: ");
    scanf("%d", &new_stock);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == product_id) {
            inventory[i].stock = new_stock;
            printf("Stock level updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to generate a sales report
void generate_report() {
    float total_sales = 0.0;
    printf("Product ID\tProduct Name\tPrice\t\tStock\tSales\n");
    for (int i = 0; i < num_products; i++) {
        float sales = inventory[i].price * inventory[i].stock;
        printf("%d\t\t%s\t\t%.2f\t\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock, sales);
        total_sales += sales;
    }
    printf("Total Sales: %.2f\n", total_sales);
}

int main() {
    int choice;
    while (1) {
        printf("Inventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Stock\n");
        printf("3. Generate Sales Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                update_stock();
                break;
            case 3:
                generate_report();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
