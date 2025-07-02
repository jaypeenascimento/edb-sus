#include "hashmap.h"

#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

HashMap *hashmap_create() {
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));
    return hashmap;
}

HashMapValue *hashmap_create_value(char *key, void *data) {
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

void hashmap_free(HashMap *hashmap) {
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

            linkedlist_free(list);
        }
    }

    free(hashmap);
}

void hashmap_insert(HashMap *hashmap, char *key, void *data) {
    int idx = hash(key);

    LinkedList *list = hashmap->data[idx];
    if (list == NULL) {
        list = linkedlist_create();
        hashmap->data[idx] = list;
    }

    HashMapValue *value = hashmap_create_value(key, data);
    linkedlist_append(list, value);
}

void *hashmap_fetch(HashMap *hashmap, char *key) {
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
