#include "Node.h"
#include <iostream>

link reversal_with_head(link x) {
	//x is a header node, flip list so all elements in reverse order

	link t , y = x->next, r = 0;

	while (y != 0) {
		t = y->next;
		y->next = r;
		r = y;

		y = t;

		//if at last element, header node x points to last node r
		if (y == 0) {
			x->next = r;
		}
	}

	return x;
}

int main_3_40() {

	int arr1[] = { 0,3,0,0,7,9 };
	int arr2[] = { 0,3,0,5,0,9 };

	node headerb(0, 0);
	node headera(0, 0);

	link list1 = arr_to_list(arr1, 6, &headera);
	link list2 = arr_to_list(arr2, 6, &headerb);

	print_nodes(list1);
	std::cout << "Case 1------------------" << std::endl;
	link mod_list = reversal_with_head(list1);

	print_nodes(mod_list);

	std::cout << " ----------------- " << std::endl;

	print_nodes(list2);
	std::cout << "Case 2------------------" << std::endl;
	link mod_list_2 = reversal_with_head(list2);

	print_nodes(mod_list_2);
	return 0;
}