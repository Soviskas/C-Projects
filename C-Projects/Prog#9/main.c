#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float proteins;
    float fats;
    float carbs;
    float calories;
} Product;

void inputProducts(Product products[], int *count);
void displayProducts(const Product products[], int count);
void searchProduct(const Product products[], int count);
void sortAndDisplayProducts(Product products[], int count, int criterion);
int menu();

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                inputProducts(products, &productCount);
                break;
            case 2:
                displayProducts(products, productCount);
                break;
            case 3:
                searchProduct(products, productCount);
                break;
            case 4:
                printf("1. By the amount of protein\n2. By the amount of fat\n3. By the amount of carbohydrates\n4. By calorie content\n");
                printf("Select a sorting criterion: ");
                int criterion;
                scanf("%d", &criterion);
                sortAndDisplayProducts(products, productCount, criterion);
                break;
            case 5:
                printf("Exit the program.\n");
                break;
            default:
                printf("Wrong choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void inputProducts(Product products[], int *count) {
    int n;
    printf("How many products do you want to add? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the name of the product: ");
        scanf("%s", products[*count].name);
        printf("Enter the amount of proteins (g): ");
        scanf("%f", &products[*count].proteins);
        printf("Enter the amount of fat (g): ");
        scanf("%f", &products[*count].fats);
        printf("Enter the amount of carbohydrates (g): ");
        scanf("%f", &products[*count].carbs);
        printf("Enter the calorie content (kcal): ");
        scanf("%f", &products[*count].calories);
        (*count)++;
    }
}

void displayProducts(const Product products[], int count) {
    printf("Food products:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Proteins: %.2f, Fat: %.2f, Carbohydrates: %.2f, Calories: %.2f\n",
               products[i].name, products[i].proteins, products[i].fats,
               products[i].carbs, products[i].calories);
    }
}

void searchProduct(const Product products[], int count) {
    char searchName[50];
    printf("Enter the product name to search for: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("Title: %s, Proteins: %.2f, Fat: %.2f, Carbohydrates: %.2f, Calories: %.2f\n",
                   products[i].name, products[i].proteins, products[i].fats,
                   products[i].carbs, products[i].calories);
            return;
        }
    }
    printf("Product not found.\n");
}

void sortAndDisplayProducts(Product products[], int count, int criterion) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int swap = 0;
            switch (criterion) {
                case 1:
                    if (products[i].proteins > products[j].proteins) swap = 1;
                    break;
                case 2:
                    if (products[i].fats > products[j].fats) swap = 1;
                    break;
                case 3:
                    if (products[i].carbs > products[j].carbs) swap = 1;
                    break;
                case 4:
                    if (products[i].calories > products[j].calories) swap = 1;
                    break;
                default:
                    printf("Incorrect sorting criterion.\n");
                    return;
            }
            if (swap) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    displayProducts(products, count);
}

int menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Entering information into an array of structures\n");
    printf("2. Display of all information\n");
    printf("3. Search by entered value\n");
    printf("4. Organize product lists\n");
    printf("5. Exit the program\n");
    printf("Select the menu item: ");
    scanf("%d", &choice);
    return choice;
}
