// io.c
// Řešení IJC-DU2, příklad 2), 18.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Definuje funkci pro cteni slova

#include "io.h"
#include <stdlib.h>
#include <ctype.h>

int read_word(char* s, int max, FILE *f)
{
    int c = 0;
    int length = 0;
    static int warning = 0;

    // Skip leading whitespace
    while ((c = fgetc(f)) != EOF && isspace(c));

    if(c == EOF) {
        return EOF;
    }

    while (c != EOF && !isspace(c)) {
        if(length >= max) break;
        
        s[length++] = c;
        c = fgetc(f);
    }

    s[length] = '\0';   // add null terminator

    if (length >= max && !isspace(c)) {
        if(warning != 1) {
            fprintf(stderr, "Warning: Word is too long! Max length is %d.\n", max);
            warning = 1;
        }
        // Skip the rest of the word
        while ((c = fgetc(f)) != EOF && !isspace(c));
    }
    
    return length;
}