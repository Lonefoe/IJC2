// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include "htab.h"
#include "htab_struct.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
    free(t->arr);
    free(t);
}