#include "aoc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // read_file_string(char *filename, char* string)
    char *string = malloc(sizeof(char));
    // char *string = read_init();
    int length = read_file_string("string_data.txt", string);
    if (length)
        printf("%s [%d]\n", string, length);
    
    
    // printf("a:%p\n", string);
    // read_close(string);
    free(string);
    // printf("b:%p\n", string);
    return 0;
}
