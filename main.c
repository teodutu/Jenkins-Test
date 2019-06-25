#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* merge_strings(char* str1, char* str2, int type) {
    char* new_str = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char));

    if (type) {
        strcpy(new_str, str1);
        strcat(new_str, str2);
    } else {
        strcpy(new_str, str2);
        strcat(new_str, str1);
    }

    return new_str;
}

int main(int argc, char** argv) {
    int type = atoi(argv[3]);
    char* res = merge_strings(argv[1], argv[2], type);

    printf("%s\n", res);
    free(res);

    return 0;
}