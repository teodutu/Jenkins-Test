#include "unity.h"
#include "helper.h"

extern void setUp(void);
extern void tearDown(void);
extern void test1_merge_strings(void);

int main(void)
{
	UnityBegin("test/Test_helper.c");
	RUN_TEST(test1_merge_strings, 12);

	return (UnityEnd());
}