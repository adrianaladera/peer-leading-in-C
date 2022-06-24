/*************************************************************
If you'd like to follow along, the unseparated code will be
in Canvas > Modules > Week 13 > Week 13: Live Lab Recordings
> Tuesday (11/16) with Adriana > w13_doubly_linked_lists.c
*************************************************************/

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

int main()
{

 	struct node *add_node = NULL; //initializing an empty linked list
    struct node *p;
	char code;
	int swag, swig;

	for(;;)
	{
		printf("\nEnter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');   /* skips to end of line */

		switch (code) 
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
			case 'q': 
				printf("\nFreeing all nodes from list.\nExiting now....\n");
				clear_list(add_node);
				return 0;
			default:  printf("SORRY AMIGO BUT THAT CODE ENTRY IS NOT VALID\n");
		} //end switch
		
		printf("\nYour list contains:\n");
		for(p = add_node; p != NULL; p = p->next)
        	printf("%d\t", p->value); //(*p).value
    	printf("\n");

	} //end for
    return 0;

}

struct node *insert_before(struct node *list, int nb, int n)
{
	  struct node *new_node;
	  struct node *prev, *cur;
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    return list;
	  }

	new_node->value = n;
	//search for nb
	for(prev = NULL, cur=list; cur!=NULL&&cur->value!=nb;
		prev=cur, cur=cur->next)
	   ;
	//nb is not found  
	if(cur == NULL) 
	{
		printf("\nSorry bestie, value not found in list D:\n");
		return list;
	}
	if(prev== NULL){ // or cur== list  
	//nb is found in the add_node node
		new_node->next = cur;
		return new_node;//new_node becomes the new add_node node
	}
	else{
		prev->next = new_node;
		new_node->next= cur;
		return list;
	}
}

struct node *insert_after(struct node *list, int nb, int n)
{
	  struct node *new_node;
	  struct node  *cur;
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    return list;
	  }

	new_node->value = n; 
	//search for nb
	for(cur =list; cur!=NULL &&cur->value!=nb;cur=cur->next)
		;
	//nb is not found
	if(cur == NULL) //reached the end of the list
	{
		printf("\nSorry bestie, value not found in list D:\n");
		return list;
	}
	//insert n after nb, cur points to the node containing nb
	new_node->next = cur->next; 
	cur ->next = new_node;
	return list; //returns list with updated node
	
}


struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("Error: malloc failed in add_to_list\n");
	    exit(EXIT_FAILURE);
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

void clear_list(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	p = list;
        list = list->next;
        if( p!= NULL)
           free(p);
  }
}
 
