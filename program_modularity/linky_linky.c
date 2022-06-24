/*************************************************************
// SOURCE FILE FOR MAIN FUNCTION
*************************************************************/

//new_node = malloc(memory for new node)
//readline(new_node->name, LENGTH);

#include "linky_listy_nodes.h"

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