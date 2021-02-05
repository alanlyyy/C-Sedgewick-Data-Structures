#include <iostream>

struct node3
{
	int item;

	node3* next;
	node3* prev;

	node3(int x, node3* t, node3* tf)
	{
		item = x;
		next = tf;
		prev = t;
	}
};

typedef node3* link;

//global node
link head = new node3(1, 0, 0);
link tail;
link traverse_head = head;
link traverse_tail = tail;
link curr = head;
link prev = head->prev;
int size = 0;
link reverse;

void print_nodes(node3* curr_node) {
	
	std::cout << curr_node->item << " ";

	curr_node = curr_node->next;

	while (curr_node != 0) {
		std::cout << curr_node->item << " ";
		curr_node = curr_node->next;
	}

	std::cout << std::endl;
}

void print_nodes_reverse(node3* curr_node) {

	std::cout << curr_node->item << " ";

	curr_node = curr_node->prev;

	while (curr_node != 0) {
		std::cout << curr_node->item << " ";
		curr_node = curr_node->prev;
	}

	std::cout << std::endl;
}

void create_list3(int N) {
	//create a list of N nodes
	
	for (int i = 2; i <= N; i++) {
		traverse_head = (traverse_head->next) = new node3(i, traverse_head, 0);
		size++;
	}

	//link tail pointers
	tail = traverse_head;

	traverse_tail = tail;
	traverse_head = head;
}

node3* reverse_linked_list() {

	//reverse linked list items for doubly linked list

	if (traverse_head == 0) {
		return reverse;
	}
	else {

		//if head node is null, currently as first node
		if (traverse_head->prev == 0)
		{
			reverse = new node3(traverse_head->item, 0, 0);
		}

		//if not first node append new node to front of existing node
		else {

			//new node next points to previous node, update previtious node pointer, move up the list
			reverse = reverse->prev = new node3(traverse_head->item, 0, reverse);
		}

		traverse_head = traverse_head->next;

		return reverse_linked_list();

	}
}
node3* reverse_linked_list_nodes() {

	//reverse linked list nodes for doubly linked list

	if (traverse_head == 0) {
		return prev;
	}
	else {

		//store next node of current node
		traverse_head = curr->next;

		//current node node points to previous node
		curr->next = prev;

		//previous node of current node is now next node
		curr->prev = traverse_head;

		//update new previous node
		prev = curr;

		//move to node ahead of current node
		curr = traverse_head;

		return reverse_linked_list_nodes();

	}
}
int main_5_15() {
	create_list3(9);
	link p = reverse_linked_list_nodes();
	print_nodes(p);
	print_nodes_reverse(head);
	return 0;
}