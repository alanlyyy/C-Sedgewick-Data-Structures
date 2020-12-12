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

typedef node* link;

node* Circular_list_position_swap(node* current_node, node* other_node) {
	////swap the node current node is pointing to with the node other node is pointing to in the same circular list.
	
	//start node
	node* reference = current_node->next;

	//print all nodes
	while (reference != current_node) {
		std::cout << reference->item << " ";

		//traverse to next node
		reference = reference->next;
	}

	std::cout << std::endl;

	//store the next current_node for the insertion to take place
	link temp_curr_node_next = current_node->next;

	//store the next next other node to relink other_node->next-> to other_node->next
	link temp_other_node_next = other_node->next->next;

	//next current_node is now equal to next other node 
	current_node->next = other_node->next;

	//next current node (next other node) is now equal to next curent node previous
	current_node->next->next = temp_curr_node_next;

	//next other node is now equal to other_node->next->next 
	other_node->next = temp_other_node_next;

	//update the current node
	reference = current_node->next;
	//print all nodes
	while (reference != current_node) {
		std::cout << reference->item << " ";

		//traverse to next node
		reference = reference->next;
	}

	std::cout << std::endl;


	return current_node;
}

int main3_26() {

	//create list 1

	int N = 10, M = 5, O = 5;

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


	//create list 2

	//create first node with value 1, points to null
	link t2 = new node(10, 0);

	//first node now points to itself
	t2->next = t2;

	//x is a copy of the first node
	link x2 = t2;

	//create N number of nodes after first node
	for (int i = 1; i < M; i++) {

		//1.create new node that points to first node, 
		//2.current node points to newly created node, 
		//3.currrent node is the newly created node
		int num = i + 10;
		x2 = (x2->next = new node(num, t2));
	}

	//create list 3

	//create first node with value 1, points to null
	link t3 = new node(15, 0);

	//first node now points to itself
	t3->next = t3;

	//x is a copy of the first node
	link x3 = t3;

	//create N number of nodes after first node
	for (int i = 1; i < O; i++) {

		//1.create new node that points to first node, 
		//2.current node points to newly created node, 
		//3.currrent node is the newly created node
		int num = i + 15;
		x3 = (x3->next = new node(num, t3));
	}

	std::cout << "current item: " << Circular_list_position_swap(x, x->next->next->next)->item << std::endl;;

	return 0;
}