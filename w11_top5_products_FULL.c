/*
Program:            Top 5 Products
Authors:            Egg Gang
Description:        Sort an array of structures containing
                    information about produce items, in which they
                    are sorted by the amount sold, and the top 5 products
                    are stored in an output file.              
*/

#include <stdio.h>
#define MAX 100 //max char array length of produce name

struct product
{
    char name[MAX + 1];
    double unit_price;
    double quantity;
};

void sort_products(struct product list[], int n);
int find_largest(struct product list[], int n);

int main()
{
    struct product frootvegs[MAX]; //array of structures

    FILE *fp = fopen("fruits_vegetables.txt", "r");
    if(fp == NULL)
    {
        printf("error on reading");
        return 1;
    }

    int i = 0;
    while(!feof(fp) && !ferror(fp))
    {
        fscanf(fp, "%s %lf %lf", frootvegs[i].name, &frootvegs[i].unit_price, &frootvegs[i].quantity);
        //fgets(buffer, buffer_len, fp); //break buffer by spaces to get separate entries
        i++; //keeps track of lines in file/num of products
    }

    sort_products(frootvegs, i);

    //write the top 5 proddies to an output file
    FILE *fw = fopen("top5_proddies.txt", "w");
    if(fw == NULL)
    {
        printf("error on reading");
        return 1;
    }    

    printf("\nYour file name is: top5_proddies.txt\nTop 5 products are: ");

    int a;
    for(a = i - 1; a > i - 6; a--)
    {
        printf("\n%-20s %15.2lf %15.2lf", frootvegs[a].name, frootvegs[a].unit_price, frootvegs[a].quantity);
        fprintf(fw, "%-20s %15.2lf %15.2lf\n", frootvegs[a].name, frootvegs[a].unit_price, frootvegs[a].quantity);
    }

    fclose(fp);
    fclose(fw);

    return 0;
}

void sort_products(struct product list[], int n)
{
    struct product temp;
    int largest = 0;
    if(n == 1)//base case of recursive sort function call
        return;

    largest = find_largest(list, n); //help find index of max value in structure array

    //swap statements we all know and love <3
    if(largest < n - 1)//if index of largest value is not at the end {n-1} of our array
    {
        temp = list[n-1];
        list[n-1] = list[largest];
        list[largest] = temp;
    }
    // 1 2 3 4 5
    sort_products(list, n-1);
}

int find_largest(struct product list[], int n)
{
    int i, max_index = 0;
    for(i = 1; i < n; i++) 
    {
        if(list[i].quantity > list[max_index].quantity)
            max_index = i;
    }
    return max_index;
}