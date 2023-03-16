#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{
	int a[] = {20, 10, 30, 15, 5, 25, 40, 3, 6, 35};
	BST bst = newBST();
	int i;
	Item item;
	
	for(i = 0; i < sizeof(a)/sizeof(int); i++)
		insertBST(&bst, &a[i]);
		
	printf("min: ");
	outputItem(min(bst));
	printf("\n");
	
	Item m = max(bst);
	
	printf("max: ");
	outputItem(m);
	printf("\n");
	
	printf("Inserisci un item: ");
	m = inputItem();
	
	deleteBST(&bst, m);
	printf("Cancellato nodo, minimo: ");
	
	m = min(bst);
	outputItem(m);
	printf("\n");
	
	printf("search: ");
	item = inputItem();
	
	if (search(bst, item) != NULL)
		printf("Elemento trovato\n");
	else 
		printf("Elemento non trovato\n");
	
	return 0;
}
