link: bst.o main.o item_int.o bst.o
	gcc  main.o item_int.o bst.o -o bst.exe
link_str:  bst.o main.o item_string.o
		gcc  main.o item_string.o bst.o -o bst.exe
bst.o:
	gcc -c bst.c
main.o:
	gcc -c main.c
item_int.o:
	gcc -c item_int.c
item_string.o:
	gcc -c item_string.c
clean:
	rm -f *.o *.exe
