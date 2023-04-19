// htab_statistics.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Vypisuje statistiky tabulky na stderr

#include "htab.h"
#include "htab_struct.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void htab_statistics(const htab_t * t)
{
    size_t min_length = INT_MAX;
    size_t max_length = 0;
    double sum = 0.0;
    size_t count = 0;

    for (size_t i = 0; i < htab_bucket_count(t); i++) {
        size_t length = 0;

        htab_item_t *item = t->arr[i];
        while(item != NULL) {
            length++;
            item = item->next;
        }

        if (length > 0) {
            count++;
            sum += length;

            if (length < min_length) {
                min_length = length;
            }
            
            if (length > max_length) {
                max_length = length;
            }
        }

    }
    
    fprintf(stderr, "Number of items: %lu\n", htab_size(t));
    fprintf(stderr, "Bucket count: %lu\n", htab_bucket_count(t));
    fprintf(stderr, "Min length: %lu\n", min_length);
    fprintf(stderr, "Max length: %lu\n", max_length);
    fprintf(stderr, "Avg length: %lf\n", sum / count);
}