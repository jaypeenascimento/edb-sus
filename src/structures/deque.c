#include "deque.h"
#include <stdlib.h>

DequeNode *dequeCreateNode(void *data) {
  DequeNode *new_node = malloc(sizeof(DequeNode));
  if (!new_node) {
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

Deque *dequeCreate() {
  Deque *deque = malloc(sizeof(Deque));
  if (!deque) {
    return NULL;
  }
  deque->itemCount = 0;
  deque->front = NULL;
  deque->back = NULL;
  return deque;
}

void dequeEnqueueFront(Deque *deque, void *data) {
  DequeNode *node = dequeCreateNode(data);
  if (!node) {
    return exit(1);
  }

  if (deque->front == NULL) {
    deque->front = node;
    deque->back = node;
  } else {
    node->prev = deque->front;
    deque->front->next = node;
    deque->front = node;
  }

  deque->itemCount++;
}

void dequeEnqueueBack(Deque *deque, void *data) {
  DequeNode *node = dequeCreateNode(data);
  if (!node) {
    return exit(1);
  }

  if (deque->front == NULL) {
    deque->front = node;
    deque->back = node;
  } else {
    node->next = deque->back;
    deque->back->prev = node;
    deque->back = node;
  }

  deque->itemCount++;
}

void *dequeDequeueFront(Deque *deque) {
  if (deque->front == NULL) {
    return NULL;
  }

  DequeNode *node = deque->front;
  void *data = node->data;

  if (deque->front == deque->back) {
    deque->front = NULL;
    deque->back = NULL;
  } else {
    deque->front = node->prev;
    deque->front->next = NULL;
  }

  deque->itemCount--;
  free(node);
  return data;
}

void *dequeDequeueBack(Deque *deque) {
  if (deque->back == NULL) {
    return NULL;
  }

  DequeNode *node = deque->back;
  void *data = node->data;

  if (deque->front == deque->back) {
    deque->front = NULL;
    deque->back = NULL;
  } else {
    deque->back = node->next;
    deque->back->prev = NULL;
  }

  deque->itemCount--;
  free(node);
  return data;
}

void *dequePeekFront(Deque *deque) {
  if (deque->front == NULL) {
    return NULL;
  }
  return deque->front->data;
}

void *dequePeekBack(Deque *deque) {
  if (deque->back == NULL) {
    return NULL;
  }
  return deque->back->data;
}
