#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char name[100];
  float price;
} Fruit;

bool findFruit(Fruit *market, char *fruit, int size);
int position;

void main () {
  int numMarketVisits, numProducts;
  int i, numDesiredProducts;
  int quantityFruits;
  char fruitStr[100];
  float totalPrice;

  scanf("%d", &numMarketVisits);

  while (numMarketVisits--) {
    scanf("%d", &numProducts);

    Fruit market[numProducts];
    for (i = 0; i < numProducts; i++) {
      scanf(" %s", market[i].name);
      scanf("%f", &market[i].price);
    }

    scanf("%d", &numDesiredProducts);

    totalPrice = 0;
    for (i = 0; i < numDesiredProducts; i++) {
      scanf(" %s %d", fruitStr, &quantityFruits);
      if (findFruit(market, fruitStr, numProducts)) {
        totalPrice += market[position].price * quantityFruits;
      }
    }

    printf("R$ %.2f\n", totalPrice);
  }
}

bool findFruit(Fruit *market, char *fruit, int size) {
  int i;

  for (i = 0; i < size; i++) {
    if (strcmp(market[i].name, fruit) == 0) {
      position = i;
      return true;
    }
  }

  return false;
}