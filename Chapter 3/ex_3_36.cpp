#include "Node.h"
#include <iostream>

link node_swap(link header, link node_a, link node_b) {

	link traverse = header;

	link first_node = node_a;
	link after_first_node = first_node->next;

	link second_node = node_b;
	link after_second_node = second_node->next;

	link last_first_node = node_a;
	link last_second_node = node_b;

	//if node a is next to node b, do not perform swap, return header
	if (first_node->next == second_node) {
		return header;
	}

	//get the last first node before reaching second node
	while (traverse != 0) {

		if (traverse->next == second_node) {
			last_first_node = traverse;
			//std::cout << last_first_node->item << std::endl;
		}


		if (traverse->next == 0) {
			last_second_node = traverse;
			//std::cout << last_second_node->item << std::endl;
		}

		traverse = traverse->next;
	}

	//first_node now points to the following node after second node
	//the last node after the second node now points to first node
	first_node->next = after_second_node;
	last_second_node->next = second_node;

	//second_node now points to the following node after first node
	//the last node after the first node now points to nullptr
	second_node->next = after_first_node;
	last_first_node->next = 0;


	//return node header for traversal
	return header;
}

int main_3_36() {

	node headera(0, 0);
	node headerb(0, 0);

	link rand_list = generate_random_nodes(10, &headera);

	link ref = generate_random_nodes(10, &headerb);

	print_nodes(rand_list);
	std::cout << " --------------- " << std::endl;
	
	link mod_list = node_swap(&headera, rand_list->next, rand_list->next->next->next);

	print_nodes(mod_list);
	std::cout << " --------------- " << std::endl;

	print_nodes(ref);
	std::cout << " --------------- " << std::endl;

	link mod_list_no_swap = node_swap(&headerb, ref->next, ref->next->next);

	print_nodes(mod_list_no_swap);
	std::cout << " --------------- " << std::endl;

	return 0;
}