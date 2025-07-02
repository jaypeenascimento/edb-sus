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

// INFO: We dont need a dequeueback for this application. So it's not
// implemented.
#endif
