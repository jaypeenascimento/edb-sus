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
