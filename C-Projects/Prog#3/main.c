/*
#include <stdio.h>

int main() {

    int productNumber, quantity;
    double price, total;

    printf("Product number | Price per unit of goods\n");
    printf("1            | 29 grn. 80 cop.\n");
    printf("2            | 45 grn. 50 cop.\n");
    printf("3            | 9 grn. 98 cop.\n");
    printf("4            | 44 grn. 90 cop.\n");
    printf("5            | 67 grn. 80 cop.\n");

    printf("Enter number of product: ");
    scanf("%d", &productNumber);
    printf("Enter the quantity of goods: ");
    scanf("%d", &quantity);

    switch (productNumber) {
        case 1:
            price = 29.80;
            break;
        case 2:
            price = 45.50;
            break;
        case 3:
            price = 9.98;
            break;
        case 4:
            price = 44.90;
            break;
        case 5:
            price = 67.80;
            break;
        default:
            printf("Incorrect product number!\n");
            return 1;
    }

    total = price * quantity;
    printf("Product number %d, quantity: %d, total amount: %.2f grn.\n", productNumber, quantity, total);

    return 0;
}
*/

#include <stdio.h>

int main() {

    char letter;

    printf("Enter a letter of the English alphabet (last 10 letters): ");
    scanf(" %c", &letter);

    switch (letter) {
        case 'q': case 'w': case 'r': case 't': case 'y':
        case 'p': case 's': case 'd': case 'f': case 'g':
        case 'h': case 'j': case 'k': case 'l': case 'z':
        case 'x': case 'c': case 'v': case 'b': case 'n':
        case 'm':
            printf("This is a consonant letter.\n");
            break;
        case 'u': case 'i': case 'o': case 'a': case 'e':
            printf("This is a vowel letter.\n");
            break;
        default:
            printf("Invalid letter entered.\n");
    }

    return 0;
}
