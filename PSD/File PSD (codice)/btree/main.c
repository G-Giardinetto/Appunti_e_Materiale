#include <stdio.h>
#include "btree.h"

int main(){
	
	BTree th,tc,ta,td,tl,tp,ts,to,tq;
	
	to=buildTree(NULL,NULL,"o");
	tq=buildTree(NULL,NULL,"q");
	td=buildTree(NULL,NULL,"d");
	tl=buildTree(to,tq,"l");
	tp=buildTree(NULL,NULL,"p");
	ts=buildTree(NULL,NULL,"s");
	ta=buildTree(td,tl,"a");
	tc=buildTree(tp,ts,"c");
	th=buildTree(ta,tc,"h");
	
	printf("preorder: ");
	preOrder(th);
	printf("\npostorder: ");
	postOrder(th);
	printf("\ninorder: ");
	inOrder(th);
	printf("\n");
	
	return 0;
}