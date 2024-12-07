//Завдання 1: Одномірний масив цілих чисел
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillArray(int arr[], int size);
void printEvenIndexElementsAndSum(int arr[], int size);

int main() {
    int arr[SIZE];
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    fillArray(arr, SIZE);
    printEvenIndexElementsAndSum(arr, SIZE);

    return 0;
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Заповнення масиву випадковими числами від 0 до 99
    }
}

void printEvenIndexElementsAndSum(int arr[], int size) {
    int sum = 0;
    printf("Elements with even indexes: ");
    for (int i = 2; i < size; i += 2) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\nSum of elements with even indices: %d\n", sum);
}
*/

//Завдання 2: Перетворення матриці розміру nxm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void fillMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m);
void swapRowsWithMinMaxElements(int matrix[MAX_ROWS][MAX_COLS], int n, int m);

int main() {
    int n, m;
    int matrix[MAX_ROWS][MAX_COLS];
    char ch;

    do {
        printf("Enter the number of lines (n): ");
        scanf("%d", &n);
        printf("Enter the number of columns (m): ");
        scanf("%d", &m);

        fillMatrix(matrix, n, m);
        printf("Initial matrix:\n");
        printMatrix(matrix, n, m);

        swapRowsWithMinMaxElements(matrix, n, m);
        printf("Matrix after rearranging rows:\n");
        printMatrix(matrix, n, m);

        printf("Press 'ESC' to exit or any other key to repeat...\n");
        ch = getchar();
        getchar();  // для читання 'Enter'
    } while (ch != 27);  // 27 - код клавіші ESC

    return 0;
}

void fillMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;  // Заповнення матриці випадковими числами від 0 до 99
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void swapRowsWithMinMaxElements(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
    int minVal = matrix[0][0], maxVal = matrix[0][0];
    int minRow = 0, maxRow = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }

    if (minRow != maxRow) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[minRow][j];
            matrix[minRow][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
    }
}
