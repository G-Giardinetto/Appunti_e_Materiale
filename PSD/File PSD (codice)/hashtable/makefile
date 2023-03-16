link: list.o main.o item-int.o hashtable.o key_string.o item-entry.o entry.o
	gcc list.o main.o item-int.o hashtable.o key_string.o item-entry.o entry.o -o hashtable.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

hashtable.o:
	gcc -c hashtable.c

key_string.o:
	gcc -c key_string.c

item-entry.o:
	gcc -c item-entry.c

entry.o:
	gcc -c entry.c
	
item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

clean:
	del  *.o *.exe
