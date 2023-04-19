// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Vrací ukazatel na dvojici (buď nově vytvořenou nebo již existující)
// Při chybě s pamětí vrací NULL

#include "htab.h"
#include "htab_struct.h"
#include <stdio.h>

htab_pair_t* htab_lookup_add(htab_t * t, htab_key_t key)
{   
    htab_pair_t *pair = htab_find(t, key);
    if(pair != NULL) return pair;

    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];

    item = malloc(sizeof(htab_item_t));
    if (item == NULL) {
        return NULL;
    }

    char *new_key = malloc((strlen(key) + 1) * sizeof(char));

    if(new_key == NULL) {
        free(new_key);
        return NULL;
    }

    strcpy(new_key, key);
    
    item->pair.key = new_key;
    item->pair.value = 0;
    
    item->next = t->arr[index];
    t->arr[index] = item;

    t->size++;
    return &item->pair;
}