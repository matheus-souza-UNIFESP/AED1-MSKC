#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char ascii;
  int frequency;
} CharData;

void quickSortInternal(CharData *charArray, int start, int end);
void quickSort(CharData *charArray, int size);
void insertionSort(CharData *charArray, int size);

int main() {
  int i, j, k, z = 0;
  char text[1001];
  int frequency;
  bool seen[1001];
  CharData charArray[1001];

  while (scanf(" %[^\n]", text) != EOF) {
    k = 0;
    memset(seen, false, sizeof(seen));

    for (i = 0; text[i]; i++) {
      frequency = 0;

      if (!seen[i]) {
        for (j = 0; text[j]; j++) {
          if (text[i] == text[j]) {
            seen[j] = true;
            frequency++;
          }
        }

        charArray[k].ascii = text[i];
        charArray[k].frequency = frequency;
        k++;
      }
    }

    quickSort(charArray, k);
    insertionSort(charArray, k);

    if (z) printf("\n");
    else z++;

    for (i = 0; i < k; i++)
      printf("%d %d\n", charArray[i].ascii, charArray[i].frequency);
  }

  return 0;
}

void quickSortInternal(CharData *charArray, int start, int end) {
  CharData pivot, temp;
  int i, j;

  if (start < end) {
    i = start;
    j = end;
    pivot = charArray[(i + j) / 2];

    do {
      while (charArray[i].ascii > pivot.ascii) i++;
      while (charArray[j].ascii < pivot.ascii) j--;

      if (i <= j) {
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        i++; 
        j--;
      }
    } while (i <= j);

    quickSortInternal(charArray, start, j);
    quickSortInternal(charArray, i, end);
  }
}

void quickSort(CharData *charArray, int size) {
  quickSortInternal(charArray, 0, size - 1);
}

void insertionSort(CharData *charArray, int size) {
  int i = 1, j;
  CharData pivot;

  while (i < size) {
    j = i - 1;
    pivot = charArray[i];

    while (j >= 0 && charArray[j].frequency > pivot.frequency) {
      charArray[j + 1] = charArray[j];
      j--;
    }

    charArray[j + 1] = pivot;
    i++;
  }
}