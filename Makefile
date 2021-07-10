CFLAGS = -g -Wall -Wextra
GCC = gcc

all:
	deck_combinatorics

clean:
	rm -f deck_combinatorics

deck_combinatorics: deck_combinatorics.c
	$(GCC) $(CFLAGS) -o deck_combinatorics
