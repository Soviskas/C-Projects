//�������� 1: ���������� �������� � �����������
/*
#include <stdio.h>

int main() {
    // 1.1. ��'����� ���� ������� ���� number1 (number1 = 7.3) � number2
    float number1 = 7.3, number2;

    // 1.2. ��'����� �������� fPtr �� ��� float
    float *fPtr;

    // 1.3. �������� ������ ����� number1 ��������� fPtr
    fPtr = &number1;

    // 1.4. ������� �������� ������, �� ���� ���������� fPtr
    printf("The value referenced by fPtr: %.2f\n", *fPtr);

    // 1.5. �������� �������� ������, �� ���� ���������� fPtr, ����� number2
    number2 = *fPtr;

    // 1.6. ������� �������� number2
    printf("Value number2: %.2f\n", number2);

    // 1.7. ������� ������ number1
    printf("Address number1: %p\n", (void *)&number1);

    // 1.8. ������� ������, ��������� � ��������� fPtr
    printf("Address, stored in the index fPtr: %p\n", (void *)fPtr);

    // 1.9. ������� ������ ��������� fPtr
    printf("Address of index fPtr: %p\n", (void *)&fPtr);

    return 0;
}
*/
//�������� 2: ������ � �������� � �����������
/*
#include <stdio.h>

int main() {
    // �) ��'����� ����� ���� ���� � ��'�� values, ���� ���������� � 5-�� ��������; ��������� �������� ������ ������� ������� �� 2 �� 10
    int values[5] = {2, 4, 6, 8, 10};

    // �) ��'����� �������� ptrV �� ��'��� ���� int
    int *ptrV;

    // �) ������� �������� ������ values �� ������������� ��������� �� �������� ������ �� ������� ��'� ������/������
    printf("Array elements (array name/index):\n");
    for (int i = 0; i < 5; i++) {
        printf("values[%d] = %d\n", i, values[i]);
    }

    // �) �������� ��� ���������, �� ��������� ���� ����� �������� ��������� ������ ������ values ��������� ptrV
    ptrV = values;
    ptrV = &values[0];

    // �) ������� �������� ������ values �� ������� ��������/����
    printf("\nArray screams (pointer/offset):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptrV + %d) = %d\n", i, *(ptrV + i));
    }

    // �) ������� �������� ������ values, �������������� ������ � ���������� �� �����
    printf("\nArray elements (index with a pointer to the array):\n");
    for (int i = 0; i < 5; i++) {
        printf("ptrV[%d] = %d\n", i, ptrV[i]);
    }

    // �) ������� ������, �� ��� ���������� ����� ptrV+3, �� �������� �� ���� �������
    printf("\nAddress ptrV+3: %p\n", (void *)(ptrV + 3));
    printf("Values at the address ptrV+3: %d\n", *(ptrV + 3));

    // �) �������� ptrV ������ values[4] �� ������� �������� ������� �������� ������, �������������� ptrV
    ptrV = &values[4];
    printf("\nThe value of the first element of the array, using ptrV (ptrV = &values[4]): %d\n", *ptrV);

    return 0;
}
*/
//�������� 3: ������� ��� ���������� ������ ���������� ����� � �����,
//������� �� K
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
            index = i + 1;  // ������ � 1
        }
    }
    return index;
}
