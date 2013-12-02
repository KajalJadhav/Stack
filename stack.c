#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Stack* create(int typeSize, int length){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->typeSize = typeSize;
	stack->length = length;
	stack->top = -1;
	stack->elements = calloc(stack->length,stack->typeSize);
	return stack;
}

int push(Stack *stack,void *elements){
	if(stack->length == stack->top+1)
		return false;
	memcpy(stack->elements+(stack->typeSize*(stack->top+1)),elements,stack->typeSize);
	stack->top++;
	return true;
}

void* pop(Stack *stack){
	if(isEmpty(stack))
		return 0;
	return stack->elements+((stack->top--))*stack->typeSize;
	}

bool isEmpty(Stack *stack){
	return -1 == stack->top;
}

bool isFull(Stack *stack){
	return (stack->length == stack->top);
}