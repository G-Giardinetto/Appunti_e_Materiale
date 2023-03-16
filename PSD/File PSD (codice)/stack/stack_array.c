#include <stdlib.h>
#include "stack.h"
#include "item.h"
#define MAXSTACK 50

struct stack{
	Item elements[MAXSTACK];
	int top;
};

Stack newStack(){
	Stack stack = malloc(sizeof(struct stack));
	stack->top = 0;
	
	return stack;
}

int isEmptyStack(Stack s){
	if(s->top == 0)
		return 1;
	else
		return 0;
}

int push(Stack s, Item e){
	if(s->top == MAXSTACK)
		return 0;
	else{
		s->elements[s->top] = e;
		(s->top)++;
		return 1;
	}
}

int pop(Stack s){
	if(isEmptyStack(s) == 1)
		return 0;
	else{
		(s->top)--;
		return 1;
	}
}

Item top(Stack s){
	if(isEmptyStack(s) == 1)
		return NULL;
	else{
		return s->elements[(s->top)-1];
	}
}

void printStack(Stack s){
	int i;
	
	for(i = (s->top)-1; i >= 0; i--)
		outputItem(s->elements[i]);
}
