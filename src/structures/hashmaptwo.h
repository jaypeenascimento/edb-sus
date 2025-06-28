#ifndef HASHMAPTWO_H
#define HASHMAPTWO_H

#include "../commons.h"
#include "linkedlist.h"
#include <stdio.h>

typedef struct HashMapValue {
  char *key;
  void *data;
} HashMapValue;

typedef struct HashMap {
  LinkedList *data[TABLE_SIZE];
} HashMap;

// Initialize an empty hashmap
HashMap *hashmap_create();

// Insert a new record on the hashmap
void hashmap_insert(HashMap *hashmap, char *key, void *data);

// Returns a record from a key present on the hashmap
void *hashmap_fetch(HashMap *hashmap, char *key);

void hashmap_free(HashMap *hashmap);
#endif
