#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Compare(const void *a, const void *b);
bool BinarySearch(unsigned *, unsigned, unsigned short);
unsigned Position;

void main() {
    unsigned short i, numCases = 0;
    unsigned short numQueries;
    unsigned numMarbles, number;

    while (true) {
        scanf("%u %hu", &numMarbles, &numQueries);

        if (numQueries == 0 && numMarbles == 0)
            break;

        unsigned marbles[numMarbles];

        for (i = 0; i < numMarbles; i++)
            scanf("%u", &marbles[i]);

        qsort(marbles, numMarbles, sizeof(unsigned), Compare);

        printf("CASE# %u:\n", ++numCases);
        while (numQueries--) {
            scanf("%u", &number);

            if (BinarySearch(marbles, number, numMarbles)) {
                if (marbles[Position - 1] == marbles[Position]) {
                    while (Position > 0 && marbles[Position - 1] == marbles[Position])
                        Position--;

                    printf("%u found at %u\n", number, Position + 1);
                } else {
                    printf("%u found at %u\n", number, Position + 1);
                }
            } else {
                printf("%u not found\n", number);
            }
        }
    }
}

int Compare(const void *a, const void *b) {
    if (*(unsigned*)a == *(unsigned*)b)
        return 0;
    else if (*(unsigned*)a > *(unsigned*)b)
        return 1;
    else
        return -1;
}

bool BinarySearch(unsigned *marbles, unsigned number, unsigned short size) {
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (marbles[mid] < number)
            start = mid + 1;
        else if (marbles[mid] > number)
            end = mid - 1;
        else {
            Position = mid;
            return true;
        }
    }

    return false;
}