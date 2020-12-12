#include "Node.h"
#include <iostream>

link list_copy(link headera, link headerb) {

	//generates a copy of list starting at headera with headerb

	link first_node = headera;
	link first_node_copy = headerb;

	link traverse = first_node->next;
	link traverse_node_copy = first_node_copy;

	while (traverse != 0) {

		//2nd list current node points to current node of 1st list
		traverse_node_copy->next = traverse;

		//2nd list current node is now the 1st list current node
		traverse_node_copy = traverse;

		//move to next node
		traverse = traverse->next;

	}


	return headerb;
}

int main_3_37() {

	node headera(0, 0);
	node headerb(0, 0);

	link rand_list = generate_random_nodes(10, &headera);

	print_nodes(rand_list);
	std::cout << " --------------- " << std::endl;

	link mod_list = list_copy(rand_list,&headerb);

	print_nodes(mod_list);
	std::cout << " --------------- " << std::endl;

	return 0;
}