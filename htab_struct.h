// htab_struct.h
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Privátní soubor s definicí struktur tabulky

#ifndef HTAB_STRUCT_H
#define HTAB_STRUCT_H

#include "htab.h"

typedef struct htab_item htab_item_t;

struct htab_item {
    htab_pair_t pair;
    htab_item_t *next;
};

struct htab {
    size_t arr_size;        // hash table capacity
    size_t size;            // item count
    htab_item_t *arr[];     // item pointer array
};

#endif // HTAB_STRUCT_H