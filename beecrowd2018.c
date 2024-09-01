#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char name[50];
  unsigned short gold;
  unsigned short silver;
  unsigned short bronze;
} MedalData;

struct TreeNode {
  MedalData data;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insertGold(TreeNode *root, MedalData data);
TreeNode* insertSilver(TreeNode *root, MedalData data);
TreeNode* insertBronze(TreeNode *root, MedalData data);
void treeToArray(TreeNode *root, MedalData *array);
int compare(const void *a, const void *b);
unsigned short index = 0;

int main() {
  unsigned short j;
  char event[300];
  TreeNode *root = NULL;

  while (scanf(" %[^\n]", event) != EOF) {
    MedalData country = { 0 };
    scanf(" %[^\n]", country.name);
    root = insertGold(root, country);
    scanf(" %[^\n]", country.name);
    root = insertSilver(root, country);
    scanf(" %[^\n]", country.name);
    root = insertBronze(root, country);
  }

  MedalData competitors[300] = { 0 };
  printf("Quadro de Medalhas\n");
  treeToArray(root, competitors);
  qsort(competitors, index, sizeof(MedalData), compare);

  for (j = 0; j < index; j++)
    printf("%s %hu %hu %hu\n", competitors[j].name, competitors[j].gold, competitors[j].silver, competitors[j].bronze);

  return 0;
}

void treeToArray(TreeNode *root, MedalData *array) {
  if (root != NULL) {
    treeToArray(root->left, array);
    array[index++] = root->data;
    treeToArray(root->right, array);
  }
}

TreeNode* insertGold(TreeNode *root, MedalData data) {
  if (!root) {
    root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data = data;
    root->data.gold++;
    root->left = root->right = NULL;
  } else if (strcmp(root->data.name, data.name) > 0)
    root->left = insertGold(root->left, data);
  else if (strcmp(root->data.name, data.name) < 0)
    root->right = insertGold(root->right, data);
  else
    root->data.gold++;

  return root;
}

TreeNode* insertSilver(TreeNode *root, MedalData data) {
  if (!root) {
    root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data = data;
    root->data.silver++;
    root->left = root->right = NULL;
  } else if (strcmp(root->data.name, data.name) > 0)
    root->left = insertSilver(root->left, data);
  else if (strcmp(root->data.name, data.name) < 0)
    root->right = insertSilver(root->right, data);
  else
    root->data.silver++;

  return root;
}

TreeNode* insertBronze(TreeNode *root, MedalData data) {
  if (!root) {
    root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data = data;
    root->data.bronze++;
    root->left = root->right = NULL;
  } else if (strcmp(root->data.name, data.name) > 0)
    root->left = insertBronze(root->left, data);
  else if (strcmp(root->data.name, data.name) < 0)
    root->right = insertBronze(root->right, data);
  else
    root->data.bronze++;

  return root;
}

int compare(const void *a, const void *b) {
  if (((MedalData*)a)->gold == ((MedalData*)b)->gold) {
    if (((MedalData*)a)->silver == ((MedalData*)b)->silver) {
      if (((MedalData*)a)->bronze == ((MedalData*)b)->bronze) {
        if (strcmp(((MedalData*)a)->name, ((MedalData*)b)->name) == 0)
          return 0;
        else if (strcmp(((MedalData*)a)->name, ((MedalData*)b)->name) > 0)
          return 1;
        else
          return -1;
      } else if (((MedalData*)a)->bronze > ((MedalData*)b)->bronze)
        return -1;
      else
        return 1;
    } else if (((MedalData*)a)->silver > ((MedalData*)b)->silver)
      return -1;
    else
      return 1;
  } else if (((MedalData*)a)->gold > ((MedalData*)b)->gold)
    return -1;
  else
    return 1;
}