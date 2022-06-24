/*************************************************************
// HEADER FILE
*************************************************************/

/*THINGS THAT GO IN THE HEADER FILE:
    - include libraries
    - function declarations
    - structures, global variables, macro definitions
*/

//deez are called include guards
#ifndef LINKY_LISTY_NODES_H
#define LINKY_LISTY_NODES_H

#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
void clear_list(struct node *list);
struct node *insert_before(struct node *list, int nb, int n);
struct node *insert_after(struct node *list, int nb, int n);

struct node 
{
	int value;          
	struct node *next;  
};

#endif
