/*
Author:         Bean Counting Besties
Program:        array_compare.c
Description:    Go through each of the elements in an
                integer array using pointer arithmetic,
                count the number of different elements in
                between both arrays.
*/

#include<stdio.h>

void count_diff(int *a1, int *a2, int n, int *num_diff); //*a1 = a[]

int main()
{
    int n, i, diff = 0;
    int *d = &diff;

    printf("\nEnter the length of the number of beans counted: ");
    scanf("%d", &n);

    int a[n], b[n];
    
    printf("\nEnter the number of beans counted by worker #69: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]); //12,345 = [1, 2, 3, 4, 5]
    printf("\nEnter the number of beans counted by worker #70: ");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    count_diff(a, b, n, d); //function call 

    //handling the values of *d
    if(*d == 0) //no difference between the two arrays' elements
        printf("\nThe numbers are identical! HERE IS YOUR REWARD BESTIE!\n\n");
    else if(*d == 1)
        printf("\nThe numbers differ by 1 element.\nCOUNT AGAIN. I WANT EXACT BEANS. ");
    else if(*d > 1)
        printf("\nThe numbers differ by %d elements. \nBOO, NO FREE REWARDS FOR YOU.\n\n", *d);

    return 0;
}

void count_diff(int *a1, int *a2, int n, int *num_diff) //num_diff = d
{
    int *p, *q; //always use variables of same type to access elements
    //assume p is an int
    //for(p = 0; p < n; p++) regular array indexing
    //a1 = [1, 2, 3, 4, 5]
    //a2 = [1, 2, 3, 6, 6]
    for(p = a1, q = a2; p < a1 + n; p++, q++) //pointer arithmetic for arays
    {
        if(*p != *q) //p = i, *p = a[i]
            (*num_diff)++; //* is value, without * is the address
    }
}