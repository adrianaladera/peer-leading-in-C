/* Author:      Kermit Gang
   Program:     To Lower Case
   Description: Converting upper case characters into
                lower case characters. */

#include <stdio.h>

int main()
{
    printf("\nTYPE SOMETHING MATE: \n");
    char ch;

    do{
        ch = getchar();
        if(ch >= 65 && ch <= 90) //if characters are upper case!
            ch += 32; //converts to lower case using ASCII values!
        
        //lower to upper : 97 - 122, ch -= 32;

        printf("%c", ch);    

    }while(ch != '\n');//while user doesnt press 'enter'

    printf("\nSHhhhh why are you yelling?\n" 
            "\nWe're in a library :(");

    return 0;
}