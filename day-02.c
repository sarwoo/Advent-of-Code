/**
 --- Day 2: I Was Told There Would Be No Math ---
 The elves are running low on wrapping paper, and so they need to submit an order for more. 
 They have a list of the dimensions (length l, width w, and height h) of each present, and only 
 want to order exactly as much as they need.
 
 Fortunately, every present is a box (a perfect right rectangular prism), which makes calculating 
 the required wrapping paper for each gift a little easier: find the surface area of the box, 
 which is 2*l*w + 2*w*h + 2*h*l. The elves also need a little extra paper for each present: the area 
 of the smallest side.

 For example:

    A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper 
    plus 6 square feet of slack, for a total of 58 square feet.
    A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper 
    plus 1 square foot of slack, for a total of 43 square feet.

All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?

--- Part Two ---

The elves are also running low on ribbon. Ribbon is all the same width, so they only have to worry about 
the length they need to order, which they would again like to be exact.

The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter 
of any one face. Each present also requires a bow made out of ribbon as well; the feet of ribbon required 
or the perfect bow is equal to the cubic feet of volume of the present. Don't ask how they tie the bow, 
though; they'll never tell.

For example:

    A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap the present plus 2*3*4 = 24 
    feet of ribbon for the bow, for a total of 34 feet.
    A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to wrap the present plus 1*1*10 = 10 
    feet of ribbon for the bow, for a total of 14 feet.

How many total feet of ribbon should they order?

*/

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define DATAFILE "input-day-02.txt"

// Create a Box struct
typedef struct Box
{
    int length;
    int width;
    int height;
} Box;


// find how many inputs there are in the file
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

// Read the input  file and store each input in the Box data array
int read_inputs(Box *data) {
    // Exit if cant open the file
    FILE *file = fopen(DATAFILE, "r");
    if (file == NULL) {
        return -1;
    }

    // create a working buffer  to hole each input
    char buffer[16];
    // fetch line and store in buffeer
    fgets(buffer, 16, file);
    // initialise pos counter
    int pos = 0;
    // Loop while not end of file
    while(!feof(file)){
        // create a pointer b pointing to data array at  position pos
        Box *b = data + pos;
        // read the buffer and store in box b
        sscanf(buffer, "%dx%dx%d", &b->length, &b->width, &b->height);
        // increment pos
        pos++;
        // read line and store in buffer
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

void part_2(Box *box, int size) {
    int i;
    int bow = 0;
    for (i=0; i < size; i++) {
        int volume =  box[i].length * box[i].width * box[i].height;
        int axis = box[i].length * 2 + box[i].width * 2;
        int axis_a = box[i].width * 2 + box[i].height * 2;
        int axis_b = box[i].length * 2 + box[i].height * 2;
        if (axis_a < axis) {
            axis = axis_a;
        }
        if (axis_b < axis) {
            axis = axis_b;
        }
        bow += axis + volume;
    }
    printf("Bow required is %d ft\n", bow);
}

int main(void) {
    printf("--- Day 2: I Was Told There Would Be No Math ---\n");

    // Find size of datafile
    int size = file_size(DATAFILE);
    // Create an array of Box's with correct size
    Box data[size];

    if (read_inputs(data)) {
        part_1(data, size);
        part_2(data, size);
    }
    return 0;
}