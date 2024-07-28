#include <stdio.h>

int main() {
  while (1) {
    int n;
    do {
      scanf("%d", &n);
    }while (n > 50);
    
    if (n == 0) break;
    if (n == 1) {
      printf("Discarded cards:\nRemaining card: 1\n");
      continue;
    }
    
    int stack[100], discarded[49];
    for (int i = 0; i < 100; i++){
      stack[i] = 0;
      if (i < 49) discarded[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
      stack[i] = i + 1;
    }

    int discardCount = 0, top = 0, end = n - 1;

    while (top < end) {
      discarded[discardCount++] = stack[top++];
      stack[++end] = stack[top++];
    }

    printf("Discarded cards:");
    for (int i = 0; i < discardCount; i++) {
      if (i == 0) {
        printf(" %d", discarded[i]);
      } else {
        printf(", %d", discarded[i]);
      }
    }
    printf("\nRemaining card: %d\n", stack[top]);
  }

  return 0;
}