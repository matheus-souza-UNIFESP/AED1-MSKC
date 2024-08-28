#include <stdio.h>

int sort(int array[], int size);

void main(void)
{

    int cases, trainSize;
    int i;

    scanf("%d", &cases);

    while (cases--)
    {

        scanf("%d", &trainSize);
        int wagons[trainSize];

        for (i = 0; i < trainSize; i++)
            scanf("%d", &wagons[i]);

        printf("Optimal train swapping takes %d swaps.\n", sort(wagons, trainSize));

    }
}

int sort(int array[], int size)
{

    int i, j, count = 0, temp;

    while (size--)
    {

        for (i = 0, j = 1; i < size; i++, j++)
            if (array[i] > array[j])
            {   
                count++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
    }
    return count;
}