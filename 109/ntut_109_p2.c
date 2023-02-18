#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_STUDENT 5

typedef struct {
    char id[10];
    int score;
} STUDENT;

void copy_string(char *target, char *source) {
    while (*source) {
        *target = *source; // problem 2-1
        source++;
        target++;
    }
    *target = '\0';
}

void sawp1(STUDENT s1, STUDENT s2) {
    STUDENT temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

void sawp2(STUDENT *s1, STUDENT *s2){
    STUDENT temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void foo(STUDENT *students) {
    for (int i = 0; i < NUM_OF_STUDENT; i++) {
        for (int j = i+1; j < NUM_OF_STUDENT; j++) {
            if (students[i].score > students[j].score) {
                // sawp1(*(students+i), *(students+j)); // problem 2-2
                sawp1(students[i], students[j]);
            }
        }
    }

    printf("foo\n");
    for (int  i = 0; i < NUM_OF_STUDENT; i++)
    {
        printf("students.id: %s, students.score: %d\n", students[i].id, students[i].score);
    }
    printf("\n");
}

void bar(STUDENT *students) {
    for (int i = 0; i < NUM_OF_STUDENT; i++) {
        for (int j = i+1; j < NUM_OF_STUDENT; j++) {
            if (students[i].score < students[j].score) {
                sawp2(students+i,students+j); // problem 2-3 or sawp2(&students[i],&students[j]);
            }
        }
    }

    printf("bar\n");
    for (int  i = 0; i < NUM_OF_STUDENT; i++)
    {
        printf("students.id: %s, students.score: %d\n", students[i].id, students[i].score);
    }

    printf("\n");
}

int main(){
    char *ids [NUM_OF_STUDENT] = {"t001", "t002", "t003", "t004", "t005" };
    int scores [NUM_OF_STUDENT] = {85, 70, 95, 60, 75 };
    STUDENT *students;
    students = (STUDENT *) malloc(NUM_OF_STUDENT * sizeof (STUDENT) ); // problem 2-4

    //initialize each student's id and score
    for(int i = 0; i < NUM_OF_STUDENT; i++) {
        copy_string(students[i].id, ids[i]);
        (students+i)->score = scores[i]; // problem 2-5
        printf("students.id: %s, students.score: %d\n", students[i].id, students[i].score);
    }

    printf("\n");

    foo(students);
    printf("problem 2-6: %s\n", students[0].id);

    bar (students);
    printf("problem 2-7: %s\n", students[0].id);
    return 0;
}

