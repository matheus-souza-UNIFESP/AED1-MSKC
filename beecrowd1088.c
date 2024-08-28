#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merge(int *array, int size, int *inversions);

void main ()
{
    int i, size, inversions;
    while(scanf("%d", &size), size)
    {
        int *array = malloc(size * sizeof(int));
        if (array == NULL)
            return;

        for(i = 0; i < size; ++i)
            scanf("%d", &array[i]);

        inversions = 0;
        merge(array, size, &inversions);
        printf("%s\n", inversions & 1 ? "Marcelo" : "Carlos");

        free(array);
    }
}

int merge(int *array, int size, int *inversions)
{
    if (size > 1)
    {
        int mid = size / 2;
        merge(array, mid, inversions);
        merge(array + mid, size - mid, inversions);

        int *temp = malloc(size * sizeof(int));
        if (temp == NULL)
            return -1;

        int i = 0, j = mid, k;

        for (k = 0; k < size; ++k)
        {
            if (i < mid && (j >= size || array[i] <= array[j]))
                temp[k] = array[i++];
            else
            {
                temp[k] = array[j++];
                *inversions += mid - i;
            }
        }

        memcpy(array, temp, size * sizeof(int));
        free(temp);
    }

    return 0;
}