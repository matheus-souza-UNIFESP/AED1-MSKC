#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0
#define MAXSIZE 300
#define MAXSIZES 100100

int quantities[MAXSIZE] = { 0 };
char endString[MAXSIZES];
char currentString[100100];
bool favoriteLetters[MAXSIZES] = { false };

int countFavoriteLetters();

void main() {

    unsigned i;
    unsigned k, m, n;
    char inputString[MAXSIZES], a, b;
    unsigned maxFavoriteLettersCount, temp;

    scanf("%u %u %u", &k, &m, &n);
    scanf("%s", inputString);

    for (i = 0; i < k; ++i)
        favoriteLetters[inputString[i]] = true;

    scanf("%s", inputString);

    for (i = 0; i < m; ++i)
        quantities[inputString[i]]++;

    for (i = 'a'; i <= 'z'; ++i)
        currentString[i] = endString[i] = i;

    maxFavoriteLettersCount = countFavoriteLetters();

    while (n--) {

        scanf(" %c %c", &a, &b);

        for (i = 'a'; i <= 'z'; ++i) {

            if (currentString[i] == a)
                currentString[i] = b;
            else if (currentString[i] == b)
                currentString[i] = a;

        }

        temp = countFavoriteLetters();

        if (temp > maxFavoriteLettersCount) {

            maxFavoriteLettersCount = temp;
            for (i = 'a'; i <= 'z'; ++i)
                endString[i] = currentString[i];

        }

    }

    printf("%d\n", maxFavoriteLettersCount);
    for (i = 0; i < m; ++i)
        printf("%c", endString[inputString[i]]);

    printf("\n");

}

int countFavoriteLetters() {

    int i;
    int result = 0;

    for (i = 'a'; i <= 'z'; ++i)
        result += quantities[i] * favoriteLetters[currentString[i]];

    return result;

}