/*******************************************************************************
If you would like to follow along, this code is in Canvas > Modules >
Week 13 > Week 13: Live Lab Recordings > Tuesday (11/16) with Adriana   :D
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
void clear_list(struct node *list);
void print_list(struct node *list);
struct node *insert_before(struct node *list, int nb, int n);
struct node *insert_after(struct node *list, int nb, int n);

struct node 
{
	int value;          
	struct node *next;  //YOU NEED DIS BIH FOR ALL LINKED LISTS
};

int main()
{
    struct node *add_node = NULL;
    char code;
    int swag, swig;

    for(;;) //infinite loop, same as while(1)
    {
        printf("\nWELCOME TO THE LINKED LIST MANAGER MY FRIEND! \nOptions: "
        "\nf - enter value at first node in list"
        "\na - enter value after node"
        "\nb - enter value before node"
        "\np - print all nodes values in list"
        "\nq - quit program");
        printf("\nEnter operation code bestie: ");
        scanf(" %c", &code);
        while(getchar() != '\n'); 

        switch(code)
        {
            case 'f':
                printf("\nEnter a value to be inserted into the list (type \'q\' to exit): ");
                scanf("%d", &swag);
                add_node = add_to_list(add_node, swag);
            break;
            case 'a':
                printf("\nEnter a value to be inserted into the list (type \'q\' to exit): ");
                scanf("%d", &swag);
                printf("Insert %d after (enter a value in the list): ", swag);
                scanf("%d", &swig);
                add_node = insert_after(add_node, swig, swag);
            break;   
            case 'b':
                printf("\nEnter a value to be inserted into the list (type \'q\' to exit): ");
                scanf("%d", &swag);
                printf("Insert %d before (enter a value in the list): ", swag);
                scanf("%d", &swig);
                add_node = insert_before(add_node, swig, swag);            
            break; 
            case 'p':
                print_list(add_node);
            break;
            case 'q':
                printf("\nFreeing all nodes from list. \nExiting now...\n");
                clear_list(add_node);
                return 0;
            break;
            default: printf("SORRY AMIGO BUT THAT CODE ENTRY IS NOT VALID");                               
        }
    }//end for(;;)
    return 0;
}

struct node *insert_before(struct node *list, int nb, int n)
{
	//add your code here
} // end func

//nb is value to search in linked list
//n value to add into linked list
struct node *insert_after(struct node *list, int nb, int n)
{
	//add your code here
}

// add to beginnning of linked list
struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
        // new_node malloc(strlen(s) + 1)
	  new_node =  malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    exit(EXIT_FAILURE);
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

void print_list(struct node *list)
{
    struct node *p;
    printf("\nYour list contains: ");
    for(p = list; p != NULL; p=p->next)
        printf("%d\t", p->value);
    printf("\n");
}

// frees all node memory from linked list
void clear_list(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	p = list;
        list = list->next;
        if( p!= NULL) //memory has not been freed
           free(p);
  }
}
 
