// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include "htab.h"
#include "htab_struct.h"

htab_pair_t* htab_lookup_add(htab_t * t, htab_key_t key)
{
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];
    
    while (item != NULL) {
        if (strcmp(item->pair.key, key) == 0) {
            return &item->pair;
        }
        item = item->next;
    }
    item = malloc(sizeof(htab_item_t));
    if (item == NULL) {
        return NULL;
    }
    
    item->next = t->arr[index];
    t->arr[index] = item;
    item->pair.key = key;
    item->pair.value = 0;

    t->size++;
    return &item->pair;
}