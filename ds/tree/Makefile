CC=gcc
CFLAGS=-Wall

bstree: bstree.o bstree_main.c
	$(CC) $(CFLAGS) -c bstree.c
	$(CC) $(CFLAGS) bstree.o bstree_main.c -o bstree

clean:
	rm *.o
	rm bstree