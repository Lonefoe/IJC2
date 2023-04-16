#    Makefile
#    Řešení IJC-DU2, 15.4.2023
#    Autor: Krystof Knesl, FIT

CC = gcc
LC_ALL=cs_CZ.utf8
FILES= tail.c cbuffer.c
HTAB_FILES=
CFLAGS = -Wall -Wextra -pedantic -O2 -std=c11

all: tail wordcount

wordcount:
	$(CC) $(CFLAGS) $(HTAB_FILES) -o wordcount

tail:
	$(CC) $(CFLAGS) $(FILES) -o tail

.PHONY: clean zip all

clean:
	rm -rf tail *.o xknesl03.zip

zip:
	zip xknesl03.zip *.h $(FILES) $(HTAB_FILES) Makefile