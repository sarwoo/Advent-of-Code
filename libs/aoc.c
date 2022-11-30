//
//  AoC.c
//  AoC-Utils
//
//  Created by Sarah Wood on 29/11/2022.
//

#include "aoc.h"

int file_count_lines(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) return 0;
    int current_line = 1;
    char c;
    do
    {
        c = fgetc(file);
        if (c ==  '\n') current_line++;
    } while (c != EOF);
    fclose(file);
    return current_line;
}

char *read_file_string(char *filename)
{
    // create a file pointer
    FILE *file;

    // open file and set to pointer
    file = fopen(filename, "r");

    // if file open fails return null
    if (file == NULL) return 0;

    // Go to  end of the file
    fseek(file, 0, SEEK_END);
    // store number of chars in file
    long length = ftell(file);
    // printf("length: %d\n", length);
    // Go  to  beginning of file
    fseek(file, 0, SEEK_SET);

    // create  memory to hold string data
    char *string = calloc(length + 1, sizeof(char) );

    int i = 0;  // counter to iterate through string
    
    // Read each char from file un til the end of file
    // Store each char in string
    // increment counter i
    while ((string[i] = fgetc(file)) != EOF)
        i++;
    
    // close connection to the file
    fclose(file);

    // Add null char at  end of string
    string[i] = '\0';
    
    return string;
}
