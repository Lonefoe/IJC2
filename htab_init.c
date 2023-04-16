// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include "htab.h"

htab_t* htab_init(const size_t n)
{
    htab_t *hashtab = malloc(sizeof(htab_t) + n * sizeof(htab_pair_t *));
    if (hashtab == NULL) {
        return NULL;
    }
    hashtab->arr_size = n;
    hashtab->size = 0;
    for (size_t i = 0; i < n; i++) {
        hashtab->arr[i] = NULL;
    }
    return hashtab;
}