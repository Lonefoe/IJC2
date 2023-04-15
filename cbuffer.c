// cbuffer.c
// Řešení IJC-DU2, příklad a), 13.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Definuje funkce pro kruhový buffer

#include "cbuffer.h"

// Creates a circular buffer of n size
cbuffer* cb_create(int size) {
    cbuffer *cb = malloc(sizeof(cbuffer));
    cb->buffer = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        cb->buffer[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char)); // +1 for null-terminator
    }
    cb->head = 0;
    cb->tail = -1;
    cb->size = size;
    return cb;
}

// Sets next element
void cb_put(cbuffer *cb, char *line) {
    if(cb->head == cb->tail) return;    // Buffer is full
    
    strcpy(cb->buffer[cb->head++], line);
    cb->head %= cb->size;
    if(cb->tail == -1) cb->tail = 0;    // Init tail
}

// Gets next element
char* cb_get(cbuffer *cb) {

    char *line = cb->buffer[cb->tail++];
    cb->tail %= cb->size;
    return line;
}

// Frees allocated memory of a circular buffer
void cb_free(cbuffer *cb) {
    int i;
    for (i = 0; i < cb->size; i++) {
        free(cb->buffer[(cb->head + i) % cb->size]);
    }
    free(cb->buffer);
    free(cb);
}

bool cb_is_full(cbuffer *cb) { 
    if (cb->head == cb->tail) return true;
    else return false;
}