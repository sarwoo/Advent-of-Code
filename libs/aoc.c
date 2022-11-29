#include "aoc.h"
#include <stdio.h>
#include <stdlib.h>

int read_file_string(char *filename, char* string)
{
    // create a file pointer
    FILE *file;

    // open file and set to  pointer
    file = fopen(filename, "r");

    // if file open fails return null
    if (file == NULL) return 0;

    // Go to  end of the file
    fseek(file, 0, SEEK_END);
    // store number of chars in file
    int length = ftell(file);
    // printf("length: %d\n", length);
    // Go  to  beginning of file
    fseek(file, 0, SEEK_SET);

    // enlarge memoryto hold string data
    string = realloc(string, sizeof(char) * length + 1);

    char c;     // buffer to hold char as we read
    int i = 0;  // counter to iterate through string
    // Read each char from file until the end of file
    // Store each char in string
    // increment counter i
    while ((string[i] = fgetc(file)) != EOF)
        i++;
    
    // close connection to the file
    fclose(file);

    // Add null char at  end of string
    string[i] = '\0';
    
    return length;
}