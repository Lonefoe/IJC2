// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Definuje hashovaci funkci

#include "htab.h"
#include <stdio.h>
#include <stdint.h>

size_t htab_hash_function(htab_key_t str)
{
    uint32_t h = 0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}