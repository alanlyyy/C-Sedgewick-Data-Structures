#include "Node.h"
#include <iostream>


int get_item(link current_node) {

	std::cout << "current item: " << current_node->item << std::endl;
	return current_node->item;
}

link node_removal_list(link headera, int(*function_call)(link args) ) {
	//this function accepts a node and a function call
	//remove all nodes of headera if function call returns a non zero value of the node.

	link first_node = headera;
	link first_node_next = headera->next;

	while (first_node->next != 0) {

		//if item of current node is equal to 0
		if (function_call(first_node->next) == 0) {

			//is next not node a nullptr?
			if (first_node->next != 0) {

				//delete next node 
				first_node->next = first_node->next->next;
			}
		}

		//if next node is not a 0, update current node to next node
		else {
			//update to next element
			first_node = first_node->next;
		}

	}

	return headera;
}

int main_3_38() {

	int arr1[] = { 0,3,0,0,7,9 };
	int arr2[] = { 0,3,0,5,0,9 };

	node headerb(0, 0);
	node headera(0, 0);

	link list1 = arr_to_list(arr1, 6, &headera);
	link list2 = arr_to_list(arr2,6, &headerb);

	print_nodes(list1);
	std::cout << "Case 1------------------" << std::endl;
	link mod_list = node_removal_list(list1, get_item);

	print_nodes(mod_list);

	std::cout << " ----------------- " << std::endl;

	print_nodes(list2);
	std::cout << "Case 2------------------" << std::endl;
	link mod_list_2 = node_removal_list(list2, get_item);

	print_nodes(mod_list_2);
	return 0;
}