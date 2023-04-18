// wordcount.c
// Řešení IJC-DU2, příklad a), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "htab.h"
#include "htab_struct.h"

#define HTAB_SIZE 6151

char *trim_whitespace(char *str) {
    char *end;
    // Trim leading white space
    while (isspace((unsigned char)*str)) {
        str++;
    }
    // If all white space was removed, return an empty string
    if (*str == 0) {
        return str;
    }
    // Trim trailing white space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    // Add null terminator to the end of the trimmed string
    *(end+1) = 0;
    return str;
}

void htab_print(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main() {

    htab_t *word_table = htab_init(HTAB_SIZE);
    
    char word[100];
    while (scanf("%s", word) != EOF) {
        char* trimmed_word = trim_whitespace(word);
        htab_pair_t *pair = htab_lookup_add(word_table, trimmed_word);
        pair->value++;
    }

    htab_for_each(word_table, htab_print);

    htab_free(word_table);
    return 0;
}
