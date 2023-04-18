// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include "htab.h"
#include "htab_struct.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        htab_item_t *item = t->arr[i];
        while(item != NULL){
            f(&item->pair);
            item = item->next;
        }
    }
    
}