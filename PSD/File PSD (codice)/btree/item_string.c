#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define NCHAR 20

Item inputItem(){
	char *p;
	p= malloc (NCHAR * sizeof(char));
	scanf("%s", p);
	return p;
}

void outputItem(Item i){
	char *p=i;
	printf("%s ", p);
}

int cmpItem(Item i1, Item i2){
	char *p1=i1, *p2=i2;
	return strcmp(p1, p2);
}
