#include "unity.h"
#include "helper.h"

void setUP(void) 
{
}

void tearDown(void)
{
}

void test_merge_stringsNoPalindromes(void)
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

void test_merge_stringsPalindromes(void)
{
	char* str1 = malloc(10);
	strcpy(str1, "abcba");
	
	char* str2 = malloc(10);
	strcpy(str2, "gigi");

	TEST_ASSERT_EQUAL_STRING("abcbaGigi", merge_strings(str1, str2, 1));
	TEST_ASSERT_EQUAL_STRING("Gigiabcba", merge_strings(str1, str2, 0));

	free(str1);
	free(str2);
}

void test_is_palindromeTruePalindrome(void)
{
	TEST_ASSERT_EQUAL_INT(1, is_palindrome(""));
	TEST_ASSERT_EQUAL_INT(1, is_palindrome("a"));
	TEST_ASSERT_EQUAL_INT(1, is_palindrome("aa"));
	TEST_ASSERT_EQUAL_INT(1, is_palindrome("aba"));
}

void test_is_palindromeFalsePalindrome(void)
{
	TEST_ASSERT_EQUAL_INT(0, is_palindrome("palindrome"));
	TEST_ASSERT_EQUAL_INT(0, is_palindrome("false"));
	TEST_ASSERT_EQUAL_INT(0, is_palindrome("xy"));
}
