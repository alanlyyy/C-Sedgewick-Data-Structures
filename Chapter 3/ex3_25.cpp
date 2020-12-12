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

node * Circular_list_insertion(node* current_node, node* other_node) {
	////insert contents of list other_node into list current_node at point current_node

	//start node is copy of next node current node is pointing to
	link insert_node = other_node->next;

	//used to traverse/update current_node list, stores all changes made by insertion of node
	link track_node_current = current_node;

	//from current_node to end = other_node
	while (insert_node != other_node) {

		//insertion

		//create a new node with other node
		link new_node = new node(insert_node->item, insert_node->next);

		//new node now points to the node current node is pointing to
		new_node->next = track_node_current->next;

		//the node that current node is pointing to now points to new node.
		track_node_current->next = new_node;

		//traverse to next next other node
		insert_node = insert_node->next;

		//std::cout << track_node_current ->item  << " next:  " << track_node_current->next->item << " ";

	}
	std::cout << std::endl;

	//start node
	node* reference = current_node->next;

	//print all nodes
	while ( reference != current_node) {
		std::cout << reference->item << " ";

		//traverse to next node
		reference = reference->next;
	}

	std::cout << std::endl;


	return current_node;
}

int main_3_25() {

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

	std::cout << "current item: " << Circular_list_insertion(x, x2)->item << std::endl;;
	std::cout << "current item: " << Circular_list_insertion(x2, x3)->item << std::endl;;

	return 0;
}