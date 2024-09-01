#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Word {
    char japanese[500];
    char portuguese[500];
} Word;

bool search(Word *dictionary, char *word, int size);
int compare(const void *a, const void *b);
int position;

void main() {
    int i;
    int numWords;
    int numLines, cases;
    char sentence[500] = {0}, *tempWord;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d", &numWords, &numLines);

        Word dictionary[numWords];

        for (i = 0; i < numWords; i++) {
            scanf(" %[^\n]", dictionary[i].japanese);
            scanf(" %[^\n]", dictionary[i].portuguese);
        }

        qsort(dictionary, numWords, sizeof(Word), compare);

        while (numLines--) {
            scanf(" %[^\n]", sentence);

            if (!strlen(sentence))
                printf("\n");
            else {
                tempWord = strtok(sentence, " ");

                if (search(dictionary, tempWord, numWords))
                    printf("%s", dictionary[position].portuguese);
                else
                    printf("%s", tempWord);

                while ((tempWord = strtok(NULL, " ")) != NULL) {
                    printf(" ");
                    if (search(dictionary, tempWord, numWords))
                        printf("%s", dictionary[position].portuguese);
                    else
                        printf("%s", tempWord);
                }
            }

            printf("\n");
            memset(sentence, 0, sizeof(sentence));
        }

        printf("\n");
    }
}

bool search(Word *dictionary, char *word, int size) {
    int start = 0, end = size - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (strcmp(dictionary[mid].japanese, word) < 0)
            start = mid + 1;
        else if (strcmp(dictionary[mid].japanese, word) > 0)
            end = mid - 1;
        else {
            position = mid;
            return true;
        }
    }

    return false;
}

int compare(const void *a, const void *b) {
    return strcmp((*(Word *)a).japanese, (*(Word *)b).japanese);
}