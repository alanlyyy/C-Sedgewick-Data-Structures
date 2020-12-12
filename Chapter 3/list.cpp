//list implementation that contains all definition for declarations found in list.h interface
#include "list.h"
#include <stdlib.h>
#include <iostream>
#include <exception>

link freelist; //free list = node*

void construct(int N) {
	//allocate space for N number of nodes
	
	//allocate space for node array for N nodes and 1 header node.
	freelist = new node[N + 1];

	for (int i = 0; i < N; i++) {

		//for each empty node point to the next empty node in the next index of array
		freelist[i].next = &freelist[i + 1];
	}

	//last node points to a null ptr
	freelist[N].next = 0;
}

link newNode(int i) {
	link x = remove(freelist);
	x->item = i;
	x->next = x;
	return x;
}

void deleteNode(link x) {
	insert(freelist, x);
}

void insert(link x, link t) {
	t->next = x->next;
	x->next = t;
}

link remove(link x) {
	link t = x->next; 
	x->next = t->next;
	return t;
}

link next(link x) {
	return x->next;
}

Item item(link x) {
	return x->item;
}

void print_nodes(node** header_node) {
	//print the nodes

	//if first node is a nullptr break out of function.
	if (*header_node == 0) {
		return;
	}

	node* p_node = (*header_node)->next;
	std::cout << p_node->item << std::endl;
	while (p_node != *header_node) {
		std::cout << p_node->next->item << std::endl;
		p_node = p_node->next;
	}
}

void print_free_list() {

	link t = freelist;
	while (t != 0) {
		std::cout << t->item << std::endl;
		t = t->next;
	}
}