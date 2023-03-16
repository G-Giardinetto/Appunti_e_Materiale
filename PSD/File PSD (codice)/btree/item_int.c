#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
	int *p;
	p= malloc (sizeof(int));
	scanf("%d", p);
	return p;
}

void outputItem(Item i){
	int *p=i;
	printf("%d ", *p);
}

int cmpItem(Item i1, Item i2){
	int *p1=i1, *p2=i2;
	return *p1 - *p2;
}
