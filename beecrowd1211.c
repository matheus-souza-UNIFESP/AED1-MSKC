#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  char s1[250];
} String;

String strings[100050];

int compare(String *, String *);

int main(void)
{
  unsigned t, i, j;

  while (scanf("%u", &t) != EOF)
  {
    i = 0;
    unsigned aux = t;
    while (t--)
      scanf("%s", strings[i++].s1);

    unsigned ans = 0;
    qsort(strings, i, sizeof(String), compare);

    for (i = 1; i < aux; ++i)
      for (j = 0; strings[i].s1[j]; ++j)
        if (strings[i].s1[j] == strings[i - 1].s1[j])
          ++ans;
        else
          break;

    printf("%u\n", ans);
  }

  return 0;
}

int compare(String *a, String *b)
{
  int result = strcmp(a->s1, b->s1);

  if (result == 0)
    return 0;
  else if (result < 0)
    return 1;
  else
    return -1;
}