#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>

#include "../structures/hashmap.h"

void loadPatients(HashMap *hashTable, const char *filename);

#endif
