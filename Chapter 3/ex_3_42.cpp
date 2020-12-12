#include "Node.h"
#include <iostream>


void josephus_ll_circular(link* headref,int M) {


	//current is the pointer to the first node
	link current = *headref;

	while (current != current->next) {

		for (int i = 1; i < M; i++) {
			//traverse to M-1 node
			current = current->next;
		}
	

		//M-1 node points to M+1 node
		current->next = current->next->next;

		//headref now points to the next node
		*headref = current->next;

		//print current item and new header item
		std::cout << (*headref)->item << " "<< current->item << " " << current->next->item << std::endl;

		}

	}


void test(int M) {
	//example of headera initially pointing to nullptr and then pointing to last node of circular linked list.
	//josephus algorithm implemented on last element of the linked list.

	//current is the pointer to the first node
	link headera=0;

	//a overwrites header which is a nullptr
	link a = new node(1, 0);

	a->next = a;

	link t = a;

	//insert size count number of elements into list
	for (int i = 2; i <= 9; i++) {

		//generate new nodes, traverse to new node, new node points back to first node
		t = t->next = new node(i, a);
	}

	//headera is now the last element in the list
	headera = t;

	link current = headera;
	//std::cout << current->item << current->next->item << std::endl;

	while (current != current->next) {

		for (int i = 1; i < M; i++) {
			//traverse to M-1 node
			current = current->next;
		}


		//M-1 node points to M+1 node
		current->next = current->next->next;

		std::cout << current->item << " " << current->next->item << std::endl;

	}

	//print current item and new header item
	std::cout << current->item << " " << current->next->item << std::endl;

}

void test2(int M) {
	//passing node pointer into function, generate a list and return the last node of the list.
	//headera is a nullptr that does not change

	//current is the pointer to the first node
	link headera = 0;

	//return copy of node pointer that points to end of generated sequality list, headera does not change.
	link s_nums = generate_sequential_circular_list(9, headera);


	link current = s_nums;
	std::cout << current->item << current->next->item << std::endl;
	
	//headera returns a nullpointer, value passed through function is not changed outside function
	//std::cout << (headera)->item << headera->next->item << std::endl; 

	while (current != current->next) {

		for (int i = 1; i < M; i++) {
			//traverse to M-1 node
			current = current->next;
		}


		//M-1 node points to M+1 node
		current->next = current->next->next;

		std::cout << current->item << " " << current->next->item << std::endl;

	}

	//print current item and new header item
	std::cout << current->item << " " << current->next->item << std::endl;

}

int main_3_42() {

	int M = 5;

	//create a null ptr for node
	link headera = 0;

	//return a copy of headera which now points to end of the generated list
	link scl = generate_sequential_circular_list(9, headera);
	print_nodes_circular_list(scl);

	//create a pointer that points to copy of node of end of generated list, tracks the changes of header nodes
	link* headerb = &scl;

	//before running josephus algorithm, headerb points to first node in ccl
	std::cout << (*headerb)->item << std::endl;

	std::cout << "---------------"<< std::endl;

	//headerb now points to one node which is also the header node 
	josephus_ll_circular(headerb, M);

	std::cout << "---------------" << std::endl;
	//test2(5);
	//the algorithm deletes every Mth node, headerb is now the new header node
	std::cout << (*headerb)->item << std::endl;

	return 0;
}


