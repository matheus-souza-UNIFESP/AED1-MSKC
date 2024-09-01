#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Gift {
  char name[100];
  double price;
  char preference;
} Gift;

int compare(const void *a, const void *b);

int main() {
  unsigned short numGifts;
  unsigned short i;
  char listName[100];

  while (scanf(" %s %hu", listName, &numGifts) != EOF) {
    Gift gifts[numGifts];

    memset(gifts, 0, sizeof(gifts));
    for (i = 0; i < numGifts; i++) {
      scanf(" %[^\n]", gifts[i].name);
      scanf("%lf %hhd", &gifts[i].price, &gifts[i].preference);
    }

    qsort(gifts, numGifts, sizeof(Gift), compare);

    printf("Lista de %s\n", listName);
    for (i = 0; i < numGifts; i++)
      printf("%s - R$%.2lf\n", gifts[i].name, gifts[i].price);

    printf("\n");
  }

  return 0;
}

int compare(const void *a, const void *b) {
  const Gift *giftA = (const Gift *)a;
  const Gift *giftB = (const Gift *)b;

  if (giftA->preference == giftB->preference) {
    if (giftA->price == giftB->price) {
      return strcmp(giftA->name, giftB->name);
    } else if (giftA->price > giftB->price) {
      return 1;
    } else {
      return -1;
    }
  } else if (giftA->preference < giftB->preference) {
    return 1;
  } else {
    return -1;
  }
}