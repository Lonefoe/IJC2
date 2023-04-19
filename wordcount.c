// wordcount.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Program počítá četnost slov ve vstupním textu,
// slovo je cokoli oddělené "bílým znakem"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "htab.h"
#include "io.h"

#define HTAB_SIZE 6151
#define MAX_WORD_LENGTH 255

void htab_print(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main() {
    htab_t *word_table = htab_init(HTAB_SIZE);
    
    char *word = malloc((MAX_WORD_LENGTH + 1) * sizeof(char));

    while (read_word(word, MAX_WORD_LENGTH, stdin) != EOF) {
        htab_pair_t *pair = htab_lookup_add(word_table, word);

        if(pair == NULL) {
            fprintf(stderr, "Error: Memory allocation failed! Terminating...\n");
            free(word);
            exit(1);
        }

        pair->value++;
    }
    free(word);

    htab_for_each(word_table, htab_print);

    htab_free(word_table);
    return 0;
}
