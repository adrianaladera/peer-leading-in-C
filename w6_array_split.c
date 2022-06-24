/*
Name:           Egg Gang Besties
Program:        Array Splitting for Greenbae <3
Description:    Write a program that can split an array into
                two smaller arrays at the index in which the array
                element is a 0.
*/

#include <stdio.h>

int find_zero(int *a, int n);

int main()
{
    int n1, n2, zero_location;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n1);

    //delacre split arrays
    int a1[n1];
    int a2[n1];

    printf("\nEnter the elements of the array: ");
    int i;
    for(i = 0; i < n1; i++)
        scanf("%d", &a1[i]);

    zero_location = find_zero(a1, n1);    

    if(zero_location >= 0) 
    //checking to see if value 0 is in the array
    {
        n2 = n1 - zero_location - 1;
        n1 = zero_location;

        for(i = 0; i < n2; i++) //assigning elements to second array
            a2[i] = a1[zero_location + i + 1];
            // 1 2 3 0 6 9
            // 6 9

    //printA results
    printf("Array 1: ");
    for(i = 0; i < n1; i++)
        printf("%d ", a1[i]); //1 2 3

    printf("Array 2: ");
    for(i = 0; i < n2; i++) // 6 9
        printf("%d ", a2[i]);

    }
    else    
        printf("\n No zero found in the array!\n");


    return 0;
}

// *a is an array pointer
int find_zero(int *a, int n)
{
    // *a = 1 2 3 0 6 9
    int *p; //i
    //for(i = 0; i < n; i++), reg for loop
    for(p = a; *p != 0 && p < a + n; p++); //p = a[0]; p < a[0] + n    
    /*
    for(p = a; p < a + n; p++)
    {
        if(*p == 0) // a[p] == 0
            break;
    } 
    */

    if(*p == 0) //if 0 is found
        return p - a; //distance from beginning of array
    
    else
        return -1;

}