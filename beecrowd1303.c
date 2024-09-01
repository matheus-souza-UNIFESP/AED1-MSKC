#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 105

typedef struct Team {
  int totalPoints;
  int scored;
  int conceded;
  int id;
} Team;

int compareTeams(Team *, Team *);

Team teams[MAXSIZE];

void main() {
  int numTeams, i;
  int instance = 0;
  int id1, id2, points1, points2;

  while (scanf("%d", &numTeams)) {
    if (numTeams == 0)
      break;

    if (instance != 0)
      printf("\n");

    int totalMatches = numTeams * (numTeams - 1) / 2;
    for (i = 0; i < totalMatches; ++i) {
      scanf("%d %d %d %d", &id1, &points1, &id2, &points2);

      if (points1 > points2) {
        teams[id1].totalPoints += 2;
        teams[id2].totalPoints += 1;
      } else {
        teams[id2].totalPoints += 2;
        teams[id1].totalPoints += 1;
      }

      teams[id1].scored += points1;
      teams[id1].conceded += points2;
      teams[id2].scored += points2;
      teams[id2].conceded += points1;
      teams[id1].id = id1;
      teams[id2].id = id2;
    }

    qsort(&teams[1], numTeams, sizeof(Team), compareTeams);

    _Bool flag = FALSE;
    printf("Instancia %d\n", ++instance);
    for (i = 1; i <= numTeams; ++i) {
      if (flag)
        printf(" %d", teams[i].id);
      else
        printf("%d", teams[i].id), flag = TRUE;
    }

    printf("\n");

    memset(teams, 0, sizeof(teams));
  }
}

int compareTeams(Team *a, Team *b) {
  if (a->totalPoints == b->totalPoints) {
    if (a->conceded == 0)
      a->conceded = 1;
    if (b->conceded == 0)
      b->conceded = 1;

    float ratioA = a->scored / (a->conceded * 1.0f);
    float ratioB = b->scored / (b->conceded * 1.0f);

    if (ratioA == ratioB) {
      if (a->scored == b->scored) {
        if (a->id < b->id)
          return -1;
        else
          return 1;
      } else if (a->scored > b->scored)
        return -1;
      else
        return 1;
    } else if (ratioA > ratioB)
      return -1;
    else
      return 1;
  } else if (a->totalPoints > b->totalPoints)
    return -1;
  else
    return 1;
}