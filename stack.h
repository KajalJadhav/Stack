#include <stdbool.h>

typedef char String[256];

typedef struct{
	void *elements;
	int top;
	int typeSize;
	int length;
}Stack;

Stack* create(int typeSize,int elements);
int push(Stack *stack,void* elements);
void* pop(Stack *stack);
int top(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
