#include <iostream>
#include "list_stl.h"

int main3_49() {

	//create first node and have control_node point to first node of linked list.
	link2 first_node = newNode2(1);

	link2* control_node = &first_node;

	link2 t = *control_node;
	//generate a list from 1 -5 
	t = (t)->next = newNode2(2);
	t = (t)->next = newNode2(3);
	t = (t)->next = newNode2(4);
	t = (t)->next = newNode2(5);
	
	//t points to first node again
	t = first_node;


	//print all nodes found in list
	link2 p_node = (t);
	while (p_node != 0) {
		std::cout << p_node->item << std::endl;
		p_node = p_node->next;
	}

	node2* next_node = 0;

	while (t !=0)
	{
		//store the next node
		next_node = t->next;

		//delete current node
		deleteNode2(t);

		//t points to next node
		t = next_node;

	}

	if (t == 0) {
		std::cout << "all elements deleted" << std::endl;
	}
	return 0;
}