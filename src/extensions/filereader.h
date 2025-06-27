#ifndef FILEREADER_H
#define FILEREADER_H

#include "../structures/hashmap.h"
#include <stdio.h>

void loadPatients(HashTable *hashTable, const char *filename);

#endif
