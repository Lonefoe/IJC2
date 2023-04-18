// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Vymaže záznam s hledanou hodnotou key z tabulky
// Vrací true, pokud byl záznam nalezen a odstraněn, jinak false

#include "htab.h"
#include "htab_struct.h"

bool htab_erase(htab_t * t, htab_key_t key)
{
    htab_item_t *item = t->arr[htab_hash_function(key) % t->arr_size];
    htab_item_t *prev_item = NULL;

    while(item != NULL)
    {
        // Key found
        if(strcmp(item->pair.key, key) == 0) {
            if (prev_item != NULL) {
                prev_item->next = item->next;
            }
            free(item);
            t->size--;
            return true;
        }
        
        prev_item = item;
        item = item->next;
    }

    return false;
}