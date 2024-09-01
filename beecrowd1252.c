#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10100

int numElements, divisor;
int compare(const void *, const void *);

int main(){
  int i;
  int array[MAX_SIZE];

  while (scanf("%d %d", &numElements, &divisor), numElements){
    for (i = 0; i < numElements; ++i)
      scanf("%d", &array[i]);

    qsort(array, numElements, sizeof(int), compare);

    printf("%d %d\n", numElements, divisor);
    for (i = 0; i < numElements; ++i)
      printf("%d\n", array[i]);
  }

  printf("%d %d\n", numElements, divisor);

  return 0;
}

int compare(const void *a, const void *b){
  int valA = *(int *)a;
  int valB = *(int *)b;

  if (valA % divisor == valB % divisor){
    if ((valA & 1) && !(valB & 1))
      return -1;
    else if (!(valA & 1) && (valB & 1))
      return 1;
    else if ((valA & 1) && (valB & 1)){
      return valA > valB ? -1 : 1;
    }
    else{
      return valA > valB ? 1 : -1;
    }
  }
  else{
    return (valA % divisor > valB % divisor) ? 1 : -1;
  }
}