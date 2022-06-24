/*************************************************************
//SOURCE FILE FOR OTHER FUNCTIONS
*************************************************************/
//each source file must have groups of functions with similar purposes
//e.g. these are all functions that modify the linky listy
#include "linky_listy_nodes.h"
//#include "readline.h"

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
 
