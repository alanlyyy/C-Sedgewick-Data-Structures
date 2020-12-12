#include "list_ex_3_51.h"
#include <iostream>


void josephus_list_allocation(int M, int size) {
	Node t, x;
	int i;
	construct(size);

	for (i = 2, x = newNode(1); i <= size; i++) {
		t = newNode(i);
		insert(x, t);
		x = t;
	}

	while (x != next(x)){
		for (i = 1; i < M; i++) {
			x = next(x);
		}

		deleteNode(remove(x));
	}

	std::cout << item(x)<<std::endl;
	std::cout << "=======================" << std::endl;
	print_free_list();

}
int test() {
	
	int M = 5;

	//generate 5 nodes
	construct(M);


	node* first_node = newNode(1);

	//control_node points to linked list, or pointer to first node
	node** control_node = &first_node;

	//traversal pointer
	node* t = *control_node;

	for (int i = 2; i < M; i++) {

	insert(t, newNode(i));
	t = t->next;
	}

	//reset pointer t to first_Node of list
	t = first_node;

	std::cout << t->item << std::endl;
	t = t->next;
	//pointer t now points to the next node of t;
	while (t != *control_node) {
		std::cout << t->item << std::endl;
		t = t->next;
	}


	return 0;
}

int main_3_51() {

	//josephus_list_allocation(5, 9);
	return 0;
}