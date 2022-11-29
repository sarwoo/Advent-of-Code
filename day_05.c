/*
--- Day 5: Doesn't He Have Intern-Elves For This? ---

Santa needs help figuring out which strings in his text file are naughty or nice.

A nice string is one with all of the following properties:

    It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
    It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
    It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.

For example:

    ugknbfddgicrmopn is nice because it has at least three vowels (u...i...o...), a double letter (...dd...), and none of the disallowed substrings.
    aaa is nice because it has at least three vowels and a double letter, even though the letters used by different rules overlap.
    jchzalrnumimnmhp is naughty because it has no double letter.
    haegwjzuvuyypxyu is naughty because it contains the string xy.
    dvszwmarrgswjxmb is naughty because it contains only one vowel.

How many strings are nice?

--- Part Two ---

Realizing the error of his ways, Santa has switched to a better model of determining whether a string is naughty or nice. None of the old rules apply, as they are all clearly ridiculous.

Now, a nice string is one with all of the following properties:

    It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
    It contains at least one letter which repeats with exactly one letter between them, like xyx, abcdefeghi (efe), or even aaa.

For example:

    qjhvhtzxzqqjkmpb is nice because is has a pair that appears twice (qj) and a letter that repeats with exactly one letter between them (zxz).
    xxyxx is nice because it has a pair that appears twice and a letter that repeats with one between, even though the letters used by each rule overlap.
    uurcxstgmygtbstg is naughty because it has a pair (tg) but no repeat with a single letter between them.
    ieodomkazucvgmuy is naughty because it has a repeating letter with one between (odo), but no pair that appears twice.

How many strings are nice under these new rules?


*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_FILE "input_day_05.txt"

#define MAX_LINES 1000
#define MAX_LEN   18 // 16 alph chars + \n + \0

void part_1(char data[][MAX_LEN]);
void part_2(char data[][MAX_LEN]);
int read_file(char data[][MAX_LEN]);
void substring(char *orig, char *substr, int start, int length);

int main(void)
{
    printf("--- Day 5: Doesn't He Have Intern-Elves For This? ---\n");
    char data[MAX_LINES][MAX_LEN];
    read_file(data);
    part_1(data);
    part_2(data);
    return 0;
}



void part_1(char data[][MAX_LEN])
{
    int sub_size = 3;
    char sub[sub_size];
    int nice_words = 0;
    for (int i = 0; i < MAX_LINES; i++)
    {
        char vowel_count = 0;
        char vowels[] = "aeiou";
        int has_double = 0;
        int banned_pair = 0;

        for (int k = 0; k < MAX_LEN;k++)
        {
            for (int v = 0; v < 5; v++)
            {
                if (vowels[v] == data[i][k])
                {
                    vowel_count++;
                }
            }
        }

        for (int j = 0; j < MAX_LEN - sub_size; j++)
        {
            substring(data[i], sub, j, 2);

            if (sub[0] == sub[1])
                has_double = 1;

            if (
                (sub[0] == 'a' && sub[1] == 'b') ||
                (sub[0] == 'c' && sub[1] == 'd') ||
                (sub[0] == 'p' && sub[1] == 'q') ||
                (sub[0] == 'x' && sub[1] == 'y') 
                )
                banned_pair = 1;
                
        }
        if ((banned_pair == 0) && (vowel_count > 2) && (has_double))
            nice_words++;

    }
    printf("Part 1: Number of nice strings: %d\n", nice_words);
}



void part_2(char data[][MAX_LEN])
{
    int count_strings = 0;

    int length = strlen(data[0]);

    // for (int i = 0; i < 10; i++)
    for (int i = 0; i < MAX_LINES; i++)
    {
        bool has_pair = false;
        bool has_repeat = false;
        // printf("%s...\n", data[i]);
        for (int j = 0; j < length - 2; j++)
        {
            if (j < length - 3)
            {
                for (int k = j + 2; k < (length - 1); k++)
                {
                    if ((data[i][j] == data[i][k]) && (data[i][j+1] == data[i][k+1]))
                    {
                        has_pair = true;
                        
                        break;
                    }
                }
                
            }
            if (data[i][j] == data[i][j + 2])
                has_repeat = true;
        }
        // printf("pair: %s\n", has_repeat ? "true" : "false");
        // printf("repeat: %s\n", has_repeat ? "true" : "false");

        if (has_repeat && has_pair)
            count_strings++;
    }
    printf("Part 2: Number of nice strings: %d\n", count_strings);
}



int read_file(char data[][MAX_LEN])
{
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    if (file == NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    int line = 0;
    while (!feof(file) && !ferror(file))
         if (fgets(data[line], MAX_LEN, file) != NULL)
         {
            data[line][16] = '\0';
            line++;
         }
    fclose(file);
    return line;
}

void substring(char *orig, char *substr, int start, int length){
    int idx = 0;
    for (int i = start; i < start + length; i++)
    {
        substr[idx] = orig[i];
        idx++;
    }
    substr[length] = '\0';
}