#include "Node.h"
#include <iostream>

void generate_nodes_doubly2(Node_doubly** control_node, int size) {

	//create M nodes for the linked list, control_node still points to the pointer of the first node found in the list.
	//generated nodes are retained outside the function.

	Node_doubly* t = *control_node;

	for (int i = 2; i < size; i++) {
		t = (t->next = new Node_doubly(i, t, 0));
	}
}


void doubly_node_swap2( Node_doubly* node1, Node_doubly* node2) {


	Node_doubly* temp;

	//p_node is a pointer to the first node
	//Node_doubly* p_node = *control_node;


	//if both nodes are the same don't do anything
	if (node1 == node2) {
		return;
	}

	//if node2 comes before node1, swap pointers for node1 and node2
	if (node2->next == node1) {
		temp = node1;
		node1 = node2;
		node2 = temp;
	}

	Node_doubly* prev_node = node1->prev;
	Node_doubly* next_node = node1->next;
	Node_doubly* current_node1 = node1;

	Node_doubly* prev_node2 = node2->prev;
	Node_doubly* next_node2 = node2->next;
	Node_doubly* current_node2 = node1;


	//if node1 and node2 are adjacent to one another
	if ((node1->next == node2 && node2->prev == node1)
		|| (node1->prev == node2 && node2->next == node1))
	{
		node1->prev = next_node;
		node2->prev = prev_node;
		node1->next = next_node2;
		node2->next = prev_node2;

	}
	//if nodes are not adjacent
	else {
		node1->prev = prev_node2;
		node2->prev = prev_node;
		node1->next = next_node2;
		node2->next = next_node;
	}


	//after swapping node1 and node2, adjust pointers of prev and next nodes
	//to point back to the newly swapped nodes.
	if (node1->prev != 0) {
		node1->prev->next = node1;
	}
	if (node1->next != 0) {
		node1->next->prev = node1;
	}

	if (node2->prev != 0) {
		node2->prev->next = node2;
	}
	if (node2->next != 0) {
		node2->next->prev = node2;
	}	
}

int main_3_43() {

	int M = 14;

	//create a headers/first node
	Node_doubly * node1 = new Node_doubly(1, 0, 0);

	//control node is a header pointer that points to pointer to node 1.
	//we pass this pointer into functions to retain changes made to the linked list
	Node_doubly** control_node = &node1;

	//pass in pointer to pointer of the first node, append new nodes to linked list
	generate_nodes_doubly2(control_node,M);

	print_nodes(control_node);

	std::cout << "=======================" << std::endl;

	//dereference pointer  to get access to each individual node pointer, adjust the values of the node pointers, control_node retains changes.
	doubly_node_swap2((*control_node)->next->next, (*control_node)->next->next->next->next->next);

	std::cout << "=======================" << std::endl;

	//update p_node is a pointer to the first node to new swapped list
	
	print_nodes(control_node);

	return 0;

}

