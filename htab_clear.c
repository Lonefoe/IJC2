// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Vymaže všechny záznamy z hashovací tabulky

#include "htab.h"
#include "htab_struct.h"

void htab_clear(htab_t * t)
{
    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        htab_item_t *item = t->arr[i];

        while(item != NULL)
        {
            htab_item_t *next = item->next;
            free((char*)item->pair.key);
            free(item);
            item = next;
        }

        t->arr[i] = NULL;
    }

    t->size = 0;
}