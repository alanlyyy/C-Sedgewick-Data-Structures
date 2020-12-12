#include <iostream>
#include <stdlib.h>

struct node
{
	//stores node value
	int item;

	//stores pointer to next node
	node* next;
	
	//node constructor, t is next node
	node(int x, node* t) {
		
		item = x; 
		
		next = t;
	}
};

//grab type of node* and initialize with variable link.
typedef node* link;

int len_of_Circular_list(node* current_node) {
	//given a node to a circular list calculate length of entire list.

		//start node is copy of next node current node is pointing to (node 2)
		node * start_node = current_node->next;

		int count = 1;

		//from node 2 back to node 1
		while (start_node != current_node) {

			//traverse to next node
			start_node = start_node->next;

			std::cout << start_node->item << " ";

			count += 1;
		}
		std::cout << std::endl;

		return count;
}

int main_3_23() {


	int N = 10;
	//create first node with value 1, points to null
	link t = new node(1, 0);

	//first node now points to itself
	t->next = t;

	//x is a copy of the first node
	link x = t;

	//create N number of nodes after first node
	for (int i = 2; i < N; i++) {

		//1.create new node that points to first node, 
		//2.current node points to newly created node, 
		//3.currrent node is the newly created node
		x = (x->next = new node(i, t));
	}

	std::cout << "len of t:" << len_of_Circular_list(t) << std::endl;;
	std::cout << "len of t[3]:" << len_of_Circular_list(t->next->next->next) << std::endl;

	return 0;
}