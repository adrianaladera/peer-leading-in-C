/*
Author:         The Egg Gang Besties
Program:        String Comparison
Description:    To write a program that compares two
                strings using the C string library.
*/

#include <stdio.h>

#define STR_LEN 69
int read_line(char *str, int n);

int main()
{
    // \0
    char s1[STR_LEN + 1], s2[STR_LEN + 1];
    printf("\nEnter the first person's name: ");
    read_line(s1, STR_LEN);
    printf("\nEnter the second person's name: ");
    read_line(s2, STR_LEN);

    //comparing the two strings
    if(strcmp(s1, s2) == 0) //names are the exact same
        printf("\nDeez names are the same length! ");
    else if(strlen(s1) > strlen(s2))
        printf("\nThe first name is longer bruh");
    else if(strlen(s1) < strlen(s2))
        printf("\nThe second name is longer bruh");
    else
        printf("\nEqual lengths but different characters\n");

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