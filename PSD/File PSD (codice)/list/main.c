#include <stdio.h>
#include "list.h"
#include "item.h"
#define DIM 5

int main(){
	
	int i, flag;
	Item item;
	
	List l= newList();
	
	for(i=0;i<DIM;i++)
		addListTail(l, inputItem());
	
	printf("la taglia della lista è %d \n", sizeList(l));
	printList(l);
	printf("\n");
	
	List l1= cloneList(l);

	printList(l1);
	
	return 0;
}
