/*
Authors:        The Swaggy Peeps
Program:        Insert into Linked List
Description:    Creating a linked list of integer numbers
*/

#include<stdio.h>
#include<stdlib.h> // EXIT_FAILURE

struct node *add_to_list(struct node *list, int n); //list = linked list, n = value to insert
void clear_list(struct node *list);

struct node {
    int value;
    struct node *next; //helps to link two nodes in a list
};

int main()
{
    struct node *add_node = NULL; //initializing an empty linked list
    struct node *p;

    printf("\nEnter a value to be inserted into the list (type a negative value to exit): ");
    int swag = 0;

    while(1) //for(;;) //infinite loops
    {
        scanf("%d", &swag);
        if(swag < 0)
            break;
        add_node = add_to_list(add_node, swag);
        //modifying means assign to original linked list name
    }

    for(p = add_node; p != NULL; p = p->next)
        printf("%d\t", p->value); //(*p).value
    printf("\n");

    clear_list(add_node);

    return 0;
}

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node)); //create a new node in a list

    if(new_node == NULL) //as long as there is still memory to allocate
    {
        printf("ERROR BESTIE NO MALLOC ALLOWED");
        exit(EXIT_FAILURE); //quits function prematurely
    }

    new_node->value = n;
    new_node->next = list; //adding node to beginning of list
    return new_node;
}

void clear_list(struct node *list)
{
    struct node *p;
    while(list != NULL)
    {
        p = list;
        list = list->next;
        if(p != NULL)
            free(p);
    }
}

