#    Makefile
#    Řešení IJC-DU2, 18.4.2023
#    Autor: Krystof Knesl, FIT

CC = gcc
LC_ALL=cs_CZ.utf8
TAIL_FILES= tail.c cbuffer.c
HTAB_FILES=wordcount.c io.c htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_size.c htab_statistics.c
OBJS=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_size.o htab_statistics.o
CFLAGS = -Wall -Wextra -pedantic -O2 -std=c11

all: tail wordcount wordcount-dynamic

# Libraries
libhtab.so:
	$(CC) -shared $(CFLAGS) $(OBJS) -o libhtab.so -fPIC

libhtab.a:
	ar rcs libhtab.a $(OBJS)

# Executables
tail:
	$(CC) $(CFLAGS) $(TAIL_FILES) -o tail

wordcount:
	$(CC) $(CFLAGS) -c $(HTAB_FILES) -fPIC

wordcount-dynamic: libhtab.so
	LD_LIBRARY_PATH="."
	$(CC) $(CFLAGS) -c $(HTAB_FILES) -fPIC


.PHONY: clean zip all

clean:
	rm -rf tail wordcount *.o libhtab.so libhtab.a xknesl03.zip

zip:
	zip xknesl03.zip *.h *.c Makefile