#pragma once

struct node
{
	int item;
	node* next;
	node(int x, node* t)
	{
		item = x;
		next = t;
	}
};

typedef node* link;

struct doubly_node
{
	int item;

	doubly_node* next;
	doubly_node* prev;

	doubly_node(int x, doubly_node* t, doubly_node* tf)
	{
		item = x;
		next = tf;
		prev = t;
	}
};

typedef doubly_node* link_doubly;

void print_nodes(doubly_node* curr_node) {

	std::cout << curr_node->item << " ";

	curr_node = curr_node->next;

	while (curr_node != 0) {
		std::cout << curr_node->item << " ";
		curr_node = curr_node->next;
	}

	std::cout << std::endl;
}

void print_nodes_reverse(doubly_node* curr_node) {

	std::cout << curr_node->item << " ";

	curr_node = curr_node->prev;

	while (curr_node != 0) {
		std::cout << curr_node->item << " ";
		curr_node = curr_node->prev;
	}

	std::cout << std::endl;
}