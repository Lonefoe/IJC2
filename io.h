// io.h
// Řešení IJC-DU2, příklad 2), 18.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Deklaruje funkci pro cteni slova

#ifndef IO_H
#define IO_H

#include <stdio.h>

int read_word(char* s, int max, FILE *f);

#endif