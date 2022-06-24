/*
Author:         Greenbae's Friends
Program:        Sum of Elements
Description:    Using pointer arithmetic to sum all of the
                elements in an integer array.
*/

#include <stdio.h>

int sum_array(int *a, int n);

int main()
{
    int i, n;

    printf("\nEnter the length of your array: ");
    scanf("%d", &n);

    int a[n]; //always put after getting value of n, assuming n is unknown

    printf("\nEnter your array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // printf("\nSum of the array elements is: %d", sum_array(a, n));
    //int sum = sum_array(a, n); //just like assigning to a number!
    printf("\nSum of the array elements is: %d", sum_array(a, n));

    return 0;
}

int sum_array(int *a, int n)
{
    int *p, sum = 0;

    /* regular version for array indexing:
    int i;
    for(i = 0; i < n; i++)
        sum += a[i]; //1, 2, 3 -> sum of 6
    */
    for(p = a; p < a + n; p++) //p = a[0]
        sum += *p; //*p -> a[p]; p -> p as if index

    return sum;
}