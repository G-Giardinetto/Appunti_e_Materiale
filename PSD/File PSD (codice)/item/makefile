link: array.o utils.o main.o item_int.o
	gcc array.o utils.o main.o item_int.o -o array.exe
link_str: array.o utils.o main.o item_string.o
		gcc array.o utils.o main.o item_string.o -o array.exe
array.o:
	gcc -c array.c
utils.o:
	gcc -c utils.c
main.o:
	gcc -c main.c
item_int.o:
	gcc -c item_int.c
item_string.o:
	gcc -c item_string.c
clean:
	rm -f array.o utils.o main.o item_int.o item_string.o array.exe
