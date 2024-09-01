#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char name[30];
  char originalSignature[30];
} Student;

bool validateSignature(Student *classroom, char *classSignature, unsigned short position, unsigned short size);
unsigned short findStudent(Student *classroom, char *name, unsigned short size);

int main() {
  unsigned short numStudents, numPresentStudents;
  unsigned short i, numFalseSignatures;
  char studentName[30], classSignature[30];

  while (true) {
    scanf("%hu", &numStudents);

    if (numStudents == 0)
      break;

    Student classroom[numStudents];

    for (i = 0; i < numStudents; i++)
      scanf(" %s %s", classroom[i].name, classroom[i].originalSignature);

    scanf("%hu", &numPresentStudents);

    numFalseSignatures = 0;
    for (i = 0; i < numPresentStudents; i++) {
      scanf("%s %s", studentName, classSignature);

      if (!validateSignature(classroom, classSignature, findStudent(classroom, studentName, numStudents), numStudents))
        numFalseSignatures++;
    }

    printf("%hu\n", numFalseSignatures);
  }

  return 0;
}

bool validateSignature(Student *classroom, char *classSignature, unsigned short position, unsigned short size) {
  unsigned short i = 0;
  unsigned short numDifferences = 0;

  while (classroom[position].originalSignature[i]) {
    if (classroom[position].originalSignature[i] != classSignature[i])
      numDifferences++;

    i++;
  }

  return numDifferences <= 1;
}

unsigned short findStudent(Student *classroom, char *name, unsigned short size) {
  unsigned short i;

  for (i = 0; i < size; i++) {
    if (strcmp(classroom[i].name, name) == 0)
      return i;
  }

  return size;
}