#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct {
    int v, u, w;
} Edge;

Edge g[250];
int p[70];

int CompareEdges(Edge *a, Edge *b);
int FindComponent(int i);
int Kruskal(int c);

int main() {
    int r, c, i;

    scanf("%d %d", &r, &c);

    for (i = 0; i < c; ++i)
        scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w);

    qsort(g, c, sizeof(Edge), CompareEdges);

    for (i = 1; i <= r; ++i)
        p[i] = i;

    printf("%d\n", Kruskal(c));

    return 0;
}

int CompareEdges(Edge *a, Edge *b) {
    return a->w - b->w;
}

int FindComponent(int i) {
    if (i == p[i])
        return i;
    return FindComponent(p[i]);
}

int Kruskal(int c) {
    int i, ans = 0, v, u;

    for (i = 0; i < c; ++i) {
        v = FindComponent(g[i].v);
        u = FindComponent(g[i].u);

        if (v != u) {
            p[v] = p[u];
            ans += g[i].w;
        }
    }

    return ans;
}