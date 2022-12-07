/*
--- Day 6: Probably a Fire Hazard ---

Because your neighbors keep defeating you in the holiday house decorating contest year after 
year, you've decided to deploy one million lights in a 1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has mailed you instructions 
on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the lights at each corner 
are at 0,0, 0,999, 999,999, and 999,0. The instructions include whether to turn on, turn off, 
or toggle various inclusive ranges given as coordinate pairs. Each coordinate pair represents 
opposite corners of a rectangle, inclusive; a coordinate pair like 0,0 through 2,2 therefore 
refers to 9 lights in a 3x3 square. The lights all start turned off.

To defeat your neighbors this year, all you have to do is set up your lights by doing the
instructions Santa sent you in order.

For example:

    turn on 0,0 through 999,999 would turn on (or leave on) every light.
    toggle 0,0 through 999,0 would toggle the first line of 1000 lights, turning off the ones
    that were on, and turning on the ones that were off.
    turn off 499,499 through 500,500 would turn off (or leave off) the middle four lights.

After following the instructions, how many lights are lit?

*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "aoc-util.h"

#define SIZE 1000
// #define DATA_FILE "data.txt"
#define DATA_FILE "input-day-06.txt"

typedef enum command {ON, OFF, TOGGLE } Command;

typedef struct 
{
    Command command;
    int x1;
    int y1;
    int x2;   
    int y2;
} Instruction;

void process(bool matrix[SIZE][SIZE], Instruction led);
int count_leds_on(bool matrix[SIZE][SIZE]);
void part_1(char **data, int count, bool matrix[SIZE][SIZE]);
void part_2(char **data, int count);

int main(void)
{
    printf("--- Day 6: Probably a Fire Hazard ---\n");

	char **data;
	int count;

	data = load_file_lines(DATA_FILE, 101, &count);

	if (data == NULL)
	{
		printf("error: %s\n", strerror(count));
		return 1;
	}

    bool matrix[SIZE][SIZE] = {false};

	part_1(data, count, matrix);
	part_2(data, count);
	
	free_string_array(data, count);

	return 0;
}

void process(bool matrix[SIZE][SIZE], Instruction led)
{
    for (int x = led.x1; x <= led.x2; x++)
    {
        for (int y = led.y1; y <= led.y2; y++)
        {
            switch (led.command)
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
    }
}

int count_leds_on(bool matrix[SIZE][SIZE])
{
    int count = 0;
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if (matrix[y][x])
                count++;
        }
    }
    return count;
}

bool starts_with(char *start, char* string)
{
    int start_length = strlen(start);
    int string_length = strlen(string);
    if (strlen(start) > strlen(string)) return false;
    for (int i = 0; i < start_length; i++)
        if (string[i] != start[i]) return false;
    return true;
}

void part_1(char **data, int count, bool matrix[SIZE][SIZE])
{
    printf("Part 1... \n");	

    for (int i = 0; i < count; i++)
    {
        if (starts_with("turn", data[i]))
            data[i][4] = '-';

        char* inst;
        int x1, y1, x2, y2;

        sscanf(data[i], "%s %i,%i through %i,%i", inst, &x1, &y1, &x2, &y2);

        Command cmd;
        if (starts_with(inst, "turn-on"))
            cmd = ON;
        else if (starts_with(inst, "turn-off"))
            cmd = OFF;
        else 
            cmd = TOGGLE;
        Instruction instruction = {cmd, x1, y1, x2, y2};

        process(matrix, instruction);
    }

    printf("Number of lights on: %d\n\n", count_leds_on(matrix));
}


void part_2(char **data, int count)
{       

     int **leds = malloc(sizeof(int *) * SIZE);
     for (int i = 0; i < SIZE; i++)
        leds[i] = calloc(SIZE, sizeof(int));

	printf("Part 2... \n");

    // process instructions
    for (int i = 0; i < count; i++)
    {
        if (starts_with("turn", data[i]))
            data[i][4] = '-';

        char* inst;
        int x1, y1, x2, y2;

        sscanf(data[i], "%s %i,%i through %i,%i", inst, &x1, &y1, &x2, &y2);

        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
            if (starts_with(inst, "turn-on"))
                leds[x][y] += 1;
            else if (starts_with(inst, "turn-off"))
                {
                    leds[x][y] -= 1;
                    if (leds[x][y] < 0) leds[x][y] = 0;
                }
            else 
                leds[x][y] += 2;
            }
        }
        
    }

    unsigned long total = 0;
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            total +=  leds[y][x];
        }
    }

    printf("Number of lights on: %lu\n\n", total);

    for (int i = 0; i < SIZE; i++)
        free(leds[i]);
    free(leds);
}
