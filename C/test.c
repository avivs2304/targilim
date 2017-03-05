#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

/*
 * tests all the requirements.
 */
int main(int argc, char * argv[]){
	printf("------------- Testing list ----------------\n\n");
	list_type * our_list = init_list();
	int i;
	for(i=1;i<=10;i++){
		add_node(our_list, i);
	}
	printf("length: %d\n", get_list_length(our_list));
	printf("get first node pointer %p\n", get_first_node_pointer(our_list));
	printf("get last node pointer %p\n", get_last_node_pointer(our_list));
	printf("get second node pointer %p\n", get_next_node_pointer(get_first_node_pointer(our_list)));
	printf("get second to last node pointer %p\n", get_previous_node_pointer(get_last_node_pointer(our_list)));
	printf("get last pointer value %d\n", get_node_value(get_last_node_pointer(our_list)));
	printf("print avg: %f\n", get_avg(our_list));
	delete_node(our_list, get_previous_node_pointer(get_last_node_pointer(our_list)));
	destroy_list(our_list);
	printf("length: %d\n", get_list_length(our_list));

	printf("\n------------- Testing queue ----------------\n\n");

	queue_type * our_queue = init_queue();
	for(i=10;i<20;i++){
		add_to_queue(our_queue, i);
	}
	printf("the first node: %d, length is: %d\n", get_first_queue(our_queue), get_queue_length(our_queue));
	printf("popped %d\n", delete_first_queue_node(our_queue));
	printf("the first node: %d, length is: %d\n", get_first_queue(our_queue), get_queue_length(our_queue));
	destroy_queue(our_queue);

	return 0;
}
