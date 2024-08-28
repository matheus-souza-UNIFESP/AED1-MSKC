#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void ProcessCases();

int main() {
    ProcessCases();
    return 0;
}

void ProcessCases() {
    int cases, numPeople;
    char current[21], previous[21];
    bool isEnglish;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &numPeople);

        scanf(" %s", current);

        numPeople--;
        isEnglish = false;
        strcpy(previous, current);

        while (numPeople--) {
            if (strcmp(current, previous) != 0 && !isEnglish)
                isEnglish = true;
            else
                strcpy(previous, current);

            scanf(" %s", current);
        }

        if (isEnglish)
            printf("ingles\n");
        else
            printf("%s\n", current);
    }
}