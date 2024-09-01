#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char role[20];
  unsigned commission;
} Role;

typedef struct {
  char word[300];
} Word;

bool findWord(Role *roles, char *word, int size);
int position;

void main() {
  int numWords, numRoles;
  char text[10000], *tempWord;
  unsigned long totalSalary;
  Word dictionary[10000];
  int i, j;

  scanf("%d %d", &numWords, &numRoles);

  Role roles[numWords];
  memset(roles, 0, sizeof(roles));

  for (i = 0; i < numWords; i++)
    scanf(" %s %u", roles[i].role, &roles[i].commission);

  while (numRoles--) {
    totalSalary = 0;
    while (true) {
      scanf(" %[^\n]", text);

      if (strcmp(text, ".") == 0)
        break;

      i = 0;
      tempWord = strtok(text, " ");
      strcpy(dictionary[i++].word, tempWord);

      do {
        tempWord = strtok(NULL, " ");
        if (tempWord)
          strcpy(dictionary[i++].word, tempWord);
      } while (tempWord);

      for (j = 0; j < i; j++)
        if (findWord(roles, dictionary[j].word, numWords))
          totalSalary += roles[position].commission;
    }

    printf("%lu\n", totalSalary);
  }
}

bool findWord(Role *roles, char *word, int size) {
  int i;

  for (i = 0; i < size; i++)
    if (strcmp(roles[i].role, word) == 0) {
      position = i;
      return true;
    }

  return false;
}