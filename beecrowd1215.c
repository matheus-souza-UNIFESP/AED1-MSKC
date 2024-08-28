#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char words[201];
} String;

bool StringExists(char *str, String *dictionary, unsigned size);
void QuickSortAlphabetical(String *dictionary, int size);
void QuickSortAlphabeticalInternal(String *dictionary, int start, int end);

int main() {
    unsigned i, j, k = 0;
    char tempInput[201], tempOutput[201];
    String dictionary[5050];

    memset(dictionary, 0, sizeof(dictionary));
    while (scanf(" %[^\n]", tempInput) != EOF) {
        i = j = 0;
        while (tempInput[i]) {
            while (isalpha(tempInput[i])) {
                tempOutput[j++] = tolower(tempInput[i++]);
            }
            if (tempInput[i] == '\0') {
                tempOutput[j] = '\0';
                if (!StringExists(tempOutput, dictionary, k)) {
                    strcpy(dictionary[k++].words, tempOutput);
                }
                j = 0;
                memset(tempOutput, 0, sizeof(tempOutput));
                break;
            }
            tempOutput[j] = '\0';
            while (!isalpha(tempInput[i])) {
                i++;
                if (tempInput[i] == '\0') break;
            }
            if (!StringExists(tempOutput, dictionary, k)) {
                strcpy(dictionary[k++].words, tempOutput);
            }
            j = 0;
            memset(tempOutput, 0, sizeof(tempOutput));
        }
        memset(tempInput, 0, sizeof(tempInput));
    }

    QuickSortAlphabetical(dictionary, k);

    j = 0;
    if (strcmp(dictionary[0].words, "\0") == 0) j = 1;
    for (; j < k; j++) {
        printf("%s\n", dictionary[j].words);
    }

    return 0;
}

bool StringExists(char *str, String *dictionary, unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++) {
        if (strcmp(dictionary[i].words, str) == 0) return true;
    }
    return false;
}

void QuickSortAlphabeticalInternal(String *dictionary, int start, int end) {
    String pivot, temp;
    int i, j;
    if (end - start > 0) {
        if (start < end) {
            i = start;
            j = end;
            pivot = dictionary[(i + j) / 2];
            do {
                while (strcmp(dictionary[i].words, pivot.words) < 0) i++;
                while (strcmp(dictionary[j].words, pivot.words) > 0) j--;
                if (i <= j) {
                    temp = dictionary[i];
                    dictionary[i] = dictionary[j];
                    dictionary[j] = temp;
                    i++;
                    j--;
                }
            } while (i <= j);
            QuickSortAlphabeticalInternal(dictionary, start, j);
            QuickSortAlphabeticalInternal(dictionary, i, end);
        }
    }
}

void QuickSortAlphabetical(String *dictionary, int size) {
    QuickSortAlphabeticalInternal(dictionary, 0, size - 1);
}