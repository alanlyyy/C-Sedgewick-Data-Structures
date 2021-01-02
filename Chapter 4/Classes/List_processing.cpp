//list_processing implementation
#include "List_processing.h"

void list_processing::construct(int N) {
	freelist = new node[N + 1];

	for (int i = 0; i < N; i++) {
		freelist[i].next = &freelist[i + 1];
	}
	freelist[N].next = 0;
}

node* list_processing::newNode(int i) {
	node* x = remove(freelist);
	x->item = i; x->next = x;
	return x;
}

void list_processing::deleteNode(node* x) {
	insert(freelist, x);
}
void list_processing::insert(node* x, node* t) {
	t->next = x->next;
	x->next = t;
}
node* list_processing::remove(node* x) {
	node* t = x->next;
	x->next = t->next;
	return t;
}
node* list_processing::next(node* x) {
	return x->next;
}

Item list_processing::item(node* x) {
	return x->item;
}

void list_processing::deleteNode_from_linked_list(node* x) {
	//takes node returned by removeNode() and inserts node into the freelist.

	insert_freeList(x);
}
void list_processing::insert_linkedList(node* t) {
	//insert node into linked list
	t->next = current_node->next;
	current_node->next = t;
}
void list_processing::insert_freeList(node* t) {
	//insert node into free list for empty node management.
	t->next = freelist->next;
	freelist->next = t;
}

node* list_processing::remove_current_node() {
	//takes the current node and removes from from linked list
	//returns removed node to be inserted into freelist
	node* t = current_node->next;
	current_node->next = t->next;
	return t;
}

node* list_processing::traverse_next_node() {
	//moves to next node, returns updated node;
	current_node = current_node->next;
	return current_node;
}

node* list_processing::get_current() {
	return current_node;
}

void list_processing::set_first_node(node* first_node) {
	current_node = first_node;
	current_node->next = current_node;
}