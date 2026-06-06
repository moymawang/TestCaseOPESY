#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct {
    int id;
    char name[50];
    float grade;
} Student;


void inputStudents(Student students[], int *n) {
    printf("Enter number of students: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }
}


void displayStudents(Student students[], int n) {
    printf("\n--- Student List ---\n");

    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Grade: %.2f\n",
               students[i].id,
               students[i].name,
               students[i].grade);
    }
}


void sortByGrade(Student students[], int n) {
    Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (students[i].grade < students[j].grade) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


int searchStudent(Student students[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}


int main() {
    Student students[MAX];
    int n;

    inputStudents(students, &n);

    sortByGrade(students, n);

    displayStudents(students, n);

    int searchId;
    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);

    int index = searchStudent(students, n, searchId);

    if (index != -1) {
        printf("Found: %s with grade %.2f\n",
               students[index].name,
               students[index].grade);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}