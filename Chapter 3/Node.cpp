//node implementation 
#include "Node.h"
#include <cmath>
#include <time.h>
#include <iostream>

//node constructor, t is next node
node::node(int x, node* t) {

	item = x;

	next = t;
};

//node constructor for doubly linked list
Node_doubly::Node_doubly(int x, Node_doubly* prev_node, Node_doubly* next_node) {
	item = x;
	next = next_node;
	prev = prev_node;
};


link generate_random_nodes(int size, link header) {
	//generate a linked list of random numbers

	//generate random number seed
	srand(time(0));

	//a and t is a pointer to header node
	link a = header, t = a;

	//insert size count number of elements into list
	for (int i = 0; i < size; i++) {
		t = (t->next = new node(rand() % 1000, 0));
	}

	//return header node a
	return a;
}

void generate_nodes_doubly(Node_doubly** control_node, int size) {

	//create M nodes for the linked list, control_node still points to the pointer of the first node found in the list.
	//generated nodes are retained outside the function.

	Node_doubly* t = *control_node;

	for (int i = 2; i < size; i++) {
		t = (t->next = new Node_doubly(i, t, 0));
	}
}

link generate_random_nodes_circular_list(int size, link header) {

	//pass in empty node or null ptr, rerturn a circular linked list

	//generate random number seed
	srand(time(0));

	//a and t is a pointer to header node
	link a = header;

	//a overwrites header which is a nullptr
	a = new node(rand() % 1000, 0);

	a->next = a;

	link t = a;

	//insert size count number of elements into list
	for (int i = 1; i < size; i++) {

		//generate new nodes, traverse to new node, new node points back to first node
		t = t->next = new node(rand() % 1000, a);
	}

	return a;
}

link generate_sequential_circular_list(int size, link header) {

	//pass in empty node or null ptr, rerturn a circular linked list

	//return a node pointer to last node  in list 

	//a overwrites header which is a nullptr
	link a = new node(1, 0);

	a->next = a;

	link t = a;

	//insert size count number of elements into list
	for (int i = 2; i <= size; i++) {

		//generate new nodes, traverse to new node, new node points back to first node
		t = t->next = new node(i, a);
	}

	//node pointer header is last node in the circular linked list
	header = t;

	return header;
}

void generate_sequential_circular_list2(int size, link * header) {
	//pass in empty null ptr of type node* , retain all changes to link * header.


	link a = new node(1, 0);

	a->next = *header;

	*header = a;

	a->next = a;

	link t = a;


	//insert size count number of elements into list
	for (int i = 2; i <= size; i++) {

		//generate new nodes, traverse to new node, new node points back to first node
		t = t->next = new node(i, a);
	}

	//node pointer points now points to last node in the circular linked list
	*header = t;
}

link arr_to_list(int* p, int size, link header) {
	//converts array to list

	//create a header node
	//node heada(0, 0);

	//a and t is a pointer to header node
	link d = header, t = d;

	//insert size count number of elements into list
	for (int i = 0; i < size; i++) {

		//create a node using p value
		t = (t->next = new node(p[i], 0));
	}

	return d;
}

link reversal(link x) {
	//reverses links in a list, returns a pointer to the final node which points 2nd to last node, and etc.
	//head node points to 0

	link t, y = x, r = 0;

	while (y != 0) {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}

void print_nodes(link header) {

	link t = header->next;

	while (t != 0) {
		std::cout << t->item << std::endl;

		t = t->next;
	}
}

void print_nodes(Node_doubly** control_node) {

	//pass in a pointer to node pointer to print all nodes found in linked list.

	Node_doubly* t = (*control_node);

	while (t != 0) {
		std::cout << t->item << std::endl;

		t = t->next;
	}
}

void print_nodes_circular_list(link first_node) {

	//if first element print item and traverse to next node
	link t = first_node;

	std::cout << t->item << std::endl;

	t = t->next;

	//keep printing nodes until we traverse back to first node
	while (t != first_node) {
		std::cout << t->item << std::endl;

		t = t->next;
	}
}

link insertion_sort(link headera) {

	//Must pass in headera node,unsorted list 
	//the linked list generated inside the function scope is saved through headera
	//otherwise the reference to the sorted list is destroyed after the function scope is completed.

	link a = headera, t = a;
	//link u = t;

	node headb(0, 0);
	link u, x, b = &headb;

	for (t = a->next; t != 0; t = u) {

		u = t->next;
		//traverse entire list until we find node that is greater than current item
		for (x = b; x->next != 0; x = x->next) {

			//if current node is smaller than traverse node break.
			if (x->next->item > t->item) {
				break;
			}
		}

		//swap the 2 nodes
		t->next = x->next;
		x->next = t;

	}

	//after removing all elements from headera and sorting them into headerb
	//we set headera to point to headerb list.
	headera->next = b->next;

	//return link headera
	return headera;
}

void sortedInsert2(link* head_ref, link new_node)
{

	link current;

	/* Special case for the head end */

	//if head node item >= new_node item
	if (*head_ref == NULL || (*head_ref)->item >= new_node->item)
	{
		//add new node to list
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL &&
			current->next->item < new_node->item)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}

}
// function to sort a singly linked list using insertion sort 
void insertionSort2(link* head_ref)
{
	//head_ref is a pointer to node pointer

	// Initialize sorted linked list 
	link sorted = NULL;

	// Traverse the given linked list and insert every 
	// node to sorted 

	//current is pointer to header node
	link current = *head_ref;

	while (current != NULL)
	{
		// Store next for next iteration 
		link next = current->next;

		// insert current in sorted linked list 
		sortedInsert2(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}

void doubly_node_swap(Node_doubly* node1, Node_doubly* node2) {


	Node_doubly* temp;

	//p_node is a pointer to the first node
	//Node_doubly* p_node = *control_node;


	//if both nodes are the same don't do anything
	if (node1 == node2) {
		return;
	}

	//if node2 comes before node1, swap pointers for node1 and node2
	if (node2->next == node1) {
		temp = node1;
		node1 = node2;
		node2 = temp;
	}

	Node_doubly* prev_node = node1->prev;
	Node_doubly* next_node = node1->next;
	Node_doubly* current_node1 = node1;

	Node_doubly* prev_node2 = node2->prev;
	Node_doubly* next_node2 = node2->next;
	Node_doubly* current_node2 = node1;


	//if node1 and node2 are adjacent to one another
	if ((node1->next == node2 && node2->prev == node1)
		|| (node1->prev == node2 && node2->next == node1))
	{
		node1->prev = next_node;
		node2->prev = prev_node;
		node1->next = next_node2;
		node2->next = prev_node2;

	}
	//if nodes are not adjacent
	else {
		node1->prev = prev_node2;
		node2->prev = prev_node;
		node1->next = next_node2;
		node2->next = next_node;
	}


	//after swapping node1 and node2, adjust pointers of prev and next nodes
	//to point back to the newly swapped nodes.
	if (node1->prev != 0) {
		node1->prev->next = node1;
	}
	if (node1->next != 0) {
		node1->next->prev = node1;
	}

	if (node2->prev != 0) {
		node2->prev->next = node2;
	}
	if (node2->next != 0) {
		node2->next->prev = node2;
	}
}