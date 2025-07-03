#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
} LinkedList;

LinkedList *linkedlistCreate();

void linkedlistAppend(LinkedList *list, void *data);

void linkedlistRemove(LinkedList *list, void *data);

void linkedlistFree(LinkedList *list);

#endif
