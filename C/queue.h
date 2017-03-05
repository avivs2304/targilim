#ifndef QUEUE_H_
#define QUEUE_H_

/*
 * 		Structure of queue type
 */

typedef struct queue{
	list_type * list;
}queue_type;

/*
 * 		Function declaration: (functionality comments in source)
 */

int get_first_queue(queue_type * our_queue);
int get_queue_length(queue_type * our_queue);
int delete_first_queue_node(queue_type * our_queue);
void add_to_queue(queue_type * our_queue, int value);
void destroy_queue(queue_type * our_queue);
queue_type * init_queue();

#endif /* QUEUE_H_ */
