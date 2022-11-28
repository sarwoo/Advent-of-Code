/*
--- Day 6: Probably a Fire Hazard ---

Because your neighbors keep defeating you in the holiday house decorating contest year after year, you've decided to deploy one million lights in a 1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has mailed you instructions on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The instructions include whether to turn on, turn off, or toggle various inclusive ranges given as coordinate pairs. Each coordinate pair represents opposite corners of a rectangle, inclusive; a coordinate pair like 0,0 through 2,2 therefore refers to 9 lights in a 3x3 square. The lights all start turned off.

To defeat your neighbors this year, all you have to do is set up your lights by doing the instructions Santa sent you in order.

For example:

    turn on 0,0 through 999,999 would turn on (or leave on) every light.
    toggle 0,0 through 999,0 would toggle the first line of 1000 lights, turning off the ones that were on, and turning on the ones that were off.
    turn off 499,499 through 500,500 would turn off (or leave off) the middle four lights.

After following the instructions, how many lights are lit?

*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef enum command {ON, OFF, TOGGLE } Command;

void process(bool matrix[SIZE][SIZE], int x1, int y1, int x2, int y2, Command command);

int main(void)
{
    bool matrix[SIZE][SIZE] = {false};

    process(matrix, 0, 0, 9, 9,  ON);
    process(matrix, 0, 0, 9, 0,  TOGGLE);
    process(matrix, 4, 4, 5, 5,  OFF);

    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            printf("%i ", matrix[y][x]);
        }
        printf("\n");
    }

    return 0;
}


void process(bool matrix[SIZE][SIZE], int x1, int y1, int x2, int y2, Command command)
{
    for (int x = x1; x < x2+1; x++)
    {
        for (int y = y1; y < y2+1; y++)
        {
            switch (command)
            {
            case ON:
                matrix[x][y] = 1;
                break;
            case OFF:
                matrix[x][y] = 0;
                break;
            case TOGGLE:
                matrix[x][y] = !matrix[x][y];
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}