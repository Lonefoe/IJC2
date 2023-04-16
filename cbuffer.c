// cbuffer.c
// Řešení IJC-DU2, příklad 1), 13.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Definuje funkce pro kruhový buffer

#include "cbuffer.h"

// Creates a circular buffer of n size
cbuffer* cb_create(int size) {
    cbuffer *cb = malloc(sizeof(cbuffer));
    cb->buffer = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        cb->buffer[i] = NULL;
    }
    cb->head = 0;
    cb->tail = -1;
    cb->size = size;
    return cb;
}

// Sets next element
void cb_put(cbuffer *cb, char *line) {
    if(cb->head == cb->tail && cb->size != 1) return;    // Buffer is full
    
    if(cb->buffer[cb->head] == NULL) cb->buffer[cb->head] = malloc(strlen(line) * sizeof(char));
    else cb->buffer[cb->head] = realloc(cb->buffer[cb->head], strlen(line) * sizeof(char));
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
    for (int i = 0; i < cb->size; i++) {
        if(cb->buffer[(cb->head + i) % cb->size] != NULL)
            free(cb->buffer[(cb->head + i) % cb->size]);
    }
    free(cb->buffer);
    free(cb);
}

bool cb_is_full(cbuffer *cb) { 
    if (cb->head == cb->tail) return true;
    else return false;
}