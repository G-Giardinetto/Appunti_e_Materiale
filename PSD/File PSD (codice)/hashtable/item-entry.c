#include "key.h"
#include "item.h"
#include "entry.h"

int compareItem(Item a, Item b){
	Entry a1 = a;
	Entry b1 = b;
	Key k1 = getKey(a1);
	Key k2 = getKey(b1);
	return !equals(k1, k2);
}