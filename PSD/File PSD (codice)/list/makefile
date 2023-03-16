link: list.o main.o item-int.o
	gcc list.o main.o item-int.o -o adtList.exe

link-str: list.o main.o item-string.o
	gcc list.o main.o item-string.o -o adtList.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

clean:
	rm -- *.o *.exe
