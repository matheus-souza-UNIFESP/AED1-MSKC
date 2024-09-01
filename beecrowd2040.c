#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char teamName[100];
    unsigned short points;
} Team;

unsigned short findTeam(Team *championship, char *teamName, unsigned short size);
void sortTeams(Team *championship, unsigned short size);

void main() {
    char teamAName[100], teamBName[100];
    unsigned short goalsTeamA, goalsTeamB;
    unsigned short numTeams, halfSize;
    unsigned short i;

    while (true) {
        scanf("%hu", &numTeams);

        if (numTeams == 0)
            break;

        Team championship[numTeams];
        for (i = 0; i < numTeams; i++)
            scanf(" %s %hu", championship[i].teamName, &championship[i].points);

        halfSize = numTeams / 2;
        for (i = 0; i < halfSize; i++) {
            scanf(" %s %hu-%hu %s", teamAName, &goalsTeamA, &goalsTeamB, teamBName);

            // Goals scored by each team are worth 3 points each;
            // Increment points for the team at the position returned by findTeam();
            championship[findTeam(championship, teamAName, numTeams)].points += goalsTeamA * 3;
            championship[findTeam(championship, teamBName, numTeams)].points += goalsTeamB * 3;

            if (goalsTeamA > goalsTeamB)
                championship[findTeam(championship, teamAName, numTeams)].points += 5;
            else if (goalsTeamB > goalsTeamA)
                championship[findTeam(championship, teamBName, numTeams)].points += 5;
            else {
                championship[findTeam(championship, teamAName, numTeams)].points += 1;
                championship[findTeam(championship, teamBName, numTeams)].points += 1;
            }
        }

        sortTeams(championship, numTeams);

        if (strcmp(championship[0].teamName, "Sport") == 0)
            printf("O Sport foi o campeao com %hu pontos :D\n\n", championship[0].points);
        else
            printf("O Sport nao foi o campeao. O time campeao foi o %s com %hu pontos :(\n\n", championship[0].teamName, championship[0].points);
    }
}

unsigned short findTeam(Team *championship, char *teamName, unsigned short size) {
    unsigned short i;

    for (i = 0; i < size; i++)
        if (strcmp(championship[i].teamName, teamName) == 0)
            return i;
}

void sortTeams(Team *championship, unsigned short size) {
    short i = 1, j;
    Team pivot;

    while (i < size) {
        j = i - 1;
        pivot = championship[i];

        while (j >= 0 && championship[j].points < pivot.points) {
            championship[j + 1] = championship[j];
            j--;
        }

        championship[j + 1] = pivot;
        i++;
    }
}