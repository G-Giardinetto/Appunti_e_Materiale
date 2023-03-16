link: stack_array.o main.o item-int.o
	gcc stack_array.o main.o item-int.o -o adtStack.exe

link-str: stack_list.o list.o main.o item-string.o
	gcc stack_list.o list.o main.o item-string.o -o adtStack.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c
	
stack_array.o:
	gcc -c stack_array.c
	
stack_list.o:
	gcc -c stack_list.c

clean:
	del *.o *.exe
