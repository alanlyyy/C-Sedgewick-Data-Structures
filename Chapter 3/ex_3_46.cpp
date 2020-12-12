#include "list.h"
#include <iostream>


void destroy_list(node** list_control) {
	//free all nodes found in the linked list

	node * traverse = (*list_control)->next;

	//continuously iterate list and deleted nodes until nullptr is reached
	while (traverse != 0) {
		deleteNode(traverse);
		traverse = traverse->next;
	}

	//reset pointer of first node to nullptr
	*list_control = 0;

}

int main_ex_3_46() {

	int M = 5;

	//preallocate 5 positions in memory
	construct(M);
	

	//create a pointer to a linked list header node
	node** control_node= 0;

	for (int i = 1; i <= M; i++) {

		if (i == 1) {
			node * header_node = newNode(i);

			//control node points to pointer that points to first node of linked list
			control_node = &header_node;
		}
		else {

			//pass pointer to link list of pointer to current node, insert newNode at the end of current node
			insert(*control_node, newNode(i));
		}
	}

	print_nodes(control_node);

	//delete list from memory
	destroy_list(control_node);

	print_nodes(control_node);

	return 0;
}