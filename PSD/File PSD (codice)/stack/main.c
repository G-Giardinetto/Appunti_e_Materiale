#include <stdio.h>
#include "stack.h"
#include "item.h"
#define DIM 5

int main(){
	
	int i;
	Item e;
	Stack s = newStack();
	for(i = 0; i < DIM; i++){
		e = inputItem();
		push(s, e);
		printStack(s);
		printf("\n");
	}
	
	for(i = 0; i < DIM+1; i++){
		
		e = top(s);
		if(e){
			printf("Elemento top: ");
			outputItem(e);
		}
		
		pop(s);
		printStack(s);
		printf("\n");
	}
	
	
	return 0;
}
