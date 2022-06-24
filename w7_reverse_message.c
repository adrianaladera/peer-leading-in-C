/*
Author:         Greenbae's Friends
Program:        Reverse Message
Description:    Using pointer arithmetic to print the 
                reverse order of characters entered by the user.
*/

#include <stdio.h>

#define MESSAGE_LEN 100

int main()
{
    char *p;
    char message[MESSAGE_LEN];
    int count = 0;

    printf("\nEnter a message: ");
    for(p = message; p < message + MESSAGE_LEN; p++)
    {
        *p = getchar();
        count++; //counting chars entered into 'message' array
        if(*p == '\n') //as long as user does not press 'enter'
            break;
    }

    // null character: '\0'
    printf("Reverse is: "); //[e, g, g, .....] 
    for(p = message + count - 1; p >= message; p--) //initialization points to last element in array
        putchar(*p); //same as printing a character with a printf()
    putchar('\n');

    return 0;
}