#include <iostream>
#include "Node.h"



//global head node
link_doubly head_node;
link_doubly th = head_node;
//max value pointer
link_doubly max;

int s = 6;

int find_recursive_max_ll() {
	
	//if at end of list return max value
	if (th->next == head_node) {
		return max->item;
	}
	else {
		int val = th->item;
		int max_val = max->item;

		//if the current val is greater than max
		if (val > max_val) {

			std::cout << "new_max: " << max->item << std::endl;
			//max now points to current val
			max = th;
		}

		//move onto next element in the list
		th = th->next;

		return find_recursive_max_ll();
	}
}

int main_5_17() {

	int arr[] = { 5,27,8,19,3,2 };

	//create linked list with contents of arr
	for (int i = 0; i < s; i++) {

		//if first index initialize head node
		if (i == 0) {
			head_node = new doubly_node(arr[i], 0, 0);
			th = head_node;
			max = head_node;
		}
		else {
			th = th->next = new doubly_node(arr[i], th, 0);
		}
	}

	//fix pointers for last node
	th->next = head_node;
	head_node->prev = th;
	th = th->next;

	//input recursive maxx function
	std::cout << "max: " << find_recursive_max_ll() << std::endl;

	return 0;
}