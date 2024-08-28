#include <stdio.h>
#include <stdlib.h>

typedef struct nodeList{
  int data;
  struct nodeList *next;
} nodeList;

typedef struct lList{
  nodeList *first;
  nodeList *last;
} lList;

int hashIndex(int mod, int key);
void hashPush(lList *, int key);

unsigned x;

int main(){
  unsigned n;
  scanf("%u", &n);

  while(n--){
    unsigned m;
    int c, tmp;
    scanf("%u %d", &m, &c);

    lList hash[m];
    for(int i = 0; i < m; ++i){
      hash[i].first = NULL;
      hash[i].last = NULL;
    }

    x = m;

    for(int i = 0; i < c; ++i){
      scanf("%d", &tmp);
      hashPush(hash, tmp);
    }

    for(int i = 0; i < m; ++i){
      printf("%d -> ", i);
      nodeList *j = hash[i].first;
      while(j){
        printf("%d -> ", j->data);
        j = j->next;
      }
      printf("\\\n");
    }

    if(n)
      printf("\n");
  }

  return 0;
}

void hashPush(lList *hash, int key){
  int idx = hashIndex(x, key);
  nodeList *aux = (nodeList *)malloc(sizeof(nodeList));

  if(!aux)
    exit(1);

  aux->data = key;
  aux->next = NULL;

  if(hash[idx].first)
    hash[idx].last->next = aux;
  else
    hash[idx].first = aux;

  hash[idx].last = aux;
}

int hashIndex(int mod, int key){
  return key % mod;
}