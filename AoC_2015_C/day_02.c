/**
* --- Day 2: I Was Told There Would Be No Math ---
* The elves are running low on wrapping paper, and so they need to submit an order for more. 
* They have a list of the dimensions (length l, width w, and height h) of each present, and only 
* want to order exactly as much as they need.
* 
* Fortunately, every present is a box (a perfect right rectangular prism), which makes calculating 
* the required wrapping paper for each gift a little easier: find the surface area of the box, 
* which is 2*l*w + 2*w*h + 2*h*l. The elves also need a little extra paper for each present: the area 
* of the smallest side.
*
* For example:
*
*    A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper 
*    plus 6 square feet of slack, for a total of 58 square feet.
*    A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper 
*    plus 1 square foot of slack, for a total of 43 square feet.
*
* All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE "input_day_02.txt"

typedef struct Box
{
    int length;
    int width;
    int height;
} Box;


int file_size(char *filename) {
    FILE *fh;
    fh = fopen(filename, "r");

    if (fh == NULL) {
        printf("Error opening file");
        return 0;
    }

    int pos = 0;
    char c;
    do {
        c = fgetc(fh);
        if (c == '\n') {
            pos++;
        }
    } while (c != EOF); 

    fclose(fh);
    return pos;
}


int read_inputs(Box *data) {
    FILE *file = fopen(DATAFILE, "r");
    if (file == NULL) {
        return -1;
    }

    char buffer[16];
    fgets(buffer, 16, file);
    int pos = 0;
    while(!feof(file)){
        Box *b = data + pos;
        sscanf(buffer, "%dx%dx%d", &b->length, &b->width, &b->height);
        pos++;
        fgets(buffer, 16, file);
    }
    return pos;
}


void part_1(Box *box, int size) {
    int i;
    int total_area = 0;
    for (i = 0; i < size; i++) {
        int top = box[i].length*box[i].width;
        int side = box[i].width*box[i].height;
        int front = box[i].length*box[i].height;
        int surface_area =  2*top + 2*side + 2*front;
        int smallest_area = top;
        if (side < smallest_area) {
            smallest_area = side;
        }
        if (front < smallest_area) {
            smallest_area = front;
        }

        total_area += surface_area + smallest_area;
        
    }
    printf("Wrapping paper required is %d sq ft\n", total_area);
}

int main(void) {
    printf("--- Day 2: I Was Told There Would Be No Math ---\n");

    // Find size of datafile
    int size = file_size(DATAFILE);
    Box data[size];

    if (read_inputs(data)) {
        part_1(data, size);
    }
    return 0;
}