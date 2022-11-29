#include "aoc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // read_file_string(char *filename, char* string)
    char *string = malloc(sizeof(char));
    int length = read_file_string("string_data.txt", string);
    if (length)
        printf("%s [%d]\n", string, length);
    free(string);

    return 0;
}
