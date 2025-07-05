#include "patientdata_manager.h"

#include <stdlib.h>
#include <string.h>

Patient *patientDataManagerGetRandomPatient(HashMap *hashmap) {
    int total = 0;
    Patient *candidates[1024];
    for (int i = 0; i < TABLE_SIZE; i++) {
        LinkedList *list = hashmap->data[i];
        if (list) {
            LinkedListNode *curr = list->head;
            while (curr) {
                HashMapValue *value = (HashMapValue *)curr->data;
                Patient *p = (Patient *)value->data;
                if (p && p->attended == 0) {
                    candidates[total++] = p;
                }
                curr = curr->next;
            }
        }
    }
    if (total == 0)
        return NULL;

    int randomIndex = rand() % total;
    return candidates[randomIndex];
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

            free(value->key);
            free(value);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
