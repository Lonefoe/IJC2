// tail.c
// Řešení IJC-DU2, příklad 2), 15.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
// Hledá zadaný klíč v tabulce, vrací ukazatel na dvojici dat

#include "htab.h"
#include "htab_struct.h"
#include <limits.h>
#include <stdio.h>

void htab_statistics(const htab_t * t)
{
    size_t min_length = 99999999999;
    size_t max_length = 0;
    double sum_length = 0.0;
    size_t count = 0;
    for (size_t i = 0; i < htab_bucket_count(t); i++) {
        size_t length = 0;
        for (htab_item_t *item = t->arr[i]; item != NULL; item = item->next) {
            length++;
        }
        if (length > 0) {
            count++;
            sum_length += length;
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
    fprintf(stderr, "Avg length: %lf\n", sum_length / count);
}