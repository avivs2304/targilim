#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*
 *		Initialize the list
 */

list_type * init_list(){
	list_type * our_list = malloc(sizeof(list_type));
	our_list->first_node = NULL;
	our_list->last_node = NULL;
	our_list->number_of_nodes = 0;
	our_list->sum_of_values = 0;
	return our_list;
}

/*
 * 		Delete a given node
 */

void delete_node(list_type * our_list, struct node * np){
	if(np != NULL){
		if(np->previous_node == NULL || np->next_node == NULL){
			/* if this is the last node and first node*/
			if(np->previous_node == NULL && np->next_node == NULL){
				printf("destroyed\n");
			} else {
				/* if this is the first node */
				if(np->previous_node == NULL){
					np->next_node->previous_node = np->previous_node;
					our_list->first_node = np->next_node;
				} else {
					/* if this is the last node */
					np->previous_node->next_node = np->next_node;
					our_list->last_node = np->previous_node;
				}
			}
		} else {
			/* if this is a "regular" node */
			np->next_node->previous_node = np->previous_node;
			np->previous_node->next_node = np->next_node;
		}
		--our_list->number_of_nodes;
		our_list->sum_of_values -= np->value;
		free(np);
	} else {
		printf("cannot delete, NULL node pointer");
	}
}

/*
 * 		Destroy entire list
 */

void destroy_list(list_type * our_list){
	struct node * np;
	while(our_list->number_of_nodes > 0){
		delete_node(our_list, our_list->first_node);
	}
	free(our_list);
}

/*
 * 		Add a single node
 */

void add_node(list_type * our_list, int value){
	node_type * our_node = malloc(sizeof(node_type));
	our_node->value = value;
	our_node->previous_node = our_list->last_node;
	/* if this is the first node */
	if(our_list->first_node==0){
		our_list->first_node = our_node;
		our_node->previous_node = NULL;
	} else {
		our_node->previous_node->next_node = our_node;
	}
	our_list->last_node = our_node;
	++our_list->number_of_nodes;
	our_list->sum_of_values += value;
	our_node->next_node = NULL;
}

/*
 * 		Returns the number of nodes
 */

int get_list_length(list_type * our_list){
	if(our_list->number_of_nodes !=0){
		return our_list->number_of_nodes;
	}
	printf("list empty\n");
	return 0;
}

/*
 * 		Gets the pointer of the first node.
 */

struct node * get_first_node_pointer(list_type * our_list){
	return our_list->first_node;
}

/*
 * 		Gets the pointer of the last node.
 */

struct node * get_last_node_pointer(list_type * our_list){
	return our_list->last_node;
}

/*
 *		Gets the pointer of the next node of the argument node.
 */

struct node * get_next_node_pointer(node_type * np){
	return np->next_node;
}
 /*
  * 	Gets the pointer of the previous node of the argument node.
  */

struct node * get_previous_node_pointer(node_type * np){
	return np->previous_node;
}

/*
 * 		Gets the value of the argument node.
 */
int get_node_value(node_type * np){
	return np->value;
}

/*
 * 		Gets the average of the values in the list.
 */
double get_avg(list_type * our_list){
	return ((double)(our_list->sum_of_values)/our_list->number_of_nodes);
}

