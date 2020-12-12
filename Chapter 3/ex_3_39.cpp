#include "Node.h"
#include <iostream>


int get_item_node(link current_node) {

	std::cout << "current item: " << current_node->item << std::endl;
	if (current_node->item != 0) {
		return current_node->item;
	}
	else {
		return 0;
	}
}

link node_removal_list(link headera, link headerb, int(*function_call)(link arg1)) {
	//this function accepts a node and a function call
	//remove all nodes of headera if function call returns a non zero value of the node.

	link first_node = headera;
	link current_node = headera->next;

	link return_list = headerb;

	//node tempNode= *headerb;
	while (first_node->next != 0) {

		//keep track of node after one above first_node
		current_node = current_node->next;
		
		//is current node = 0?
		if (function_call(first_node->next) ==0)
		{
			//delete next node 
			first_node->next = first_node->next->next;
		}
		else {

			//if current element is not equal to 0, make a copy node, with the same 'item' value
			return_list->next = new node(first_node->next->item, 0);

			//update the tracking node to equal the new node
			return_list = return_list->next;

			//update to next node
			first_node = first_node->next;
		}
	}

	return headerb;
}

int main_3_39() {

	int arr1[] = { 0,3,0,0,7,9 };
	int arr2[] = { 0,3,0,5,0,9 };

	node headerb(0, 0);
	node headera(0, 0);
	node headerc(0, 0);
	node headerd(0, 0);

	link list1 = arr_to_list(arr1, 6, &headera);
	link list2 = arr_to_list(arr2, 6, &headerb);

	print_nodes(list1);
	std::cout << "Case 1------------------" << std::endl;
	link mod_list = node_removal_list(list1,&headerc, get_item_node);

	print_nodes(mod_list);

	std::cout << " ----------------- " << std::endl;

	print_nodes(list2);
	std::cout << "Case 2------------------" << std::endl;
	link mod_list_2 = node_removal_list(list2, &headerd, get_item_node);

	print_nodes(mod_list_2);
	return 0;
}