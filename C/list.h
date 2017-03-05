#ifndef LIST_H_
#define LIST_H_

/*
 * 		Structure of node type
 */

typedef struct node{
    struct node * previous_node;
    struct node * next_node;
    int value;
}node_type;

/*
 * 		Structure of list type
 */

typedef struct list{
	struct node * first_node;
	struct node * last_node;
	int number_of_nodes;
	int sum_of_values;
}list_type;

/*
 * 		Function declaration: (functionality comments in source)
 */

list_type * init_list();
void delete_node(list_type * our_list, struct node * np);
void destroy_list(list_type * our_list);
void add_node(list_type * our_list, int value);
int get_list_length(list_type * our_list);
struct node * get_first_node_pointer(list_type * our_list);
struct node * get_last_node_pointer(list_type * our_list);
struct node * get_next_node_pointer();
struct node * get_previous_node_pointer();
int get_node_value(node_type * np);
double get_avg(list_type * our_list);

#endif /* LIST_H_ */
