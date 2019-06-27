#include "unity.h"
#include "helper.h"

extern void setUp(void);
extern void tearDown(void);
extern void test_merge_stringsNoPalindromes(void);
extern void test_merge_stringsPalindromes(void);
extern void test_is_palindromeTruePalindrome(void);
extern void test_is_palindromeFalsePalindrome(void);

int main(int argc, char** argv)
{
    UnityBegin("test/Test_helper.c");

    if(argc != 2)
    {
        printf("Usage: ./test <function_to_test>.\n");
    } else if (!strcmp(argv[1], "merge_strings"))
    {
        /* Run the tests for merge_strings */
        RUN_TEST(test_merge_stringsNoPalindromes, 12);
        RUN_TEST(test_merge_stringsPalindromes, 31);
    } else if (!strcmp(argv[1], "is_palindrome"))
    {
        /* Run the tests for is_palindrome */
        RUN_TEST(test_is_palindromeTruePalindrome, 46);
        RUN_TEST(test_is_palindromeFalsePalindrome, 54);
    } else
    {
        printf("Undefined function\n");
    }
    

    return (UnityEnd());
}