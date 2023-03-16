link:  btree.o main.o item_string.o
		gcc  main.o item_string.o btree.o -o btree.exe 
link_int: btree.o main.o item_int.o
	gcc  main.o item_int.o -o array.exe
btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c
item_int.o:
	gcc -c item_int.c
item_string.o:
	gcc -c item_string.c
clean:
	rm -f btree.o main.o item_int.o item_string.o btree.exe
