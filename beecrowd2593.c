#include <stdio.h>
#include <string.h>

void readInput(char *input);
void readWords(char words[][200], unsigned wordCount);
void tokenText(char text[][200], char *input, unsigned *textCount);
void findWordPositions(char text[][200], unsigned textCount, char words[][200], unsigned wordCount);

int main() {
  char input[10050];
  char text[10050][200];
  char words[200][200];
  unsigned wordCount, textCount;

  readInput(input);
  scanf("%*c%u", &wordCount);

  readWords(words, wordCount);
  tokenText(text, input, &textCount);
  findWordPositions(text, textCount, words, wordCount);

  return 0;
}

void readInput(char *input) {
  scanf(" %[^\n]", input);
}

void readWords(char words[][200], unsigned wordCount) {
  for (unsigned i = 0; i < wordCount; ++i)
    scanf("%s", words[i]);
}

void tokenText(char text[][200], char *input, unsigned *textCount) {
  char *token = strtok(input, " ");
  *textCount = 0;
  while (token) {
    strcpy(text[(*textCount)++], token);
    token = strtok(0, " ");
  }
}

void findWordPositions(char text[][200], unsigned textCount, char words[][200], unsigned wordCount) {
  for (unsigned k = 0; k < wordCount; ++k) {
    unsigned position = 0;
    int found = 1;
    for (unsigned j = 0; j < textCount; ++j) {
      if (strcmp(text[j], words[k]) == 0) {
        if (!found)
          printf(" %u", position);
        else
          printf("%u", position), found = 0;
      }
      position += strlen(text[j]) + 1;
    }
    if (found)
      printf("-1\n");
    else
      printf("\n");
  }
}
