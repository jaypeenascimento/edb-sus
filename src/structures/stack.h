#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "linkedlist.h"

typedef struct Stack {
    LinkedList *list;
} Stack;

Stack *stackCreate();
void stackPush(Stack *stack, void *data);
void *stackPop(Stack *stack);
void *stackPeek(Stack *stack);
int stackIsEmpty(Stack *stack);
void stackFree(Stack *stack);

#endif