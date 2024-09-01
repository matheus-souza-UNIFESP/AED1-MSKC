#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char name[60];
  char color[20];
  char size;
} Shirt;

void sortBySize(Shirt *shirts, int count);
void sortByName(Shirt *shirts, int count);
void sortByColor(Shirt *shirts, int count);

int main() {
  int numShirts;
  int i;

  scanf("%d", &numShirts);

  while (true) {
    if (numShirts == 0)
      break;

    Shirt shirts[numShirts];
    for (i = 0; i < numShirts; i++) {
      scanf(" %[^\n]", shirts[i].name);
      scanf("%s %c", shirts[i].color, &shirts[i].size);
    }

    sortByName(shirts, numShirts);
    sortBySize(shirts, numShirts);
    sortByColor(shirts, numShirts);

    for (i = 0; i < numShirts; i++)
      printf("%s %c %s\n", shirts[i].color, shirts[i].size, shirts[i].name);

    scanf("%d", &numShirts);
    if (numShirts != 0)
      printf("\n");
  }

  return 0;
}

void sortByName(Shirt *shirts, int count) {
  int i = 1, j;
  Shirt pivot;

  while (i < count) {
    j = i - 1;
    pivot = shirts[i];

    while (j >= 0 && strcmp(shirts[j].name, pivot.name) > 0) {
      shirts[j + 1] = shirts[j];
      j--;
    }

    shirts[j + 1] = pivot;
    i++;
  }
}

void sortByColor(Shirt *shirts, int count) {
  int i = 1, j;
  Shirt pivot;

  while (i < count) {
    j = i - 1;
    pivot = shirts[i];

    while (j >= 0 && strcmp(shirts[j].color, pivot.color) > 0) {
      shirts[j + 1] = shirts[j];
      j--;
    }

    shirts[j + 1] = pivot;
    i++;
  }
}

void sortBySize(Shirt *shirts, int count) {
  int i = 1, j;
  Shirt pivot;

  while (i < count) {
    j = i - 1;
    pivot = shirts[i];

    while (j >= 0 && shirts[j].size < pivot.size) {
      shirts[j + 1] = shirts[j];
      j--;
    }

    shirts[j + 1] = pivot;
    i++;
  }
}