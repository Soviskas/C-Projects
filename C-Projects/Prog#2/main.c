/*
// Програма з використанням структури if/else
#include <stdio.h>

int main() {

    int x;
    double y;

    printf("Enter value x: ");
    scanf("%d", &x);

    if (x < -1) {
        y = x * x - 2;
    } else if (x > 1) {
        y = x * x * x * x - x * x + 2;
    } else {
        y = 0;  // Значення y для проміжку [-1, 1] не визначено, тому ставимо 0
    }

    printf("y = %.2f\n", y);

    return 0;
}
*/
// Програма з використанням логічних операцій

#include <stdio.h>

int main() {

    int x;
    double y;

    printf("Enter value x: ");
    scanf("%d", &x);

    if (x <= -1 || x >= 1) {
        y = (x < -1) ? (x * x - 2) : (x * x * x * x - x * x + 2);
    } else {
        y = 0;  // Значення y для проміжку [-1, 1] не визначено, тому ставимо 0
    }

    printf("y = %.2f\n", y);

    return 0;
}

