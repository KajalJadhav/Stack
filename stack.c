#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Stack* create(int elementSize, int size){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->elementSize = elementSize;
	stack->size = size;
	stack->top = -1;
	stack->elements = calloc(stack->size,stack->elementSize);
	return stack;
}

int push(Stack* Stack,void* elements){
    void* address;
    if(isFull(Stack))
        return 0;
    address = Stack->elements+(++(Stack->top)*Stack->elementSize);
    memcpy(address,elements,Stack->elementSize);
    return 1;
}

void* pop(Stack *stack){
	if(isEmpty(stack))
		return 0;
	return stack->elements+((stack->top--))*stack->elementSize;
}

int isEmpty(Stack *stack){
	if(stack->top == -1)
		return 1;
	return 0;
}

int isFull(Stack *stack){
	return (stack->size == stack->top);
}

void* top(Stack *stack){
	return stack->elements + ((stack->top)*stack->elementSize);
}