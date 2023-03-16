#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BST newBST()
{
	return NULL;
}
int isEmptyBST(BST bst)
{
	if (bst == NULL)
		return 1;
	return 0;
}

BST getLeft(BST bt)
{
	if(isEmptyBST(bt))
		return NULL;
	return bt->left;
}

BST getRight(BST bt)
{
	if(isEmptyBST(bt))
		return NULL;
	return bt->right;
}

Item getItem(BST bt)
{
	if(isEmptyBST(bt) == 1)
		return NULL;
	return bt->value;
}
Item search(BST bt, Item i)
{
	if(isEmptyBST(bt) == 1)
		return NULL;
	
	int a = cmpItem(i, bt->value);
	
	if(a == 0)
		return bt->value;
	else if(a > 0)
		return search(bt->right, i);
	else if(a < 0)
		return search(bt->left, i);
}
		
Item min(BST bt)
{
	if(isEmptyBST(bt) == 1)
		return NULL;
	
	if(bt->left != NULL)
		return min(bt->left);
		
	return bt->value;
}

Item max(BST bt)
{
	if(isEmptyBST(bt) == 1)
		return NULL;
	
	if(bt->right != NULL)
		return max(bt->right);
		
	return bt->value;
}
void insertBST(BST *bt, Item i)
{
	if(isEmptyBST(*bt)){
		*bt = malloc(sizeof(struct node));
		(*bt)->left = NULL;
		(*bt)->right = NULL;
		(*bt)->value = i;
	}
	
	int a = cmpItem(i, (*bt)->value);
	
	if(a > 0)
		insertBST(&((*bt)->right), i);
	else if(a < 0)
		insertBST(&((*bt)->left), i);
}

Item deleteBST(BST *bt, Item i)
{
	if(isEmptyBST(*bt) == 1)
		return NULL;
	
	int a = cmpItem(i, (*bt)->value);
	
	if(a == 0){
		if(isEmptyBST((*bt)->left)){ //caso 1: il nodo ha un solo sottoalbero
			BST temp = *bt;
			Item e = (*bt)->value;
			*bt = (*bt)->right;
			free(temp);
			return e;
		}else if(isEmptyBST((*bt)->right)){
			BST temp = *bt;
			Item e = (*bt)->value;
			*bt = (*bt)->left;
			free(temp);
			return e;
		}else{  //caso  2: il nodo ha entrambi i sottoalberi
			Item m = max((*bt)->left);
			Item e = (*bt)->value;
			(*bt)->value = m;
			deleteBST(&((*bt)->left), m);
			return e;
		}
	}	
	else if(a > 0)
		return deleteBST(&((*bt)->right), i);
	else if(a < 0)
		return deleteBST(&((*bt)->left), i);
}
