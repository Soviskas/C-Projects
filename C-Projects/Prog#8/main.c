////Завдання 1: Алгоритми для роботи із символами
//1.1. Для цілого числа N (32 ≤ N ≤ 126) вивести символ з кодом, рівним N.

/*
#include <stdio.h>

int main() {
    int N;
    printf("Enter an integer N (32 <= N <= 126): ");
    scanf("%d", &N);
    if (N >= 32 && N <= 126) {
        printf("Symbol with a code %d: %c\n", N, (char)N);
    } else {
        printf("The number is not in the specified range.\n");
    }
    return 0;
}
*/

//1.2. Для символу C вивести два символи, перший з яких передує символу C в кодовій таблиці, а другий слідує за символом C.

/*
#include <stdio.h>

int main() {
    char C;
    printf("Enter the character C: ");
    scanf(" %c", &C);
    printf("The symbol before %c: %c\n", C, C - 1);
    printf("The symbol after %c: %c\n", C, C + 1);
    return 0;
}
*/

//1.3. Для цілого числа N (1 ≤ N ≤ 26) вивести N перших прописних (великих) букв латинського алфавіту.

/*
#include <stdio.h>

int main() {
    int N;
    printf("Enter an integer N (1 <= N <= 26): ");
    scanf("%d", &N);
    if (N >= 1 && N <= 26) {
        for (int i = 0; i < N; i++) {
            printf("%c ", 'A' + i);
        }
        printf("\n");
    } else {
        printf("The number is not in the specified range.\n");
    }
    return 0;
}
*/

//1.4. Для цілого числа N (1 ≤ N ≤ 26) вивести N останніх рядкових (маленьких) букв латинського алфавіту в зворотному порядку.

/*
#include <stdio.h>

int main() {
    int N;
    printf("Enter an integer N (1 <= N <= 26): ");
    scanf("%d", &N);
    if (N >= 1 && N <= 26) {
        for (int i = 0; i < N; i++) {
            printf("%c ", 'z' - i);
        }
        printf("\n");
    } else {
        printf("The number is not in the specified range.\n");
    }
    return 0;
}
*/

//1.5. Для символу C вивести рядок «digit», якщо він зображує цифру, та рядок «alpha», якщо він зображує букву.

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char C;
    printf("Enter the character C: ");
    scanf(" %c", &C);
    if (isdigit(C)) {
        printf("digit\n");
    } else if (isalpha(C)) {
        printf("alpha\n");
    } else {
        printf("Neither a number nor a letter.\n");
    }
    return 0;
}
*/

//1.6. Програма, що дозволяє користувачеві ввести символ та отримати повну інформацію про нього.

/*
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

void printCharInfo(char C);

int main() {
    char C;
    printf("Enter a character (press ESC to exit):\n");
    while ((C = _getch()) != 27) {  // 27 - код клавіші ESC
        printf("Symbol: %c\n", C);
        printCharInfo(C);
    }
    return 0;
}

void printCharInfo(char C) {
    printf("Symbol code: %d\n", C);
    if (isalpha(C)) {
        printf("This is the letter\n");
    } else if (isdigit(C)) {
        printf("This is a number\n");
    } else if (ispunct(C)) {
        printf("This is a punctuation mark\n");
    } else if (iscntrl(C)) {
        printf("This is the control character\n");
    } else {
        printf("This is a different symbol\n");
    }
}
*/


//Завдання 2: Алгоритми для роботи із рядками
//Програма вводить рядок тексту у масив символів s[100] та виводить його у верхньому і нижньому регістрах.

/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100];
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    printf("Upper case: ");
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", toupper(s[i]));
    }
    printf("\n");

    printf("Lower case: ");
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", tolower(s[i]));
    }
    printf("\n");

    return 0;
}
*/

//2. Програма вводить 4 рядки, які представляють цілі значення, та перетворює їх у цілі числа, додає їх і виводить суму

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[10], s2[10], s3[10], s4[10];
    int num1, num2, num3, num4, sum;

    printf("Enter 4 integer values:\n");
    scanf("%s %s %s %s", s1, s2, s3, s4);

    num1 = atoi(s1);
    num2 = atoi(s2);
    num3 = atoi(s3);
    num4 = atoi(s4);

    sum = num1 + num2 + num3 + num4;

    printf("Sum of values: %d\n", sum);

    return 0;
}
*/

//3. Програма вводить декілька рядків тексту та символ для пошуку, визначає кількість появ цього символу.

/*
#include <stdio.h>
#include <string.h>

int main() {
    char s[500], searchChar;
    int count = 0;

    printf("Enter text (several lines):\n");
    fgets(s, sizeof(s), stdin);

    printf("Enter a character to search for: ");
    scanf(" %c", &searchChar);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == searchChar) {
            count++;
        }
    }

    printf("The character '%c' appears %d times\n", searchChar, count);

    return 0;
}
*/

//4. Програма вводить декілька рядків тексту та підраховує загальну кількість слів, використовуючи функцію strtok.

#include <stdio.h>
#include <string.h>

int main() {
    char s[500];
    printf("Enter text (several lines):\n");
    fgets(s, sizeof(s), stdin);

    char *token = strtok(s, " \n");
    int wordCount = 0;

    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " \n");
    }

    printf("Number of words: %d\n", wordCount);

    return 0;
}
