// htab_find.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Hledá zadaný klíč v tabulce, vrací ukazatel na dvojici dat

#include "htab.h"
#include "htab_struct.h"

htab_pair_t* htab_find(const htab_t * t, htab_key_t key)
{
    htab_item_t *item = t->arr[htab_hash_function(key) % t->arr_size];

    while(item != NULL)
    {
        if(strcmp(item->pair.key, key) == 0) {
            return &item->pair;
        }
        
        item = item->next;
    }

    return NULL;
}