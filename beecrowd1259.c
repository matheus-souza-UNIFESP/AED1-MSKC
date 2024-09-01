#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);

int main(void) {

  int cases, number, evenCount = 0, oddCount = 0;
  int i = 0, j = 0;

  scanf("%d", &cases);
  int odds[cases], evens[cases];

  while (cases--) {
    scanf("%d", &number);

    if (number % 2 == 0) {	
      evenCount++;
      evens[i++] = number;
    } else {	
      oddCount++;
      odds[j++] = number;
    }
  }

  mergeSort(evens, 0, evenCount - 1);
  mergeSort(odds, 0, oddCount - 1);

  for (i = 0; i < evenCount; i++)
    printf("%d\n", evens[i]);
  for (i = oddCount - 1; i >= 0; i--)
    printf("%d\n", odds[i]);

  oddCount = 0;
  evenCount = 0;

  j = 0;
  i = 0;

  return 0;
}

void mergeSort(int arr[], int start, int end) {

  int mid;
  if (start < end) {
    mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void merge(int arr[], int start, int mid, int end) {

  int *tempArr, p1, p2, size, i, j, k;
  int end1 = 0, end2 = 0;
  size = end - start + 1;
  p1 = start;
  p2 = mid + 1;
  tempArr = (int *)malloc(size * sizeof(int));

  if (tempArr != NULL) {

    for (i = 0; i < size; i++) {

      if (!end1 && !end2) {
        if (arr[p1] < arr[p2])
          tempArr[i] = arr[p1++];
        else
          tempArr[i] = arr[p2++];

        if (p1 > mid)
          end1 = 1;
        if (p2 > end)
          end2 = 1;
      } else {

        if (!end1)
          tempArr[i] = arr[p1++];
        else
          tempArr[i] = arr[p2++];
      }
    }

    for (j = 0, k = start; j < size; j++, k++)
      arr[k] = tempArr[j];
  }

  free(tempArr);
}