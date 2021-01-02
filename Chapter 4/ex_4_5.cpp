#include <iostream>
#include "List_processing.h"

void list_allocation_josephus(int N, int M){
	int i;

	list_processing Linked_list;

	node* x,*t;

	//generate n nodes for freelist
	Linked_list.construct(N);

	x = Linked_list.newNode(1);

	for (i = 2; i <= N; i++) {

		t = Linked_list.newNode(i);

		Linked_list.insert(x, t);

		x = t;
	}

	while (x != Linked_list.next(x)) {

		for (i = 1; i < M; i++) {
			x = Linked_list.next(x);
		}
		Linked_list.deleteNode(Linked_list.remove(x));
	}
	std::cout << Linked_list.item(x) << std::endl;
}

void list_allocation_josephus_full(int N, int M) {
	int i;

	list_processing Linked_list;

	//generate n nodes for freelist
	Linked_list.construct(N);

	//set current_node to first node in linked list
	Linked_list.set_first_node(Linked_list.newNode(1));

	for (i = 2; i <= N; i++) {

		//insert nodes into linked list after current node
		Linked_list.insert_linkedList(Linked_list.newNode(i));

		//traverse to next node
		Linked_list.traverse_next_node();
	}

	//iterate until current node is equal to next node
	while (Linked_list.get_current() != Linked_list.get_current()->next) {

		//traverse linked list M-1 times
		for (i = 1; i < M; i++) {
			Linked_list.traverse_next_node();
		}

		//delete the Mth node in the linked list
		Linked_list.deleteNode_from_linked_list(Linked_list.remove_current_node());
	}

	std::cout << Linked_list.item(Linked_list.get_current()) << std::endl;
}

int main_4_5() {
	list_allocation_josephus(13,7); 
	list_allocation_josephus_full(13, 7);
	return 0;
}