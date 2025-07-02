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

Deque *deque_create();

// Adds a new node with data to the front of the deque
void deque_enqueuefront(Deque *deque, void *data);

// Adds a new node with data to the back of the deque
void deque_enqueueback(Deque *deque, void *data);

// Returns the front node's data and removes it from the deque
void *deque_dequeuefront(Deque *deque);

// Returns the front node's data and removes it from the deque
void *deque_dequeueback(Deque *deque);

// Returns the front node's data without removing it from the deque
void *deque_peekfront(Deque *deque);

// Returns the back node's data without removing it from the deque
void *deque_peekback(Deque *deque);
#endif
