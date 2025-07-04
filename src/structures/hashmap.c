#include "hashmap.h"

#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

HashMap *hashmapCreate() {
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));
    return hashmap;
}

HashMapValue *hashmapCreateValue(char *key, void *data) {
    HashMapValue *value = (HashMapValue *)malloc(sizeof(HashMapValue));
    value->key = key;
    value->data = data;
    return value;
}

int hash(const char *key) {
    unsigned int h = 0;
    while (*key)
        h = (h * 31) + *key++;
    return h % TABLE_SIZE;
}

void hashmapFree(HashMap *hashmap) {
    if (hashmap == NULL) {
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        LinkedList *list = hashmap->data[i];

        if (list != NULL) {
            LinkedListNode *curr = list->head;
            while (curr) {
                free(curr->data);
                curr = curr->next;
            }

            linkedlistFree(list);
        }
    }

    free(hashmap);
}

void hashmapInsert(HashMap *hashmap, char *key, void *data) {
    int idx = hash(key);

    LinkedList *list = hashmap->data[idx];
    if (list == NULL) {
        list = linkedlistCreate();
        hashmap->data[idx] = list;
    }

    HashMapValue *value = hashmapCreateValue(key, data);
    linkedlistAppend(list, value);
}

void *hashmapFetch(HashMap *hashmap, char *key) {
    int idx = hash(key);
    LinkedList *list = hashmap->data[idx];

    if (list == NULL) {
        return NULL;
    }

    LinkedListNode *node = list->head;
    while (node) {
        HashMapValue *value = (HashMapValue *)node->data;

        if (strcmp((char *)value->key, key) == 0) {
            return value->data;
        }
        node = node->next;
    }

    return NULL;
}
