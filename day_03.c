/*
--- Day 3: Perfectly Spherical Houses in a Vacuum ---

Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

    > delivers presents to 2 houses: one at the starting location, and one to the east.
    ^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
    ^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.

--- Part Two ---

The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

    ^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
    ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
    ^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUTFILE "input_day_03.txt"

typedef struct 
{
    int x;
    int y;
} Point;

char *read_file(char *filename);
Point parse_char(char c);
Point move(Point current_loc, Point direction);
bool has_visited(Point *houses, Point house, int num);
void part_1(char *data);
void part_2(char *data);

int main(void)
{
    // Read contents from input file
    char *file_contents = read_file(INPUTFILE);
    if (file_contents == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }

    printf("--- Day 3: Perfectly Spherical Houses in a Vacuum ---\n");
    part_1(file_contents);
    part_2(file_contents);

    free(file_contents);

    return 0;
}

char *read_file(char *filename)
{
    FILE *file;

    file = fopen(filename, "r");

    if (file == NULL) return NULL;

    // Go to  end of the file
    fseek(file, 0, SEEK_END);
    // store number of chars in file
    int length = ftell(file);
    // printf("length: %d\n", length);
    // Go  to  beginning of file
    fseek(file, 0, SEEK_SET);

    // Allocate enough memory for the file + 1 for the null char
    char *string = malloc(sizeof(char) * (length + 1));

    char c;     // buffer to hold char as we read
    int i = 0;  // counter to iterate through string
    // Read each char from file until the end of file
    // Store each char in string
    // increment counter i
    while ((c = fgetc(file)) != EOF)
    {
        string[i] = c;
        i++;
    }
    // Add null char at  end of string
    string[i] = '\0';

    // close connection to the file
    fclose(file);

    return string;
}

Point parse_char(char c) 
{
    Point p = {0};
    switch (c)
    {
        case '<':
            p.x = -1;
            break;
        case '>':
            p.x = 1;
            break;
        case '^':
            p.y = 1;
            break;
        case 'v':
            p.y = -1;
            break;
    }
    return p;
}

Point move(Point current_loc, Point direction)
{
    current_loc.x += direction.x;
    current_loc.y += direction.y;
    return current_loc;
}

bool has_visited(Point *houses, Point house, int num)
{
    for (int i = 0; i < num; i++)
    {
        if ((houses[i].x == house.x) & (houses[i].y == house.y))
        {
            // printf("Visited (%d, %d)\n", house.x, house.y);
            return true;
        }
    }
    // printf("Not visited (%d, %d)\n", house.x, house.y);
    return false;
}

void part_1(char *data)
{
    printf("\nPart 1...\n");
    // Create a Point to hold current location
    Point location = {0, 0};

    // Create a block of dynamic memory to store an array of points
    int length = 8;
    Point *array;
    array = malloc(sizeof(Point) * length);

    // Add starting location
    array[0] = location;
    // Create variable to keep track of number of unique houses visited
    int num_houses = 1; 

    int cursor = 0;
    while (data[cursor] != '\0')
    {
        // Make sure there is enough memory to hold new location
        if (num_houses == length)
        {
            length += 8;
            array = realloc(array, sizeof(Point) * length);
        }

        Point direction = parse_char(data[cursor]);
        location = move(location, direction);

        // Check if location is member of array
        if (!has_visited(array, location, cursor))
        {
            array[num_houses] = location;
            num_houses++;
        }

        cursor++;
    }

    // Debug: Prints house locations in array
    // for (int i = 0; i < num_houses; i++)
    //     printf("array[%d]: (%d, %d)\n", i, array[i].x, array[i].y);

    printf("Directions processed : %d \n", cursor);
    printf("Unique houses visited: %d \n", num_houses);

    free(array);

}

void part_2(char *data)
{
    printf("\nPart 2...(NOT)\n");
    // Create a Point to hold current location
    Point santa_loc = {0, 0};
    Point robo_loc = {0, 0};

    // Create a block of dynamic memory to store an array of points
    int length = 8;
    Point *array;
    array = malloc(sizeof(Point) * length);

    // Add starting location
    array[0] = santa_loc;
    // Create variable to keep track of number of unique houses visited
    int num_houses = 1; 

    int cursor = 0;
    while (data[cursor] != '\0')
    {
        // Make sure there is enough memory to hold new location
        if (num_houses == length)
        {
            length += 8;
            array = realloc(array, sizeof(Point) * length);
        }

        Point direction = parse_char(data[cursor]);
        Point location;

        if (cursor % 2)
            {
                santa_loc = move(santa_loc, direction);
                location = santa_loc;
               
            }
        else
            {
                robo_loc = move(robo_loc, direction);
                location = robo_loc;
            }

        // Check if location is member of array
        if (!has_visited(array, location, cursor))
        {
            array[num_houses] = location;
            num_houses++;
        }

        cursor++;
    }

    // Debug: Prints house locations in array
    // for (int i = 0; i < num_houses; i++)
    //     printf("array[%d]: (%d, %d)\n", i, array[i].x, array[i].y);

    printf("Directions processed : %d \n", cursor);
    printf("Unique houses visited: %d \n\n", num_houses);

    free(array);

}