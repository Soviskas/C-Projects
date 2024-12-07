//Завдання 1: Елементарні операції з покажчиками
/*
#include <stdio.h>

int main() {
    // 1.1. Об'явити змінні дійсного типу number1 (number1 = 7.3) і number2
    float number1 = 7.3, number2;

    // 1.2. Об'явити покажчик fPtr на тип float
    float *fPtr;

    // 1.3. Присвоїти адресу змінної number1 покажчику fPtr
    fPtr = &number1;

    // 1.4. Вивести значення даного, на який посилається fPtr
    printf("The value referenced by fPtr: %.2f\n", *fPtr);

    // 1.5. Присвоїти значення даного, на який посилається fPtr, змінній number2
    number2 = *fPtr;

    // 1.6. Вивести значення number2
    printf("Value number2: %.2f\n", number2);

    // 1.7. Вивести адресу number1
    printf("Address number1: %p\n", (void *)&number1);

    // 1.8. Вивести адресу, збережену у покажчику fPtr
    printf("Address, stored in the index fPtr: %p\n", (void *)fPtr);

    // 1.9. Вивести адресу покажчика fPtr
    printf("Address of index fPtr: %p\n", (void *)&fPtr);

    return 0;
}
*/
//Завдання 2: Робота з масивами і покажчиками
/*
#include <stdio.h>

int main() {
    // а) Об'явити масив типу ціле з ім'ям values, який складається з 5-ти елементів; ініціювати елементи масиву парними числами від 2 до 10
    int values[5] = {2, 4, 6, 8, 10};

    // б) Об'явити покажчик ptrV на об'єкт типу int
    int *ptrV;

    // в) Вивести елементи масиву values із використанням звернення до елементів масиву за методом ім'я масиву/індекс
    printf("Array elements (array name/index):\n");
    for (int i = 0; i < 5; i++) {
        printf("values[%d] = %d\n", i, values[i]);
    }

    // г) Записати два оператори, за допомогою яких можна присвоїти початкову адресу масиву values покажчику ptrV
    ptrV = values;
    ptrV = &values[0];

    // д) Вивести елементи масиву values за методом покажчик/зсув
    printf("\nArray screams (pointer/offset):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptrV + %d) = %d\n", i, *(ptrV + i));
    }

    // е) Вивести елементи масиву values, використовуючи індекс з покажчиком на масив
    printf("\nArray elements (index with a pointer to the array):\n");
    for (int i = 0; i < 5; i++) {
        printf("ptrV[%d] = %d\n", i, ptrV[i]);
    }

    // є) Вивести адресу, на яку посилається вираз ptrV+3, та значення за цією адресою
    printf("\nAddress ptrV+3: %p\n", (void *)(ptrV + 3));
    printf("Values at the address ptrV+3: %d\n", *(ptrV + 3));

    // ж) Присвоїти ptrV адресу values[4] та вивести значення першого елемента масиву, використовуючи ptrV
    ptrV = &values[4];
    printf("\nThe value of the first element of the array, using ptrV (ptrV = &values[4]): %d\n", *ptrV);

    return 0;
}
*/
//Завдання 3: Функція для визначення номера останнього числа в масиві,
//більшого за K
#include <stdio.h>

int findLastGreaterThanK(int *arr, int n, int k);

int main() {
    int n, k;
    printf("Enter the size of the array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d non-zero integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter an integer K: ");
    scanf("%d", &k);

    int index = findLastGreaterThanK(arr, n, k);
    if (index == 0) {
        printf("There are no numbers greater than %d\n", k);
    } else {
        printf("The number of the last number in the array that is greater than %d: %d\n", k, index);
    }

    return 0;
}

int findLastGreaterThanK(int *arr, int n, int k) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            index = i + 1;  // індекс з 1
        }
    }
    return index;
}
