#include "linkedlist.h"
#include <stdlib.h>

LinkedList *linkedlist_create() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (list) {
    list->head = NULL;
  }
  return list;
}

void linkedlist_append(LinkedList *list, void *data) {
  if (!list)
    return;

  LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  if (!node)
    return;

  node->data = data;
  node->next = NULL;

  if (!list->head) {
    list->head = node;
  } else {
    LinkedListNode *curr = list->head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = node;
  }
}

void linkedlist_remove(LinkedList *list, void *data) {
  if (!list || !list->head)
    return;

  LinkedListNode *curr = list->head;
  LinkedListNode *prev = NULL;

  while (curr) {
    if (curr->data == data) {
      if (prev) {
        prev->next = curr->next;
      } else {
        list->head = curr->next;
      }

      // Free only the node, not the value inside data.
      free(curr);
      return;
    }

    prev = curr;
    curr = curr->next;
  }
}

void linkedlist_free(LinkedList *list) {
  if (!list)
    return;
  LinkedListNode *curr = list->head;

  while (curr) {
    LinkedListNode *next = curr->next;
    free(curr);
    curr = next;
  }
  free(list);
}
