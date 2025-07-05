#include "patientdata_manager.h"
#include <stdlib.h>
#include <string.h>

Patient *patientDataManagerGetRandomPatient(HashMap *hashmap) {
  int total = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    LinkedList *list = hashmap->data[i];
    if (list) {
      LinkedListNode *curr = list->head;
      while (curr) {
        total++;
        curr = curr->next;
      }
    }
  }
  if (total == 0)
    return NULL;

  int randomIndex = rand() % total;
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    LinkedList *list = hashmap->data[i];
    if (list) {
      LinkedListNode *curr = list->head;
      while (curr) {
        if (count == randomIndex) {
          HashMapValue *value = (HashMapValue *)curr->data;
          return (Patient *)value->data;
        }
        count++;
        curr = curr->next;
      }
    }
  }
  return NULL;
}

void patientRemove(HashMap *hashmap, char *key) {
  int idx = hash(key);
  LinkedList *list = hashmap->data[idx];
  if (!list)
    return;

  LinkedListNode *curr = list->head;
  LinkedListNode *prev = NULL;
  while (curr) {
    HashMapValue *value = (HashMapValue *)curr->data;
    if (strcmp(value->key, key) == 0) {
      if (prev) {
        prev->next = curr->next;
      } else {
        list->head = curr->next;
      }
      free(curr->data);
      free(curr);
      break;
    }
    prev = curr;
    curr = curr->next;
  }
}
