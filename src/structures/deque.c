#include "deque.h"
#include <stdlib.h>

DequeNode *deque_createnode(void *data) {
  DequeNode *new_node = malloc(sizeof(DequeNode));
  if (!new_node) {
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

Deque *deque_create() {
  Deque *deque = malloc(sizeof(Deque));
  if (!deque) {
    return NULL;
  }
  deque->front = NULL;
  deque->back = NULL;
  return deque;
}

void deque_enqueuefront(Deque *deque, void *data) {
  DequeNode *node = deque_createnode(data);
  if (!node) {
    // FORCEFULL CRASH PROGRAM IF NO MEMORY.
    return exit(1);
  }

  if (deque->front == NULL) {
    // Deque is empty.
    deque->front = node;
    deque->back = node;
  } else {
    // Deque is non-empty.
    node->prev = deque->front;
    deque->front->next = node;
    deque->front = node;
  }
}

void deque_enqueueback(Deque *deque, void *data) {
  DequeNode *node = deque_createnode(data);
  if (!node) {
    // FORCEFULL CRASH PROGRAM IF NO MEMORY.
    return exit(1);
  }

  if (deque->front == NULL) {
    // Deque is empty.
    deque->front = node;
    deque->back = node;
  } else {
    // Deque is non-empty.
    node->next = deque->back;
    deque->back->prev = node;
    deque->back = node;
  }
}
