// htab_init.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Vytváří a alokuje novou hashovací tabulku

#include "htab.h"
#include "htab_struct.h"

htab_t* htab_init(const size_t n)
{
    htab_t *h = malloc(sizeof(htab_t) + n * sizeof(htab_item_t *));
    if (h == NULL) {
        return NULL;
    }
    h->arr_size = n;
    h->size = 0;
    for (size_t i = 0; i < n; i++) {
        h->arr[i] = NULL;
    }
    return h;
}