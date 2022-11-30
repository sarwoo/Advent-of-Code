#include "aoc.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_STRING "data_string.txt"
#define DATA_LINES "data_lines.txt"

int main(int argc, const char * argv[])
{
    char *data = read_file_string(DATA_STRING);
    printf("string data: %s\n", data);

    int num_lines = file_count_lines(DATA_LINES);
    printf("lines count: %d\n", num_lines);

    char **array = read_file_lines(DATA_LINES, 100);
    for (int i = 0 ; i < num_lines; i++)
        printf("%s", array[i]);
    printf("\n");
    free(data);
    free(array);
    return 0;

}
