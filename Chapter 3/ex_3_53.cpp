#include "list.h"
#include <iostream>

int main3_53() {
	//Since a set contains only unique values of all values found in the list
	//if each node cannot point to a nullptr and each node has to point to a node in the set that is not already pointed to
	//the linked list will create a cycle where the start of the list is equal to the end of the list.

	construct(10);

	//create first node and have control_node point to first node of linked list.
	link first_node = newNode(1);

	link* control_node = &first_node;

	//generate a list from 1 -5 
	insert(*control_node, newNode(2));
	insert(*control_node,newNode(3));
	insert(*control_node, newNode(4));
	insert(*control_node, newNode(5));

	link t = *control_node;
	//print all nodes found in list

	link p_node = (t);
	std::cout << p_node->item << std::endl;

	p_node = p_node->next;

	while (p_node != *control_node) {
		std::cout << p_node->item << std::endl;
		p_node = p_node->next;
	}

	return 0;

}