#ifndef HASHMAP_H
#define HASHMAP_H

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

HashMap *hashmap_create();

void hashmap_insert(HashMap *hashmap, char *key, void *data);

void *hashmap_fetch(HashMap *hashmap, char *key);

void hashmap_free(HashMap *hashmap);
#endif
