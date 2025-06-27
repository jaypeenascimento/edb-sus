#include "hashmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../extensions/logger.h"

void initializeTable(HashTable *hashTable) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable->table[i] = NULL;
  }
}

int hashFunction(const char *id) {
  unsigned int h = 0;
  while (*id)
    h = (h * 31) + *id++;
  return h % TABLE_SIZE;
}

void insertPatient(HashTable *hashTable, char *id, char *name, int age,
                   char gender, char *cpf, int priority, int attended) {
  int index = hashFunction(id);
  int startIndex = index;

  while (hashTable->table[index] != NULL) {
    index = (index + 1) % TABLE_SIZE;
    if (index == startIndex) {
      logMessage(
          "[ERROR] Tabela hash cheia, não foi possível inserir o paciente %s",
          id);
      return;
    }
  }

  InfoNode *idNode = malloc(sizeof(InfoNode));
  strncpy(idNode->info, id, sizeof(idNode->info) - 1);
  idNode->info[sizeof(idNode->info) - 1] = '\0';

  InfoNode *nameNode = malloc(sizeof(InfoNode));
  strncpy(nameNode->info, name, sizeof(nameNode->info) - 1);
  nameNode->info[sizeof(nameNode->info) - 1] = '\0';

  InfoNode *ageNode = malloc(sizeof(InfoNode));
  snprintf(ageNode->info, sizeof(ageNode->info), "%d", age);

  InfoNode *genderNode = malloc(sizeof(InfoNode));
  genderNode->info[0] = gender;
  genderNode->info[1] = '\0';

  InfoNode *cpfNode = malloc(sizeof(InfoNode));
  strncpy(cpfNode->info, cpf, sizeof(cpfNode->info) - 1);
  cpfNode->info[sizeof(cpfNode->info) - 1] = '\0';

  InfoNode *priorityNode = malloc(sizeof(InfoNode));
  snprintf(priorityNode->info, sizeof(priorityNode->info), "%d", priority);

  InfoNode *attendedNode = malloc(sizeof(InfoNode));
  snprintf(attendedNode->info, sizeof(attendedNode->info), "%d", attended);

  idNode->next = nameNode;
  nameNode->next = ageNode;
  ageNode->next = genderNode;
  genderNode->next = cpfNode;
  cpfNode->next = priorityNode;
  priorityNode->next = attendedNode;
  attendedNode->next = NULL;

  hashTable->table[index] = idNode;

  logMessage("Paciente inserido: [ID: %s, Nome: %s, Idade: %s, Sexo: %s, CPF: "
             "%s, Prioridade: %s, Atendido: %s] no índice %d",
             idNode->info, nameNode->info, ageNode->info, genderNode->info,
             cpfNode->info, priorityNode->info, attendedNode->info, index);
}
