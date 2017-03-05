#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

/*
 * 		Initialize the queue
 */
queue_type * init_queue(){
	queue_type * our_queue = malloc(sizeof(queue_type));
	our_queue->list = init_list();
	return our_queue;
}

/*
 * 		Destroy the queue
 */

void destroy_queue(queue_type * our_queue){
	destroy_list(our_queue->list);
	free(our_queue);
}

/*
 * 		Add a new node to the end of the queue
 */

void add_to_queue(queue_type * our_queue, int value){
	add_node(our_queue->list, value);
}

/*
 * 		Delete the first node in the queue and return its value
 */

int delete_first_queue_node(queue_type * our_queue){
	int value;
	value=get_node_value(our_queue->list->first_node);
	delete_node(our_queue->list, our_queue->list->first_node);
	return value;
}

/*
 * 		Gets the length of the queue (number of nodes)
 */

int get_queue_length(queue_type * our_queue){
	return get_list_length(our_queue->list);
}

/*
 * 		Gets the first node value
 */

int get_first_queue(queue_type * our_queue){
	return get_node_value(our_queue->list->first_node);
}

