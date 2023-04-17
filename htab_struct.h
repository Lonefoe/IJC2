// htab_struct.h
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Privátní soubor s definicí struktury tabulky

#ifndef HTAB_STRUCT_H
#define HTAB_STRUCT_H

#include "htab.h"

typedef struct {
    htab_pair_t pair;
    struct htab *next;
} htab_item_t;

struct htab {
    size_t arr_size;        // velikost pole ukazatelů
    size_t size;            // počet prvků v tabulce
    htab_item_t *arr[];     // pole ukazatelů na prvky tabulky
};

#endif // HTAB_STRUCT_H