#include "Node.h"
#include <iostream>

link largest_node_last(link head) {
	
	//capture header node
	link a = head;
	//link b = head;

	//link max finds the node witch largest value
	link max = head;
	link last_node = head;

	//traverse the list while element is not nullptr
	while (a != 0) {

		//if current node is greater than max node
		if (a->item  > max->item) {

			//update new max
			max = a;
		}

		//record last node in the list
		if (a->next == 0) {
			last_node = a;
		}

		//traverse to next node
		a = a->next;

	}

	//reset pointer
	a = head;

	while (a != max) {
		
		if (a->next == max) {

			//previous node of max now points to what max node currently points to
			a->next = max->next;

			//next now points to nullptr
			max->next = 0;

			//the last node now points to max;
			last_node->next = max;

			break;
		}

		//move to next node of b
		a = a->next;

	}

	//reset pointer a to header node
	a = head;

	return a;
}
void test_list() {
	//test case for generating linked list and finding the largest_node and moving to last element.

	int arr[] = { 1,23,16,10,25,6,9,2 };
	int s = sizeof(arr) / sizeof(arr[0]);

	node test_headera(0, 0);
	link node_list_test = arr_to_list(arr, s, &test_headera);

	//ref is a reference node used to pass into the largest_node_last function
	link ref = node_list_test;

	//print nodes out
	while (node_list_test != 0) {
		std::cout << node_list_test->item << " " << std::endl;

		node_list_test = node_list_test->next;
	}

	std::cout << " ------------------------" << std::endl;

	link mod_list = largest_node_last(ref);

	//print nodes out
	while (mod_list != 0) {
		std::cout << mod_list->item << std::endl;
		mod_list = mod_list->next;
	}

}
int main_3_33() {

	test_list();
	
	std::cout << "-------------------------" << std::endl;

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

	link mod_list = largest_node_last(ref);

	//print nodes out
	while (mod_list != 0) {
		std::cout << mod_list->item << std::endl;
		mod_list = mod_list->next;
	}

	return 0;
}