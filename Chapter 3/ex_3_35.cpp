#include "Node.h"
#include <iostream>



link insertion_sort_even_odd_split(link headera) {
	
	//Must pass in headera node,unsorted list 
	//return headera sorted list broken up by odd and even split.

	link a = headera, t = a;

	link u = t;

	node odd(0, 0);
	link x, b = &odd;

	node even(0, 0);
	link y, c = &even;

	//stores the last odd node for combining even and odd nodes
	link last_odd_node =b;

	for (t = a->next; t != 0; t = u) {

		//store the next element before we lose the element from the swap
		u = t->next;

		//is current element even?
		if ((t->item % 2) != 0) {
			//traverse entire list until we find node that is greater than current item and odd
			for (x = b; x->next != 0; x = x->next) {

				//if current node is smaller than traverse node break.
				if (x->next->item > t->item) {
					break;
				}
			}

			//swap the 2 nodes
			t->next = x->next;
			x->next = t;
		}
		//is current element odd?
		else {
			//traverse entire list until we find node that is greater than current item and even
			for (y = c; y->next != 0; y = y->next) {

				//if current node is smaller than traverse node break.
				if (y->next->item > t->item) {
					break;
				}
			}

			//swap the 2 nodes
			t->next = y->next;
			y->next = t;

		}
		
	}
	x = &odd;
	y = &even;

	while (x != 0) {

		//find the last odd node
		if (x->next == 0) {
			last_odd_node = x;
			break;
		}

		//traverse to next node
		x = x->next;
	}

	//join the odd list and even list
	last_odd_node->next = c->next;

	//headera points to the odd and even list
	headera->next = b->next;

	return headera;
}

int test_insertion_sort() {
	node headera(0, 0);
	link rand_list = generate_random_nodes(10, &headera);

	//make a copy of randlist to pass into sorted_list
	link ref = rand_list;

	print_nodes(rand_list);

	link sorted_list = insertion_sort(ref);

	print_nodes(sorted_list);

	return 0;

}

int main_3_35() {

	node headera(0, 0);
	link rand_list = generate_random_nodes(10, &headera);

	//make a copy of randlist to pass into sorted_list
	link ref = rand_list;

	print_nodes(rand_list);
	std::cout << "-------------------" << std::endl;
	link sorted_list = insertion_sort_even_odd_split(ref);

	print_nodes(sorted_list);
	return 0;
}