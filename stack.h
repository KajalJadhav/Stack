#include <stdbool.h>

typedef char String[256];

typedef struct{
	void *elements;
	int top;
	int elementSize;
	int size;
}Stack;

Stack* create(int elementSize,int size);
int push(Stack *stack,void* elements);
void* pop(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void* top(Stack *stack);
