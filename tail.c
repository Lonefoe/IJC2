// tail.c
// Řešení IJC-DU2, příklad a), 13.4.2023
// Autor: Krystof Knesl, FIT
// Přeloženo: gcc 10.2
//

#include "cbuffer.h"

// Reads lines from cbuffer and prints them
void read_cbuffer(cbuffer *cb, int n, bool full_flag)
{
    if(full_flag) cb->tail = cb->head;  // Start from the beginning
    for (int i = 0; i < n; i++) {
        char *line = cb_get(cb);
        if(line == NULL) break;

        printf("%s", line);
    }
}

int main(int argc, char** argv) {
    int line_num = 10;
    char *filename = NULL;
    FILE *file = NULL;
    bool full_flag = 0;

    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if(argv[i][1] == 'n')
            {
                int num = atoi(argv[i+1]);
                if(num > 0) {
                    line_num = num;
                } else {
                    fprintf(stderr, "Error: Number of lines is less than 1.\n");
                    exit(1);
                }
            }
        } else {
            filename = argv[i];
        }
    }

    if(filename != NULL) {
        file = fopen(filename, "r");

        if(file == NULL) 
        {
            fprintf(stderr, "Error: File could not be opened.\n");
            exit(1);
        }
    } else file = stdin;    // Read from standard input

    cbuffer *cb = cb_create(line_num);
    char line[MAX_LINE_LENGTH];

    // Read file line by line into circular buffer
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        cb_put(cb, line);
        if(cb_is_full(cb)) {
            cb_get(cb);
            full_flag = 1;
        }
    }

    read_cbuffer(cb, line_num, full_flag);

    fclose(file);

    return 0;
}