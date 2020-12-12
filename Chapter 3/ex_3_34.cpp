#include "Node.h"
#include <iostream>

link smallest_node_first(link head) {

	//capture 1st node
	link a = head->next;

	//link min finds the node with smallest value
	link min = head->next;
	link first_node = head;

	//traverse the list while element is not nullptr
	while (a != 0) {

		//if current node is less than min node
		if (a->item < min->item) {

			//update new min
			min = a;
		}

		//traverse to next node
		a = a->next;

	}

	//reset pointer
	a = head;

	while (a != min) {

		if (a->next == min) {

			//previous node of min now points to what min node currently points to
			a->next = min->next;

			//next now points to node that header node is pointing to.
			min->next = first_node->next;

			//the header node now points to min;
			first_node->next = min;

			break;
		}

		//move to next node of b
		a = a->next;

	}

	//reset pointer a to header node
	a = head;

	return a;
}

int main_3_34() {

	//pass header node to function to save created linked list after function scope is destroyed
	node headera(0, 0);
	link node_list = generate_random_nodes(20, &headera);

	//ref is a reference node used to pass into the largest_node_last function
	link ref = node_list;

	//print nodes out
	while (node_list != 0) {
		std::cout << node_list->item << " " << std::endl;

		node_list = node_list->next;
	}

	std::cout << " ------------------------" << std::endl;

	link mod_list = smallest_node_first(ref);

	//print nodes out
	while (mod_list != 0) {
		std::cout << mod_list->item << std::endl;
		mod_list = mod_list->next;
	}

	return 0;
}