#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 205

double notes[100] = {0};

void fillNotes();
int autoTune(char *jingle);
double countCompass(char *temp);

void main() {
  fillNotes();
  char jingle[MAXSIZE] = {0};

  while (TRUE) {
    scanf("%s", jingle);

    if (strcmp(jingle, "*") == 0)
      break;

    printf("%d\n", autoTune(&jingle[1]));
  }
}

int autoTune(char *jingle) {
  char *temp;
  int correctCompasses = 0;

  temp = strtok(jingle, "/");

  if (countCompass(temp) == 1.0)
    correctCompasses++;

  while ((temp = strtok(NULL, "/")) != NULL) {
    if (countCompass(temp) == 1.0)
      correctCompasses++;
  }

  return correctCompasses;
}

double countCompass(char *temp) {
  double sum = 0;
  int i = 0;

  while (temp[i])
    sum += notes[temp[i++]];

  return sum;
}

void fillNotes() {
  notes['W'] = 1.0;
  notes['H'] = 0.5;
  notes['Q'] = 0.25;
  notes['E'] = 0.125;
  notes['S'] = 0.0625;
  notes['T'] = 0.03125;
  notes['X'] = 0.015625;
}