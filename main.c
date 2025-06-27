#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/structures/hashmap.h"

int main() {
  HashTable hashTable;
  initializeTable(&hashTable);

  loadPatients(&hashTable, "./data/in/pacientes.csv");

  closeLogFile();
  return 0;
}
