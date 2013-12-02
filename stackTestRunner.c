#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_create_integer_creates_with_zeroes");
	setup();
		test_1_create_integer_creates_with_zeroes();
	tearDown();
	testEnded();
	testStarted("test_2_create_float_creates_with_zeroes");
	setup();
		test_2_create_float_creates_with_zeroes();
	tearDown();
	testEnded();
	testStarted("test_3_create_character_creates_with_null");
	setup();
		test_3_create_character_creates_with_null();
	tearDown();
	testEnded();
	testStarted("test_4_create_double_creates_with_zeroes");
	setup();
		test_4_create_double_creates_with_zeroes();
	tearDown();
	testEnded();
	testStarted("test_5_creates_string_stack");
	setup();
		test_5_creates_string_stack();
	tearDown();
	testEnded();
	testStarted("test_6_push_integer_element_in_stack");
	setup();
		test_6_push_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_7_push_float_element_in_stack");
	setup();
		test_7_push_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_8_push_double_element_in_stack");
	setup();
		test_8_push_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_9_push_character_element_in_stack");
	setup();
		test_9_push_character_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_10_push_string_element_in_stack");
	setup();
		test_10_push_string_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_11_pop_integer_element_from_stack");
	setup();
		test_11_pop_integer_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_12_pop_float_element_from_stack");
	setup();
		test_12_pop_float_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_13_pop_double_element_from_stack");
	setup();
		test_13_pop_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_14_pop_character_element_from_stack");
	setup();
		test_14_pop_character_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_15_pop_string_element_from_stack");
	setup();
		test_15_pop_string_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_16_gives_top_element_in_stack");
	setup();
		test_16_gives_top_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_fail");
	setup();
		test_fail();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
