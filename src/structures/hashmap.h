#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>

#include "../commons.h"
#include "linkedlist.h"

typedef struct HashMapValue {
    char *key;
    void *data;
} HashMapValue;

typedef struct HashMap {
    LinkedList *data[TABLE_SIZE];
} HashMap;

HashMap *hashmapCreate();

void hashmapInsert(HashMap *hashmap, char *key, void *data);

void *hashmapFetch(HashMap *hashmap, char *key);

void hashmapFree(HashMap *hashmap);

int hash(const char *key);
#endif
