#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
} LinkedList;

LinkedList *linkedlist_create();

// Adds a new node with data to the end of the list
void linkedlist_append(LinkedList *list, void *data);

// Removes the first node containing the given data pointer
void linkedlist_remove(LinkedList *list, void *data);

// Frees the entire list (does not free the data pointers)
void linkedlist_free(LinkedList *list);

#endif
