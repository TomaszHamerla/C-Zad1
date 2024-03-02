#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 2

int main() {
    int grades[SUBJECTS][STUDENTS];
    float averages[SUBJECTS] = {0};


    printf("Podaj oceny uczniow:\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Uczen %d:\n", i+1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Ocena z przedmiotu %s: ", j == 0 ? "matematyki" : "fizyki");
            scanf("%d", &grades[j][i]);
        }
    }


    for (int i = 0; i < SUBJECTS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            averages[i] += grades[i][j];
        }
        averages[i] /= STUDENTS;
    }


    printf("\nSrednie ocen:\n");
    printf("Matematyka: %.2f\n", averages[0]);
    printf("Fizyka: %.2f\n", averages[1]);

    return 0;
}
