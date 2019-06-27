#include "helper.h"

#include <stdio.h>

int is_palindrome(char* str)
{
    char* s = str + strlen(str) - 1;

    while (*str == *s && str++ < s--);

    return str >= s;
}

char* merge_strings(char* str1, char* str2, int type)
{
    char* new_str = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char));

    if (!is_palindrome(str1))
    {
       *str1 = toupper(str1[0]);
    }
    if (!is_palindrome(str2))
    {
        *str2 = toupper(*str2);
    }

    if (type)
    {
        strcpy(new_str, str1);
        strcat(new_str, str2);
    } else
    {
        strcpy(new_str, str2);
        strcat(new_str, str1);
    }

    return new_str;
}