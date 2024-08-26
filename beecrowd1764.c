#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
  int v1, v2, weight;
} edge;

int find(int parent[], int i);
void unionSet(int parent[], int rank[], int x, int y);
int myComp(const void *a, const void *b);
int totalWeight(edge mst[], int n);
int kruskal(edge edges[], int V, int E);

int main(void) {

  while (1) {
    int m, n;
    scanf("%d %d", &m, &n);
    if (m == 0 && n == 0)
      break;

    edge edges[n];
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &edges[i].v1, &edges[i].v2, &edges[i].weight);
    }

    int result = kruskal(edges, m, n);
    printf("%d\n", result);
  }
  return 0;
}

int find(int parent[], int i) {
  if (parent[i] != i)
    parent[i] = find(parent, parent[i]);

  return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
  int xroot = find(parent, x);
  int yroot = find(parent, y);

  if (xroot != yroot) {
    if (rank[xroot] < rank[yroot])
      parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
      parent[yroot] = xroot;
    else {
      parent[yroot] = xroot;
      rank[xroot]++;
    }
  }
}

int myComp(const void *a, const void *b) {
  return ((edge *)a)->weight - ((edge *)b)->weight;
}

int totalWeight(edge mst[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += mst[i].weight;
  }

  return result;
}

int kruskal(edge edges[], int V, int E) {
  qsort(edges, E, sizeof(edge), myComp);

  int parent[V], rank[V];
  for (int i = 0; i < V; i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  edge tree[V - 1];
  int index = 0, i = 0;
  while (index < V - 1 && i < E) {
    edge next = edges[i++];
    int x = find(parent, next.v1);
    int y = find(parent, next.v2);

    if (x != y) {
      tree[index++] = next;
      unionSet(parent, rank, x, y);
    }
  }

  return totalWeight(tree, index);
}