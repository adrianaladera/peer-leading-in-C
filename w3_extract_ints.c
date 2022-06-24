/* Author:      Kermit Gang
   Program:     Extract Integers
   Description: Drawing integers from the command line
                given input from the user. */

#include <stdio.h>

int main()
{
    char ch; //empty string character

    printf("\nThis program extracts numbers from the text.\nType a message here: ");
    //scanf("%c", ch);
    //ch = getchar();

    printf("\nIntegers from the text: ");

    while(ch != '\n') //can use any loop you want!
    {
        ch = getchar(); //getchar does account for spaces
        if(ch >= '0' && ch <= '9') //checking to see if char is an int
        //remember to put single quotation marks
            printf("%c ", ch);
    }//while(ch != '\n'); //get text until the user presses 'enter'
    printf("\n\n");

    return 0;
}