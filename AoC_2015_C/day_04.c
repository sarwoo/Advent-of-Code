/*
--- Day 4: The Ideal Stocking Stuffer ---

Santa needs help mining some AdventCoins (very similar to bitcoins) to use as 
gifts for all the economically forward-thinking little girls and boys.
ls
To do this, he needs to find MD5 hashes which, in hexadecimal, start with at 
least five zeroes. The input to the MD5 hash is some secret key (your puzzle 
input, given below) followed by a number in decimal. To mine AdventCoins, you 
must find Santa the lowest positive number (no leading zeroes: 1, 2, 3, ...) 
that produces such a hash.

For example:

    If your secret key is abcdef, the answer is 609043, because the MD5 hash 
    of abcdef609043 starts with five zeroes (000001dbbfa...), and it is the 
    lowest such number to do so.
    If your secret key is pqrstuv, the lowest number it combines with to make 
    an MD5 hash starting with five zeroes is 1048970; that is, the MD5 hash 
    of pqrstuv1048970 looks like 000006136ef....

--- Part Two ---

Now find one that starts with six zeroes.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "libs/md5.h"

void get_hash(char *secret, char *hash);

int main(void)
{
    bool no_match = true;
    int suffix = 0;
    char *secret = "abcdef";


    while (no_match)
    {    
        char test[50];
        sprintf(test,"%s%d", secret, suffix); 
        char hash[33] = "";
        get_hash(test, hash);
        if(hash[0] == '0' &&
           hash[1] == '0' &&
           hash[2] == '0' &&
           hash[3] == '0' &&
           hash[4] == '0' &&
           hash[5] == '0' )
        {
            printf("Part 2 = %s : %d\n", hash, suffix);
            no_match = false;
        }
        else
        {
        suffix++;

        }
    }

    return 0;
}

void get_hash(char *secret, char *hash)
{
    uint8_t *result;
    result = md5String(secret);
    for(unsigned int i = 0; i < 16; ++i){
        char bits[3];
		sprintf(bits,"%02x", result[i]); 
		strcat(hash, bits);
	}
}