#include <stdlib.h>
#include "entry.h"
#include "item.h"

struct entry
{
	Key key;
	Item value;	
};

Entry newEntry(Key k, Item i)
{
	Entry e=malloc(sizeof(struct entry));
	e->key=k;
	e->value=i;
	return e;
}

Key getKey(Entry e)
{
	if(e!=NULL)
		return e->key;
	return NULL;
}

Item getValue(Entry e)
{
	if(e!=NULL)
		return e->value;
	return NULL;
}