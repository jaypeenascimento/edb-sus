#ifndef HASHMAP_H
#define HASHMAP_H

#include "../commons.h"
#include <stdio.h>

typedef struct InfoNode {
  char info[64];
  struct InfoNode *next;
} InfoNode;

typedef struct HashMap {
  InfoNode *table[TABLE_SIZE];
} HashMap;

void initializeTable(HashMap *hashTable);
int hashFunction(const char *id);
void insertPatient(HashMap *hashTable, char *id, char *name, int age,
                   char gender, char *cpf, int priority, int attended);

#endif
