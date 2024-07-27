#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 300
#define MAX_STACK 100

typedef struct {
  char items[MAX_STACK];
  int top;
} Stack;

void initStack(Stack *s) {
  s->top = -1;
}

int isFull(Stack *s) {
  return s->top == MAX_STACK - 1;
}

int isEmpty(Stack *s) {
  return s->top == -1;
}

void push(Stack *s, char value) {
  if(!isFull(s)) {
    s->items[++(s->top)] = value;
  }
}

char pop(Stack *s) {
  if(!isEmpty(s)) {
    return s->items[(s->top)--];
  }
  return '\0';
}

char peek(Stack *s) {
  if(!isEmpty(s)) {
    return s->items[s->top];
  }
  return '\0';
}

int precedence(char op) {
  switch(op) {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
  }
}

int isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char* infix, char* postfix) {
  Stack stack;
  initStack(&stack);
  int k = 0;

  for(int i = 0; infix[i] != '\0'; i++) {
    if(isdigit(infix[i]) || isalpha(infix[i])) {
      postfix[k++] = infix[i];
    } else if(infix[i] == '(') {
      push(&stack, infix[i]);
    } else if(infix[i] == ')') {
      while(!isEmpty(&stack) && peek(&stack) != '(') {
        postfix[k++] = pop(&stack);
      }
      pop(&stack);
    } else if(isOperator(infix[i])) {
      while(!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
        postfix[k++] = pop(&stack);
      }
      push(&stack, infix[i]);
    }
  }

  while(!isEmpty(&stack)) {
    postfix[k++] = pop(&stack);
  }

  postfix[k] = '\0';
}

int main() {
  int N;
  scanf("%d", &N);
  char infix[MAX], postfix[MAX];

  for(int i = 0; i < N; i++) {
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
  }

  return 0;
}