#ifndef __AOC__
#define __AOC__

char *read_init();

void read_close(char *p);

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
int read_file_string(char *filename, char* string);

#endif