#include <stdio.h>
#include "list.h"
#include "item.h"
#include "hashtable.h"
#include "entry.h"
#include "key.h"
#define DIM 5

int main(){
	HashTable hash = newHashtable(DIM);
	int i;
	Key k;
	Entry e;
	Item item;
	for(i = 0; i < DIM; i++){
		k = inputKey();
		item = inputItem();
		e = newEntry(k, item);
		insertHash(hash, e);
	}
	
	printf("Ricerca di una chiave\n");
	k = inputKey();
	e = searchHash(hash, k);
	if(e == NULL) 
		printf("Non trovato\n");
	else
		outputItem(getValue(e));
	return 0;
}
