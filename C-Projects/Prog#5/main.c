//Завдання 1: Програма, яка перевіряє виклики функцій математичної бібліотеки
/*
#include <stdio.h>
#include <math.h>

void printMathFunctions(double x, double y);

int main() {

    double x = 5.0, y = 2.0;
    printMathFunctions(x, y);

    return 0;
}

void printMathFunctions(double x, double y) {
    printf("Function         | Appointment                            | Example\n");
    printf("-------------------------------------------------------------\n");
    printf("sqrt(x)         | Square root                            | sqrt(%.2f) = %.2f\n", x, sqrt(x));
    printf("exp(x)          | Exhibitor (e^x)                        | exp(%.2f) = %.2f\n", x, exp(x));
    printf("log(x)          | Natural logarithm                      | log(%.2f) = %.2f\n", x, log(x));
    printf("fabs(x)         | Absolute value                         | fabs(%.2f) = %.2f\n", x, fabs(x));
    printf("pow(x, y)       | Promotion to degree                    | pow(%.2f, %.2f) = %.2f\n", x, y, pow(x, y));
    printf("sin(x)          | Sine                                   | sin(%.2f) = %.2f\n", x, sin(x));
    printf("cos(x)          | Cosine                                 | cos(%.2f) = %.2f\n", x, cos(x));
    printf("tan(x)          | Tangents                               | tan(%.2f) = %.2f\n", x, tan(x));
    printf("fmod(x, y)      | Remainder from division                | fmod(%.2f, %.2f) = %.2f\n", x, y, fmod(x, y));
}
*/

//Завдання 2: Написати функцію invertDigit


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int invertDigit(int num);

int main() {

    int num;
    char ch;

    do {
        printf("Enter a positive integer: ");
        scanf("%d", &num);

        printf("Reverse order of digits: %d\n", invertDigit(num));

        printf("Press 'ESC' to exit or any other key to continue...\n");
        ch = _getch();
    } while (ch != 27);  // 27 - код клавіші ESC

    return 0;
}

int invertDigit(int num) {
    int inverted = 0;

    while (num > 0) {
        inverted = inverted * 10 + (num % 10);
        num /= 10;
    }

    return inverted;
}
