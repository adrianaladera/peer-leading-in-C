/* Author:          FBI Squad
   Program:         Search and Delete Database
   Description:     Write two functions that can search and delete
                    selected values from the array.
*/

#include <stdio.h>

//function declarations
int search(int a[], int n, int value); //() is a parameter to be accepted
int delete(int a[], int n, int value);

int main()
{
    int n, i, value = 0, selection;

    //a = [ , , , , , ]
    printf("\nEnter the length of the array: ");
    scanf("%d", &n); //n is length of array

    int a[n]; //declare array var after user input

    printf("\nEnter the elements of the array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    do {
        printf("\nWould you like to (1) search or (2) delete?");
        scanf("%d", &selection);
        if(selection != 1 && selection != 2)
            printf("\nDang bruh, that is not an option >:(");
    } while(selection != 1 && selection != 2);

    switch(selection)
    {
        case 1: //search
            printf("\nEnter the value for searching: ");
            scanf("%d", &value);
            if(search(a, n, value) == -1)
                printf("The value that you're looking for is not in the array.\n\n");
            else
            {// update with index
                int array_val = search(a, n, value);
                printf("\nThe value you are searching for is %d", a[array_val]);
            }
        break;
        case 2: //delete
            printf("\nEnter the value for deleting: ");
            scanf("%d", &value);
            int j = delete(a, n, value);
            if (j == n) //nothing was deleted
                printf("\nNothing was deleted ):");
            else
            {
                printf("\nThe new array after deleting is: \n");
                for(i = 0; i < j; i++)
                    printf("%d ", a[i]);
            }
        break;
    }//switch

    return 0;
}

int search(int a[], int n, int value) 
{   //      0 1 2 3 4 5    
    // a = [ , ,4, , , ]    
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == value)
            break;
    }

    if(a[i] != value)
        return -1; //not in the array

    return i;
}

int delete(int a[], int n, int value)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == value) //value == 7
            break;
    }

    //   0 1 2 3 4 5 6
    // [ 1 2 4 5 9 2]
    if (i < n)
    {
        n -= 1; //n = 6
        int x;
        for(x = i; x < n; x++) //shift elements to the left
            a[x] = a[x + 1];
    }

    return n;
}
