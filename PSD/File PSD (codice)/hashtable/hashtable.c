#include <stdlib.h>
#include "list.h"
#include "hashtable.h"
#include "key.h"
#include "item.h"

struct hashtable{
	int size;
	List *entries;
};

HashTable newHashtable(int size){
	HashTable h = malloc(sizeof(struct hashtable));
	h->size = size;
	h->entries = malloc(size * sizeof(List));
	int i;
	for(i = 0; i < size; i++)
		h->entries[i] = newList();
	return h;
}

int insertHash(HashTable h, Entry e){
	int index = hashValue(getKey(e), h->size);
	int pos;
	if(searchList(h->entries[index], e, &pos) == NULL){
		addHead(h->entries[index], e);
		return 1;
	}
	else
		return 0;
}

Entry searchHash(HashTable h, Key k){

	int index = hashValue(k, h->size);

	int pos;
	Entry e1;
	e1 = newEntry(k, NULL);
	return searchList(h->entries[index], e1, &pos);
}

Entry deleteHash(HashTable h, Key k){
	int index = hashValue(k, h->size);
	Entry e1;
	e1 = newEntry(k, NULL);	
	return removeListItem(h->entries[index], e1);
}