/*
--- Day 1: Not Quite Lisp ---

Santa was hoping for a white Christmas, but his weather machine's "snow" function is powered by stars, 
and he's fresh out! To save Christmas, he needs you to collect fifty stars by December 25th.

Collect stars by helping Santa solve puzzles. Two puzzles will be made available on each day in the Advent 
calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

Here's an easy 
puzzle to warm you up.

Santa is trying to deliver presents in a large apartment building, but he can't find the right floor - the 
directions he got are a little confusing. He starts on the ground floor (floor 0) and then follows the instructions 
one character at a time.

An opening parenthesis, (, means he should go up one floor, and a closing parenthesis, ), means he should go down one floor.

The apartment building is very tall, and the basement is very deep; he will never find the top or bottom floors.

For example:

    (()) and ()() both result in floor 0.
    ((( and (()(()( both result in floor 3.
    ))((((( also results in floor 3.
    ()) and ))( both result in floor -1 (the first basement level).
    ))) and )())()) both result in floor -3.

To what floor do the instructions take Santa?

--- Part Two ---

Now, given the same instructions, find the position of the first character that causes him to enter the 
basement (floor -1). The first character in the instructions has position 1, the second character has position 2, and so on.

For example:

    ) causes him to enter the basement at character position 1.
    ()()) causes him to enter the basement at character position 5.

What is the position of the character that causes Santa to first enter the basement?

*/

#include <stdio.h>

#define DATAFILE "input_day_01.txt"

int file_size(char *filename) {
    FILE *fh;
    fh = fopen(filename, "r");
    if (fh != NULL) {
        int pos = 0;
        while (fgetc(fh) != EOF) {
            pos++;
        }
        fclose(fh);
        return pos;
    } else {
        printf("Error opening file");
        return 0;
    }
}

int read_input(char *filename, char *data) {
    FILE *fh;
    fh = fopen(filename, "r");
    if (fh == NULL) {
        printf("Error opening file");
        return 0;
    }
    int pos = 0;
    char c;
    while ((c = fgetc(fh)) != EOF) {
        data[pos] = c;
        pos++;
    }
    fclose(fh);
    return 1;
}

void part_1(char *data, int size) {
    int level = 0;
    for (int i = 0; i < size; i++) {
        level += (data[i] == '(') ? 1 : -1;
        // long form
        // if (data[i] == '(') {
        //     level++;
        // } else {
        //     level--;
        // }
    }
    printf("Santa finished on level %i\n", level);
}

void part_2(char *data, int size) {
    int level = 0;
    int count = 1;
    for (int i = 0; i < size; i++) {
        level += (data[i] == '(') ? 1 : -1;
        if (level == -1) {
            break;
        } else {
            count++;
        }
    }

    printf("Santa reached the basement on move %i\n", count);
}

int main(void) {
    printf("--- Day 1: Not Quite Lisp ---\n");

    // Find size of datafile
    int size = file_size(DATAFILE);
    // printf("Size of data: %i\n", size);

    // initialise array to size of data
    char data[size];

    // read populate data array from data file
    // and run challanges using the data
    if (read_input(DATAFILE, data)) {
        part_1(data, size);
        part_2(data, size);
    }
    return 0;
}