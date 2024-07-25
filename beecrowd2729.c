#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 21

int compare(const char *a, const char *b){
  return strcmp(a, b);
}

void insertionSort(char items[MAX_ITEMS][MAX_LENGTH], int itemCount){
  for(int i = 1; i < itemCount; i++){
    char key[MAX_LENGTH];
    strcpy(key, items[i]);
    int j = i - 1;
    while(j >= 0 && compare(items[j], key) > 0){
      strcpy(items[j + 1], items[j]);
      j--;
    }
    strcpy(items[j + 1], key);
  }
}

void processList(char items[MAX_ITEMS][MAX_LENGTH], int itemCount){
  insertionSort(items, itemCount);
  
  int uniqueCount = 0;
  for(int i = 0; i < itemCount; i++){
    if(i == 0 || strcmp(items[i], items[i - 1]) != 0){
      strcpy(items[uniqueCount], items[i]);
      uniqueCount++;
    }
  }

  for(int i = 0; i < uniqueCount; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%s", items[i]);
  }
  printf("\n");
}

int main(){
  int N;
  scanf("%d", &N);
  getchar();

  for(int i = 0; i < N; i++){
    char line[10000];
    char items[MAX_ITEMS][MAX_LENGTH];
    int itemCount = 0;

    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " \n");
    while(token != NULL){
      strcpy(items[itemCount], token);
      itemCount++;
      token = strtok(NULL, " \n");
    }
    processList(items, itemCount);
  }

  return 0;
}
