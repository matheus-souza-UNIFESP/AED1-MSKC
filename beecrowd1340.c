#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct NodeQueue {
  int data;
  struct NodeQueue *next;
} NodeQueue;

typedef struct Queue {
  NodeQueue *first;
  NodeQueue *last;
} Queue;

typedef struct NodeStack {
  int data;
  struct NodeStack *next;
} NodeStack;

typedef struct Stack {
  NodeStack *top;
} Stack;

typedef struct PriorityQueue {
  int data;
  int priority;
} PriorityQueue;

typedef struct PQueue {
  int count;
  PriorityQueue elements[MAX];
} PQueue;

void initializeQueue(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
int peekQueue(Queue *);

void initializeStack(Stack *);
void pushStack(Stack *, int);
int popStack(Stack *);
int peekStack(Stack *);

PQueue *createPriorityQueue();
void enqueuePriorityQueue(PQueue *, int, int);
int dequeuePriorityQueue(PQueue *);
int peekPriorityQueue(PQueue *);
void balanceInsertion(PQueue *, int);
void balanceRemoval(PQueue *, int);

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int x, command, i;
    _Bool isQueue, isStack, isPQueue;
    PQueue *priorityQueue = createPriorityQueue();
    Queue queue;
    Stack stack;

    initializeQueue(&queue);
    initializeStack(&stack);

    isQueue = isStack = isPQueue = 1;
    for (i = 0; i < n; ++i) {
      scanf("%d %d", &command, &x);

      if (command == 1) {
        enqueuePriorityQueue(priorityQueue, x, x);
        pushStack(&stack, x);
        enqueue(&queue, x);
      } else {
        if (peekStack(&stack) != x)
          isStack = 0;
        else
          popStack(&stack);

        if (peekQueue(&queue) != x)
          isQueue = 0;
        else
          dequeue(&queue);

        if (peekPriorityQueue(priorityQueue) != x)
          isPQueue = 0;
        else
          dequeuePriorityQueue(priorityQueue);
      }
    }

    if (!isStack && !isQueue && !isPQueue)
      printf("impossible\n");
    else if ((isStack && isPQueue) || (isStack && isQueue) || (isQueue && isPQueue))
      printf("not sure\n");
    else if (isPQueue)
      printf("priority queue\n");
    else if (isQueue)
      printf("queue\n");
    else if (isStack)
      printf("stack\n");
  }

  return 0;
}

void initializeQueue(Queue *queue) {
  queue->first = queue->last = NULL;
}

void enqueue(Queue *queue, int value) {
  NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
  if (!newNode)
    exit(1);

  newNode->data = value;
  newNode->next = NULL;

  if (queue->last)
    queue->last->next = newNode;
  else
    queue->first = newNode;

  queue->last = newNode;
}

int dequeue(Queue *queue) {
  if (!queue->first)
    return -1;

  NodeQueue *temp = queue->first;
  int value = temp->data;
  queue->first = queue->first->next;

  if (!queue->first)
    queue->last = NULL;

  free(temp);
  return value;
}

int peekQueue(Queue *queue) { return queue->first ? queue->first->data : -1; }

void initializeStack(Stack *stack) { stack->top = NULL; }

void pushStack(Stack *stack, int value) {
  NodeStack *newNode = (NodeStack *)malloc(sizeof(NodeStack));
  if (!newNode)
    exit(1);

  newNode->data = value;
  newNode->next = stack->top;
  stack->top = newNode;
}

int popStack(Stack *stack) {
  if (!stack->top)
    return -1;

  NodeStack *temp = stack->top;
  int value = temp->data;
  stack->top = stack->top->next;
  free(temp);
  return value;
}

int peekStack(Stack *stack) { return stack->top ? stack->top->data : -1; }

PQueue *createPriorityQueue() {
  PQueue *pq = (PQueue *)malloc(sizeof(PQueue));
  if (!pq)
    exit(1);

  pq->count = 0;
  return pq;
}

void enqueuePriorityQueue(PQueue *pq, int priority, int value) {
  if (pq->count == MAX)
    exit(1);

  pq->elements[pq->count].data = value;
  pq->elements[pq->count].priority = priority;
  balanceInsertion(pq, pq->count);
  pq->count++;
}

void balanceInsertion(PQueue *pq, int index) {
  int parent = (index - 1) / 2;
  PriorityQueue temp;

  while (index > 0 &&
         pq->elements[parent].priority <= pq->elements[index].priority) {
    temp = pq->elements[index];
    pq->elements[index] = pq->elements[parent];
    pq->elements[parent] = temp;

    index = parent;
    parent = (parent - 1) / 2;
  }
}

int peekPriorityQueue(PQueue *pq) {
  return pq->count > 0 ? pq->elements[0].data : -1;
}

int dequeuePriorityQueue(PQueue *pq) {
  if (pq->count == 0)
    return -1;

  int value = pq->elements[0].data;
  pq->count--;
  pq->elements[0] = pq->elements[pq->count];
  balanceRemoval(pq, 0);
  return value;
}

void balanceRemoval(PQueue *pq, int index) {
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;
  int largest = index;
  PriorityQueue temp;

  if (leftChild < pq->count &&
      pq->elements[leftChild].priority > pq->elements[largest].priority)
    largest = leftChild;

  if (rightChild < pq->count &&
      pq->elements[rightChild].priority > pq->elements[largest].priority)
    largest = rightChild;

  if (largest != index) {
    temp = pq->elements[index];
    pq->elements[index] = pq->elements[largest];
    pq->elements[largest] = temp;
    balanceRemoval(pq, largest);
  }
}