#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0
#define MAXSIZE 235

void main() {
  bool flag;
  unsigned numHeights;
  unsigned i, numCases, temp;
  int heights[MAXSIZE] = {0};

  scanf("%u", &numCases);

  while (numCases--) {
    scanf("%u", &numHeights);

    for (i = 0; i < numHeights; ++i) {
      scanf("%u", &temp);
      heights[temp]++;
    }

    flag = false;
    for (i = 20; i <= 230; ++i) {
      if (heights[i] > 1) {
        while (heights[i]--) {
          if (!flag)
            printf("%u", i), flag = true;
          else
            printf(" %u", i);
        }
      }
      else if (heights[i] == 1) {
        if (!flag)
          printf("%u", i), flag = true;
        else
          printf(" %u", i);
      }
    }

    printf("\n");
    memset(heights, 0, sizeof(heights));
  }
}