#include "unity.h"
#include "helper.h"

void setUP(void) 
{
}

void tearDown(void)
{
}

void test1_merge_strings(void)
{
	char* str1 = malloc(10);
	strcpy(str1, "gigel");
	
	char* str2 = malloc(10);
	strcpy(str2, "gigi");
	
	char* str3 = malloc(10);
	strcpy(str3, "dorel");

	TEST_ASSERT_EQUAL_STRING("GigelGigi", merge_strings(str1, str2, 1));
	TEST_ASSERT_EQUAL_STRING("DorelGigel", merge_strings(str1, str3, 0));

	free(str1);
	free(str2);
	free(str3);
}