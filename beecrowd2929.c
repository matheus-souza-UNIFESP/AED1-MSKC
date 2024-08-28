#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct {
    long long number;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void Pop(Stack *stack);
void CreateStack(Stack *stack);
long long MinInStack(Stack *stack);
void Push(Stack *stack, long long number);

int main() {
    Stack stack;
    char operation[10];
    int numOperations;
    long long number, temp;

    scanf("%d", &numOperations);

    CreateStack(&stack);

    while (numOperations--) {
        scanf("%s", operation);

        if (strcmp(operation, "PUSH") == 0) {
            scanf("%lld", &number);
            Push(&stack, number);
        } else if (strcmp(operation, "POP") == 0) {
            Pop(&stack);
        } else {
            temp = MinInStack(&stack);
            if (temp == -1) {
                printf("EMPTY\n");
            } else {
                printf("%lld\n", temp);
            }
        }
    }

    return 0;
}

void CreateStack(Stack *stack) {
    stack->top = NULL;
}

void Push(Stack *stack, long long number) {
    Node *auxiliary;

    auxiliary = (Node *) malloc(sizeof(Node));
    if (!auxiliary) exit(1);

    auxiliary->next = stack->top;
    stack->top = auxiliary;
    auxiliary->number = number;
}

void Pop(Stack *stack) {
    Node *auxiliary;
    auxiliary = stack->top;

    if (auxiliary) {
        stack->top = auxiliary->next;
        free(auxiliary);
    } else {
        printf("EMPTY\n");
    }
}

long long MinInStack(Stack *stack) {
    Node *auxiliary;
    auxiliary = stack->top;

    if (!auxiliary) return -1;

    long long min = auxiliary->number;

    while (auxiliary) {
        if (auxiliary->number < min) min = auxiliary->number;
        auxiliary = auxiliary->next;
    }

    return min;
}