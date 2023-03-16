#include <stdlib.h>
#include "item.h"
#include "list.h"

struct list {
	
	int size;
	struct node *head;

};

struct node{

	Item value;
	struct node *next;

};

List newList(){
	
	List l= malloc(sizeof(struct list));
	
	l->size = 0;
	l->head = NULL;
	
	return l;
}

int isEmpty(List l){
	
	if(l->size==0)
		return 1;
	else
		return 0;
}

void addHead(List l, Item i){

	struct node *n = malloc(sizeof(struct node));
	//aggancio l'item al nuovo nodo
	n->value = i;
	
	n->next = l->head;
	
	//aggiorno la nuova head
	l->head = n;
	
	(l->size)++;
}

Item removeHead(List l){

	Item i;

	if(isEmpty(l))
		return NULL;
	
	struct node *t = l->head;

	//ho agganciato la testa di l al successivo del nodo
	l->head = t->next;
	
	//salvo l'item in una variabile
	i= t->value;
	//libero t dal valore
	free(t);
	(l->size)--;
	return i;
}


Item getHead(List l){
	
	if(isEmpty(l))
		return NULL;
	else
		return l->head->value;
	
}

int sizeList(List l){
	
	return l->size;
	
}

void printList(List l){
	
	struct node *p;
	
	for(p = l->head; p != NULL; p = p->next)
		outputItem(p->value);
	
}

// Ricerca all'interno della lista
Item searchList(List l, Item item, int *pos){
	struct node *p;
	*pos = 0;

	for(p = l->head; p != NULL; p = p->next, (*pos)++)
		if (compareItem(item, p->value) == 0)
			return p->value;		

	*pos = -1;
	return NULL;	
}

// Rimuovi item dalla lista
Item removeListItem(List l, Item item){
	if (isEmpty(l))
		return NULL;

	struct node *p, *prev;
	Item temp;

	for(p = l->head; p != NULL; prev = p, p = p->next)
		if (compareItem(p->value, item) == 0)
			if (p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;

				temp = p->value;
				free(p);
				
				(l->size)--;
				return temp;
			}
	
	return NULL;
}

Item removeListItemPos(List l, int pos){
	if (isEmpty(l))
		return NULL;

	struct node *p, *prev;
	Item temp;
	int i;

	for(p = l->head, i=0; p != NULL; prev = p, p = p->next, i++)
		if (i == pos)
			if (p == l->head)
				return removeHead(l);
			else{
				prev->next = p->next;

				temp = p->value;
				free(p);
				
				(l->size)--;
				return temp;
			}
	
	return NULL;
}

int addListItem (List l, Item i, int pos){
	
	if(pos < 0 || pos > l->size)
		return 0;
	
	if(pos == 0)
	{
		addHead(l, i);
		return 1;
	}
	
	int nodo=0;
	struct node	*p;
	
	for(p = l->head; nodo < pos-1; p = p->next, nodo++)
		;
	
	struct node *newNode= malloc(sizeof(struct node));
	newNode->next = p->next;
	newNode->value = i;
	
	p->next = newNode;
	
	(l->size)++;
	
	return 1;
}

int addListTail (List l, Item i){
	return addListItem (l, i, l->size);
}

void reverseList(List l)
{
	struct node *prev= NULL, *p, *temp;
	
	for(p = l->head; p != NULL; prev = p, p = temp){
		temp= p->next;
		p->next = prev;
	}
	
	l->head = prev;
}
List cloneList (List l)
{
	struct node *p;
	List l1= newList();
	
	for(p = l->head; p != NULL; p = p->next){
		addListTail (l1, p->value);
	}
	
	return l1;
}