#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "btree.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;

};

BTree newTree(){

	return NULL;
}


int isEmptyTree(BTree bt){

	if (bt==NULL)
		return 1;
	return 0;

}


BTree buildTree(BTree left, BTree right, Item item){
	
	BTree bt=malloc(sizeof(struct node ));
	
	bt->value=item;
	bt->left=left;
	bt->right=right;

	return bt;
}



Item getBTreeRoot(BTree bt){
	
	if (isEmptyTree(bt))
		return NULL;
	return bt->value;
	
}



BTree getLeft(BTree bt){
	if (isEmptyTree(bt))
		return NULL;
	return(bt->left);
}


BTree getRight(BTree bt){
	
	if (isEmptyTree(bt))
		return NULL;
	return (bt->right);
	
	
}


void preOrder(BTree bt){
	if(!isEmptyTree(bt)){
		outputItem(bt->value);
		preOrder(bt->left);
		preOrder(bt->right);
	}
}
void postOrder(BTree bt){
	if(!isEmptyTree(bt)){
		postOrder(bt->left);
		postOrder(bt->right);
		outputItem(bt->value);	
	}
}
void inOrder(BTree bt){
	if(!isEmptyTree(bt)){
		inOrder(bt->left);
		outputItem(bt->value);
		inOrder(bt->right);
			
	}
}
