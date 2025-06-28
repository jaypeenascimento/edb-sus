#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/structures/hashmap.h"

int main() {
  HashMap *hashmap = hashmap_create();

  loadPatients(hashmap, "./data/in/pacientes.csv");

  closeLogFile();
  return 0;
}
