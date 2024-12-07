/*
#include <stdio.h>

int main() {

    int productNumber, quantity;
    double price, total = 0;
    int moreProducts;

    printf("Product number | Price per unit of goods\n");
    printf("1            | 29 grn. 80 cop.\n");
    printf("2            | 45 grn. 50 cop.\n");
    printf("3            | 9 grn. 98 cop.\n");
    printf("4            | 44 grn. 90 cop.\n");
    printf("5            | 67 grn. 80 cop.\n");

    do {
        printf("Enter the product number: ");
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
                continue;
        }

        printf("Product number %d – price: %.2f grn – quantity: %d – payable to: %.2f grn\n", productNumber, price, quantity, price * quantity);
        total += price * quantity;

        printf("Would you like to add another product? (1 - yes, 0 - no): ");
        scanf("%d", &moreProducts);
    } while (moreProducts);

    printf("\nTotal purchase amount: %.2f grn\n", total);

    return 0;
}
*/

//Програма з використанням циклу for

/*
#include <stdio.h>
#include <math.h>

int main() {

    double x, sum = 0, term;
    int k, count = 0;
    const double s = 1e-4;

    printf("Enter the value x (-2 < x < 2): ");
    scanf("%lf", &x);

    for (k = 1, term = pow(x, 3*k + 1) / (3*k * tgamma(k + 2)); fabs(term) > s; k++) {
        term = pow(-1, k - 1) * pow(x, 3*k + 1) / (3*k * tgamma(k + 2));
        sum += term;
        count++;
    }

    printf("Sum of a series: %.10f\n", sum);
    printf("Number of addends: %d\n", count);

    return 0;
}
*/

//Програма з використанням циклу while

/*
#include <stdio.h>
#include <math.h>

int main() {

    double x, sum = 0, term;
    int k = 1, count = 0;
    const double s = 1e-4;

    printf("Enter the value x (-2 < x < 2): ");
    scanf("%lf", &x);

    term = pow(-1, k - 1) * pow(x, 3*k + 1) / (3*k * tgamma(k + 2));
    while (fabs(term) > s) {
        sum += term;
        k++;
        term = pow(-1, k - 1) * pow(x, 3*k + 1) / (3*k * tgamma(k + 2));
        count++;
    }

    printf("Sum of a series: %.10f\n", sum);
    printf("Number of addends: %d\n", count);

    return 0;
}
*/

//Програма з використанням циклу do/while


#include <stdio.h>
#include <math.h>

int main() {

    double x, sum = 0, term;
    int k = 1, count = 0;
    const double s = 1e-4;

    printf("Enter the value x (-2 < x < 2): ");
    scanf("%lf", &x);

    do {
        term = pow(-1, k - 1) * pow(x, 3*k + 1) / (3*k * tgamma(k + 2));
        if (fabs(term) > s) {
            sum += term;
            count++;
        }
        k++;
    } while (fabs(term) > s);

    printf("Sum of a series: %.10f\n", sum);
    printf("Number of addends: %d\n", count);

    return 0;
}

