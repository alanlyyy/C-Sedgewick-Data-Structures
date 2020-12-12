#include "list.h"
#include <iostream>

bool is_same_list(link l1, link l2) {
	//check if l1 and l2 are list in the same cycle
	//if true l2 is a node found in l1, cycle
	//else l1 and l2 are two different lists.

	link traverse = l1->next;

	while (traverse != l1) {

		if (traverse == l2) {
			if (traverse->next == l2->next) {
				return true;
			}
			else {
				return false;
			}
		}

		traverse = traverse->next;
	}

	return false;
}

int main_3_54() {
	//Since a set contains only unique values of all values found in the list
	//if each node cannot point to a nullptr and each node has to point to a node in the set that is not already pointed to
	//the linked list will create a cycle where the start of the list is equal to the end of the list.

	construct(10);

	//create first node and have control_node point to first node of linked list.
	link first_node = newNode(1);
	link second_node = newNode(1);

	link* control_node = &first_node;
	link* second_control_node = &second_node;

	//generate a list from 1 -5 
	insert(*control_node, newNode(2));
	insert(*control_node, newNode(3));
	insert(*control_node, newNode(4));
	insert(*control_node, newNode(5));

	insert(*second_control_node, newNode(2));
	insert(*second_control_node, newNode(3));
	insert(*second_control_node, newNode(4));
	insert(*second_control_node, newNode(5));

	std::cout << "False" << " " << is_same_list((*control_node)->next, (*second_control_node)->next) << std::endl;
	std::cout << "True" << " " << is_same_list((*control_node)->next->next, (*control_node)) << std::endl;

	return 0;
}