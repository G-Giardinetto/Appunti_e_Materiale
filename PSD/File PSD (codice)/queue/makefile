link: queue_array.o main.o item-int.o
	gcc queue_array.o main.o item-int.o -o adtQueue.exe

link-str: queue_list.o list.o main.o item-string.o
	gcc queue_list.o list.o main.o item-string.o -o adtQueue.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c
	
queue_array.o:
	gcc -c queue_array.c
	
queue_list.o:
	gcc -c queue_list.c

clean:
	del *.o *.exe
