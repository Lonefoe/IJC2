// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include "htab.h"
#include "htab_struct.h"

size_t htab_size(const htab_t * t)
{
    return t->size;
}