#ifndef HASHMAP_H
#define HASHMAP_H

#include "../commons.h"
#include <stdio.h>

typedef struct InfoNode {
  char info[64];
  struct InfoNode *next;
} InfoNode;

typedef struct HashTable {
  InfoNode *table[TABLE_SIZE];
} HashTable;

void initializeTable(HashTable *hashTable);
int hashFunction(const char *id);
void insertPatient(HashTable *hashTable, char *id, char *name, int age,
                   char gender, char *cpf, int priority, int attended);

#endif
