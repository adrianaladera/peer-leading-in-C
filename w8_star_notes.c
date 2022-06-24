/*
Author:         FBI Peepoo
Program:        Star Notes
Description:    Use pointer arithmetic to determine whether
                or not the input given from the user has two *.
                If so, print the output between them.
*/

#include <stdio.h>

#define MAX_LEN 1000 //max chars for input

int read_line(char *str, int n);
int search(char *s1, char *s2); //copy input from s1 to s2 that's encased by the two *

int main()
{
    int star_flag;
    char egg[MAX_LEN + 1]; //+1 for '\0'

    printf("\nWhat do we have to decode in the text, sargeant: ");
    int N = read_line(egg, MAX_LEN);

    char egg_out[N + 1];

    //star_flag determines whether or not there are two * found in the input
    star_flag = search(egg, egg_out);

    if(star_flag == 1) //two stars are found!
        printf("\nOutput: %s\n", egg_out);
    else
        printf("\nNothing to decode! Two * characters were not found :(\n\n");

    return 0;
}

int read_line(char *str, int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i < n)
        {
            *str++ = ch; //str[i] = ch;
            i++; //counts actual number of characters read by command line
        }
    }

    *str = '\0'; //always terminate with this!
    return i;
}

int search(char *s1, char *s2)
{ // i am *dissolving* into small particles
    int num_stars = 0; //keep track of how many * are found
    char *star1, *star2; //point to locations of 1st and 2nd stars

    //check all characters in input for two stars
    while(*s1 != '\0' && num_stars < 2) //s1[] != '\0'
    {
        if(*s1 == '*')
        {
            num_stars++;

            if(num_stars == 1)
                star1 = s1; //set pointer to address of first star
            if(num_stars == 2)
                star2 = s1; //if it exists, set pointer to address of 2nd star
        }
        s1++;
    }

    //case handling, add output to s2
    if(num_stars == 2)
    {
        //loops through only chars in between two *
        for(star1++; star1 < star2; star1++)
        {
            *s2++ = *star1; //storing chars between * into s2
            /*
            *s2 = *star1; [d, i, s, ]
            s2++;
            */
        }
        *s2 = '\0';
        return 1;
    }

    else
    {
        *s2 = '\0';
        return 0;
    }
    

}