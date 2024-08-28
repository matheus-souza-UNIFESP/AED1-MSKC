#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
} String;

void Sort(String *students, int size);

int main() {
    int i;
    int numStudents, awardStudent;

    scanf("%d %d", &numStudents, &awardStudent);
    String students[numStudents];

    for (i = 0; i < numStudents; i++)
        scanf("%s", students[i].name);

    Sort(students, numStudents);
    
    printf("%s\n", students[awardStudent - 1].name);

    return 0;
}

void Sort(String *students, int size) {
    int i = 1, j;
    String pivot;

    while (i < size) {
        j = i - 1;
        pivot = students[i];

        while (j >= 0 && strcmp(students[j].name, pivot.name) > 0) {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = pivot;
        i++;
    }
}