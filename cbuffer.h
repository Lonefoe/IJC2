// cbuffer.h
// Řešení IJC-DU2, příklad 1), 13.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Deklaruje funkce pro kruhový buffer

#ifndef CBUFFER_H
#define CBUFFER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_LINE_LENGTH 4096

typedef struct {
    char **buffer;  // Pointer to buffer, buffer = array of N strings
    int head;       // Write elem index
    int tail;       // Read elem index
    int size;       // Number of buffer elems
} cbuffer;

cbuffer* cb_create(int size);
void cb_put(cbuffer *cb, char *line);
char* cb_get(cbuffer *cb);
void cb_free(cbuffer *cb);
bool cb_is_full(cbuffer *cb);

#endif // CBUFFER_H