#include <stdio.h>

#define DATAFILE "data/day01.txt"

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
    printf("Santa is on level %i  [280]\n", level);
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
    printf("Santa reached basement on move %i  [1797]\n", count);
}

int main(void) {
    printf("Advent of code - 2015 - Day 1\n");

    // Find size of datafile
    int size = file_size(DATAFILE);
    printf("Size of data: %i\n", size);

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