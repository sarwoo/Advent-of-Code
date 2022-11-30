//
//  AoC.h
//  AoC-Utils
//
//  Created by Sarah Wood on 29/11/2022.
//

#ifndef AoC_h
#define AoC_h

#include <stdio.h>
#include <stdlib.h>

// Counts how many lines are in a file and returns as int
// Returns 1 is file empty
// returns 0 if file error
int file_count_lines(char *filename);

// Function to read a string from a file into dynamic memory
// Returns the string length.
// It takes a char pointer with name of the file to be read
// and a pointer to store the string
//
// Suggested usage:
// char *string = malloc(sizeof(char));
// char *read_init()
// read_file_string("filename.txt", string);
// do something with the string...
// free(string)
char *read_file_string(char *filename);

#endif /* AoC_h */
