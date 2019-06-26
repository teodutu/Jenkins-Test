#include <stdio.h>

#include "helper.h"

int main(int argc, char** argv)
{
    int type = atoi(argv[3]);
    char* res = merge_strings(argv[1], argv[2], type);

    printf("%s\n", res);
    free(res);

    return 0;
}