#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char name[20];
  unsigned killCount;
} Assassin;

struct AssassinTree {
  Assassin data;
  struct AssassinTree *left;
  struct AssassinTree *right;
};

struct VictimTree {
  char victim[20];
  struct VictimTree *left;
  struct VictimTree *right;
};

typedef struct AssassinTree AssassinNode;
typedef struct VictimTree VictimNode;

AssassinNode* insertAssassin(AssassinNode *tree, Assassin assassin);
VictimNode* insertVictim(VictimNode *tree, char *victim);
bool searchVictim(VictimNode *tree, char *key);
void display(AssassinNode *assassinTree, VictimNode *victimTree);

int main() {
  char killer[20], victim[20];
  AssassinNode *assassinTree = NULL;
  VictimNode *victimTree = NULL;

  while (scanf(" %s %s", killer, victim) != EOF) {
    Assassin assassin = { 0 };
    strcpy(assassin.name, killer);
    assassinTree = insertAssassin(assassinTree, assassin);
    victimTree = insertVictim(victimTree, victim);
  }

  printf("HALL OF MURDERERS\n");
  display(assassinTree, victimTree);

  return 0;
}

AssassinNode* insertAssassin(AssassinNode *tree, Assassin assassin) {
  if (!tree) {
    tree = (AssassinNode *) malloc(sizeof(AssassinNode));
    tree->data = assassin;
    tree->data.killCount++;
    tree->left = tree->right = NULL;
  } else if (strcmp(tree->data.name, assassin.name) > 0) {
    tree->left = insertAssassin(tree->left, assassin);
  } else if (strcmp(tree->data.name, assassin.name) < 0) {
    tree->right = insertAssassin(tree->right, assassin);
  } else {
    tree->data.killCount++;
  }
  return tree;
}

VictimNode* insertVictim(VictimNode *tree, char *victim) {
  if (!tree) {
    tree = (VictimNode *) malloc(sizeof(VictimNode));
    strcpy(tree->victim, victim);
    tree->left = tree->right = NULL;
  } else if (strcmp(tree->victim, victim) > 0) {
    tree->left = insertVictim(tree->left, victim);
  } else {
    tree->right = insertVictim(tree->right, victim);
  }
  return tree;
}

void display(AssassinNode *assassinTree, VictimNode *victimTree) {
  if (assassinTree != NULL) {
    display(assassinTree->left, victimTree);
    if (!searchVictim(victimTree, assassinTree->data.name))
      printf("%s %u\n", assassinTree->data.name, assassinTree->data.killCount);
    display(assassinTree->right, victimTree);
  }
}

bool searchVictim(VictimNode *tree, char *key) {
  if (!tree)
    return false;

  if (strcmp(tree->victim, key) == 0)
    return true;

  if (strcmp(tree->victim, key) > 0)
    return searchVictim(tree->left, key);
  else
    return searchVictim(tree->right, key);
}