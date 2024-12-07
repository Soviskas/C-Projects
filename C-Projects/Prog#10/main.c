#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define FILE_NAME "students.dat"

typedef struct {
    int studentID;
    char lastName[MAX_NAME];
    float averageScore;
} Student;

void createFile();
void displayAll();
void searchByID();
void addToFile();
void deleteByID();
int menu();

int main() {
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchByID();
                break;
            case 4:
                addToFile();
                break;
            case 5:
                deleteByID();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void createFile() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return;
    }

    int n;
    printf("How many students do you want to add? ");
    scanf("%d", &n);

    Student student;
    for (int i = 0; i < n; i++) {
        printf("Enter student ID: ");
        scanf("%d", &student.studentID);
        printf("Enter student last name: ");
        scanf("%s", student.lastName);
        printf("Enter student average score: ");
        scanf("%f", &student.averageScore);
        fwrite(&student, sizeof(Student), 1, file);
    }

    fclose(file);
}

void displayAll() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    Student student;
    printf("All information from file:\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Student ID: %d, Last Name: %s, Average Score: %.2f\n",
               student.studentID, student.lastName, student.averageScore);
    }

    fclose(file);
}

void searchByID() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    int studentID;
    printf("Enter student ID to search: ");
    scanf("%d", &studentID);

    Student student;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.studentID == studentID) {
            printf("Student ID: %d, Last Name: %s, Average Score: %.2f\n",
                   student.studentID, student.lastName, student.averageScore);
            fclose(file);
            return;
        }
    }

    printf("Student with ID %d not found.\n", studentID);
    fclose(file);
}

void addToFile() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.studentID);
    printf("Enter student last name: ");
    scanf("%s", student.lastName);
    printf("Enter student average score: ");
    scanf("%f", &student.averageScore);
    fwrite(&student, sizeof(Student), 1, file);

    fclose(file);
}

void deleteByID() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(file);
        return;
    }

    int studentID;
    printf("Enter student ID to delete: ");
    scanf("%d", &studentID);

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.studentID == studentID) {
            found = 1;
        } else {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student with ID %d deleted.\n", studentID);
    } else {
        printf("Student with ID %d not found.\n", studentID);
    }
}

int menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Create file and enter information\n");
    printf("2. Display all information from file\n");
    printf("3. Search information from file by key field\n");
    printf("4. Add information to file\n");
    printf("5. Delete information from file by key field\n");
    printf("6. Exit program\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}
