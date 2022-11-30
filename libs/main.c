#include "aoc.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_STRING "data_string.txt"
#define DATA_LINES "data_lines.txt"

int main(int argc, const char * argv[])
{
    char *data = read_file_string(DATA_STRING);
    printf("string data: %s\n", data);
    printf("lines count: %d\n", file_count_lines(DATA_LINES));
    free(data);
    return 0;

}
