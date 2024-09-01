#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char name[150];
  int weight;
  int age;
  float height;
} Reindeer;

int compare(const void *a, const void *b);

int main() {
  int totalReindeer, reindeerInSled;
  int i, scenario;
  int cases;

  scanf("%d", &cases);

  scenario = 0;
  while (cases--) {
    scanf("%d %d", &totalReindeer, &reindeerInSled);

    Reindeer reindeers[totalReindeer];

    for (i = 0; i < totalReindeer; i++)
      scanf(" %s %d %d %f", reindeers[i].name, &reindeers[i].weight, &reindeers[i].age, &reindeers[i].height);

    qsort(reindeers, totalReindeer, sizeof(Reindeer), compare);

    printf("CENARIO {%d}\n", ++scenario);
    for (i = 0; i < reindeerInSled; i++)
      printf("%d - %s\n", i + 1, reindeers[i].name);
  }

  return 0;
}

int compare(const void *a, const void *b) {
  Reindeer *ra = (Reindeer *)a;
  Reindeer *rb = (Reindeer *)b;

  if (ra->weight == rb->weight) {
    if (ra->age == rb->age) {
      if (ra->height == rb->height) {
        return strcmp(ra->name, rb->name);
      } else if (ra->height < rb->height) {
        return -1;
      } else {
        return 1;
      }
    } else if (ra->age < rb->age) {
      return -1;
    } else {
      return 1;
    }
  } else if (ra->weight > rb->weight) {
    return -1;
  } else {
    return 1;
  }
}