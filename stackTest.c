#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack* a,Stack* b){
	int result = (a->length == b->length);
	if(!result)
		return result;
	return 0 == memcmp(a->elements,b->elements,b->length*b->typeSize);
}

void test_1_create_integer_creates_with_zeroes(){
	int two_zeros[] = {0,0};
	Stack b = {two_zeros,-1,4,2};
	Stack* a = create(sizeof(int),2);
	ASSERT(areEqual(a,&b));
}

void test_2_create_float_creates_with_zeroes(){
	float two_zeros[] = {0.0,0.0};
	Stack b = {&two_zeros,-1,4,2};
	Stack* a = create(sizeof(float),2);
	ASSERT(areEqual(a,&b));
}

void test_3_create_character_creates_with_null(){
	char two_nulls[] = {'\0','\0'};
	Stack b = {&two_nulls,-1,sizeof(char),2};
	Stack* a = create(sizeof(char),2);
	ASSERT(areEqual(a,&b));
}

void test_4_create_double_creates_with_zeroes(){
	double two_zeros[] = {0.000000,0.000000};
	Stack b = {&two_zeros,-1,sizeof(double),2};
	Stack* a = create(sizeof(double),2);
	ASSERT(areEqual(a,&b));
}

void test_5_push_integer_element_in_stack(){
    Stack* actual = create(sizeof(int),2);
    int value = 1;
    int result = push(actual,&value);
    int* data = (int*)actual->elements;
    ASSERT(data[0] == 1);
    free(actual);        
}

void test_6_push_float_element_in_stack(){
	Stack* actual = create(sizeof(float),2);
	float value = 1.0;
	float result = push(actual,&value);
	float* data = (float*)actual->elements;
	ASSERT(data[0] == 1.0);
	free(actual);
}

void test_7_push_double_element_in_stack(){
	Stack* actual = create(sizeof(double),2);
	double value = 1.000000;
	double result = push(actual,&value);
	double* data = (double*)actual->elements;
	ASSERT(data[0] == 1.000000);
	free(actual);
}

void test_8_push_character_element_in_stack(){
    Stack* actual = create(sizeof(char),2);
    char value = 'k';
    int res = push(actual,&value);
    char* data = (char*)actual->elements;
    ASSERT(data[0] == 'k');
    free(actual);        
}

void test_9_pop_integer_element_from_stack(){
    Stack* actual = create(sizeof(int),5);
    int* data = actual->elements;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data[3] = 4;
    data[4] = 5;
    actual->top = 4;
    ASSERT(5 == *(int*)pop(actual));
}

void test_10_pop_float_element_from_stack(){
	Stack* actual = create(sizeof(float),5);
	float* data = actual->elements;
	data[0] = 1.0;
	data[1] = 2.0;
	data[2] = 3.0;
	data[3] = 4.0;
	data[4] = 5.0;
	actual->top = 4;
	ASSERT(5 == *(float*)pop(actual));
}

void test_11_pop_double_element_from_stack(){
	Stack* actual = create(sizeof(double),5);
	double* data = actual->elements;
	data[0] = 1.000000;
	data[1] = 2.000000;
	data[2] = 3.000000;
	data[3] = 4.000000;
	data[4] = 5.000000;
	actual->top = 4;
	ASSERT(5 == *(double*)pop(actual));
}

void test_12_pop_character_element_from_stack(){
    Stack* actual = create(sizeof(char),3);
    char* data = actual->elements;
    data[0] = 'k';
    data[1] = 'a';
    data[2] = 'j';
    actual->top = 2;
    ASSERT('j' == *(char*)pop(actual));
}

void test_fail(){
	ASSERT(0);
}