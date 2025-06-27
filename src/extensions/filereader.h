#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>
#include "../structures/hashmap.h"

void loadPatients(HashTable *hashTable, const char *filename, FILE *logFile);

#endif