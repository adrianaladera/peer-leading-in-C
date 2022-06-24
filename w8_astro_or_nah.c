/*
Author:         The Egg Gang Besties
Program:        Astro or Nah
Description:    Write a program that can verify whether
                a given string is in an array
                of character arrays.
*/

#include <stdio.h>
#include <string.h>
 
#define NUM_ASS 12 //max number of ass bodies aka strings
#define INPUT_LEN 100 //max characters

int read_line(char *str, int n);

int main()
{
    //2D array/ pointer version
    char *astro[] = {"Mercury", "Venus", "Earth", "Mars", 
                    "Jupiter", "Saturn", "Uranus", "Neptune",
                    "Pluto", "Sirius", "Betelgeuse", "Rigel"};
    
    char input[INPUT_LEN + 1];

    int j;

    printf("\nEnter an ass-tronomical body: ");
    read_line(input, INPUT_LEN);

    for(j = 0; j < NUM_ASS; j++)
    {
        if(strcmp(input, astro[j]) == 0) //name is in the list
        {
            printf("%s is an ass-tronomical body at index %d\n", input, j);
            break;
        }

        else if(j == NUM_ASS - 1) //last index in 2D array
        {
            printf("\nSorry mate, but %s is not an ass-tronomical body", input);
            break;
        }
    }

    return 0;
}


int read_line(char *str, int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i < n) //assuming user input is always less than max length, n
        {
            *str++ = ch; //[C, H, i, C, K]
            i++; //how many characters the user actually enters
        }
    }

    *str = '\0';
    return i;
}