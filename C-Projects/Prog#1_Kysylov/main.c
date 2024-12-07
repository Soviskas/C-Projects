/*#include <stdio.h>


int main() {

    printf("Last Name: Kysylov\nFirst Name: Oleksandr\nPatronymic: Vitaliyovich\nPlace of Study: NUBIP\nPlace of Residence: Ukraine\n");
    return 0;
}
*/

#include <stdio.h>
#include <math.h>

// Функція для обчислення t1
double calculate_t1(int a, int b, double c, double d, double x, double y) {
    return (1 / c) * (1 / (a * x + b) + (y / c) * log((y * x + d) / (a * x + b)));
}

// Функція для обчислення t2
double calculate_t2(int a, double x) {
    return (1.0 / a) * tan(a * x / 2) + 0.5 * log((a * x - 1) / 2);
}

int main() {
    // Задаємо початкові значення параметрів
    int a = 5;
    int b = 3;
    double c = 2.5;
    double d = 1.5;
    double x, y;

    // Введення значень x та y з клавіатури
    printf("Enter the value x: ");
    scanf("%lf", &x);
    printf("Enter the value y: ");
    scanf("%lf", &y);

    // Обчислення t1 та t2
    double t1 = calculate_t1(a, b, c, d, x, y);
    double t2 = calculate_t2(a, x);

    // Виведення результатів
    printf("Value t1: %lf\n", t1);
    printf("Value t2: %lf\n", t2);

    return 0;
}
