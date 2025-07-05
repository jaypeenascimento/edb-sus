#ifndef DEQUE_H
#define DEQUE_H

typedef struct DequeNode {
    void *data;
    struct DequeNode *next;
    struct DequeNode *prev;
} DequeNode;

typedef struct Deque {
    int itemCount;
    DequeNode *front;
    DequeNode *back;
} Deque;

Deque *dequeCreate();

void dequeEnqueueFront(Deque *deque, void *data);

void dequeEnqueueBack(Deque *deque, void *data);

void *dequeDequeueFront(Deque *deque);

void *dequeDequeueBack(Deque *deque);

void *dequePeekFront(Deque *deque);

void *dequePeekBack(Deque *deque);
#endif
