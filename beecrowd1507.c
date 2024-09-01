#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubstring(char *string1, char *string2);

int main() {
  int i, j;
  char string[100060];
  char substring[1100];
  int numCases, numStrings;

  scanf("%d", &numCases);
  scanf("%s", string);

  for (i = 0; i < numCases; ++i) {
    scanf("%d", &numStrings);

    for (j = 0; j < numStrings; ++j) {
      scanf("%s", substring);

      if (isSubstring(substring, string))
        printf("Yes\n");
      else
        printf("No\n");
    }

    scanf("%s", string);
  }

  return 0;
}

bool isSubstring(char *string1, char *string2) {
  int i, j;
  int length1, length2;

  length1 = strlen(string1);
  length2 = strlen(string2);

  for (i = 0, j = 0; i < length2 && j < length1; i++)
    if (string1[j] == string2[i])
      j++;

  if (j == length1)
    return true;
  else
    return false;
}