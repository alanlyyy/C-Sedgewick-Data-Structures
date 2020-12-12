#include "list.h"
#include <iostream>


void delete_even_nodes(node** list_control) {
	//free all nodes found in the linked list

	node* traverse = (*list_control)->next;

	int count = 1;

	node* prev_node = 0;
	node* next_node = 0;

	//continuously iterate list and delete nodes until first node is reached
	while (traverse != *list_control) {

		//if we are at the node before Nth node
		if ((count % 2) != 0) {

			//save node before Nth element
			prev_node = traverse;

			//store node after Nth element
			next_node = traverse->next->next;

			// move to next node
			traverse = traverse->next;

			//update counter
			count += 1;

			//std::cout << prev_node->item <<" "<< next_node->item << std::endl;
		}
		//if we are at the even node
		else{

			//delete the current node
			deleteNode(traverse);

			//previouse node node now points to node after traverse
			prev_node->next = next_node;

			//traverse now points to next node
			traverse = next_node;

			//reset the count 
			count = 1;
		}
	}

	//if at Nth element, and we are at last element, delete Nth node
	if (((count) == 2) && (traverse == *list_control)) {
		deleteNode(traverse);

		//previouse node node now points to node after traverse
		prev_node->next = next_node;

		//traverse is now equal to next node
		traverse = next_node;
	}

	//header node pointer is reset to now point to first node of new traversed list of deleted elements;
	*list_control = traverse;

}

int main3_48() {

	int M = 10;

	//preallocate 15 positions in memory
	construct(M);


	//create a pointer to a linked list header node
	node** control_node = 0;

	for (int i = 1; i <= M; i++) {

		if (i == 1) {
			node* header_node = newNode(i);

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
	delete_even_nodes(control_node);

	print_nodes(control_node);

	return 0;
}