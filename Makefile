#    Makefile
#    Řešení IJC-DU2, 15.4.2023
#    Autor: Krystof Knesl, FIT

CC = gcc
LC_ALL=cs_CZ.utf8
FILES= tail.c cbuffer.c
HTAB_FILES=wordcount.c htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_size.c htab_statistics.c
CFLAGS = -Wall -Wextra -pedantic -O2 -std=c11

all: tail wordcount

wordcount:
	$(CC) $(CFLAGS) $(HTAB_FILES) -o wordcount

tail:
	$(CC) $(CFLAGS) $(FILES) -o tail

.PHONY: clean zip all

clean:
	rm -rf tail wordcount *.o xknesl03.zip

zip:
	zip xknesl03.zip *.h $(FILES) $(HTAB_FILES) Makefile