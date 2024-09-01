#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
  char text[3000];
} String;

void sortStrings(String *words, int size);

int main() {
  int cases;
  int i, j, k;
  String words[60];
  char input[3000];

  scanf("%d", &cases);

  while (cases--) {
    memset(words, 0, sizeof(words));
    memset(input, 0, sizeof(input));
    scanf(" %[^\n]", input);

    i = j = k = 0;
    while (true) {
      while (input[i] != ' ') {
        if (input[i] == '\0') break;
        else words[j].text[k++] = input[i++];
      }

      words[j].text[k] = '\0';

      if (input[i] == '\0') break;

      i++; 
      j++;
      k = 0;
    }

    j++;
    sortStrings(words, j);

    for (i = 0; i < j; i++) {
      if (i != j && i != 0) printf(" ");
      printf("%s", words[i].text);
    }
    printf("\n");
  }

  return 0;
}

void sortStrings(String *words, int size) {
  int i = 1, j;
  String pivot;

  while (i < size) {
    j = i - 1;
    pivot = words[i];

    while (j >= 0 && strlen(words[j].text) < strlen(pivot.text)) {
      words[j + 1] = words[j];
      j--;
    }

    words[j + 1] = pivot;
    i++;
  }
}