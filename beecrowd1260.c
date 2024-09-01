#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char name[100];
	unsigned count;
} DataType;

typedef struct TreeNode {
	DataType data;
	struct TreeNode *right;
	struct TreeNode *left;
} TreeNode;

TreeNode* insert(TreeNode *tree, DataType data);
void display(TreeNode *tree);
void clear(TreeNode *tree);
unsigned totalNodes;

void main() {
	char tempChar;
	unsigned numCases;
	char inputString[100] = { 0 };

	scanf("%u", &numCases);
	scanf("%c%[^\n]", &tempChar, inputString);

	while (numCases) {
		totalNodes = 0;
		TreeNode *tree = NULL;
		while (true) {
			DataType data = { 0 };
			scanf("%c%[^\n]", &tempChar, inputString);
			if (!strlen(inputString))
				break;
			strcpy(data.name, inputString);
			tree = insert(tree, data);
			totalNodes++;
			memset(inputString, 0, sizeof(inputString));
		}
		numCases--;
		display(tree);
		clear(tree);
		if (numCases)
			printf("\n");
	}
}

TreeNode* insert(TreeNode *tree, DataType data) {
	if (!tree) {
		tree = (TreeNode *) malloc(sizeof(TreeNode));
		tree->data = data;
		tree->data.count++;
		tree->right = tree->left = NULL;
	} else if (strcmp(tree->data.name, data.name) > 0)
		tree->left = insert(tree->left, data);
	else if (strcmp(tree->data.name, data.name) < 0)
		tree->right = insert(tree->right, data);
	else
		tree->data.count++;
	return tree;
}

void display(TreeNode *tree) {
	if (tree) {
		display(tree->left);
		printf("%s %.4lf\n", tree->data.name, (tree->data.count * 100.0f) / totalNodes);
		display(tree->right);
	}
}

void clear(TreeNode *tree) {
	if (!tree)
		return;
	clear(tree->left);
	clear(tree->right);
	free(tree);
	tree = NULL;
}