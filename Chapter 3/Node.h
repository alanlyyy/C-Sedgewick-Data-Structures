#pragma once
//class used to store node interface

class node
{
//node structure for singly linked list
public:
	//stores node value
	int item;

	//stores pointer to next node
	node* next;

	//node constructor, t is next node
	node(int x, node* t);
};

typedef node* link;


struct Node_doubly {
	//node structure for doubly linked list
	Node_doubly(int x, Node_doubly* prev_node, Node_doubly* next_node);

	int item;
	Node_doubly* next;
	Node_doubly* prev;
};


link generate_random_nodes(int size, link header);

void generate_nodes_doubly(Node_doubly** control_node, int size);

link generate_random_nodes_circular_list(int size, link header);

link generate_sequential_circular_list(int size, link header);

void generate_sequential_circular_list2(int size, link* header);

link arr_to_list(int* p, int size, link header);

link reversal(link x);

void doubly_node_swap(Node_doubly* node1, Node_doubly* node2);

void print_nodes(link header);

void print_nodes(Node_doubly** control_node);

void print_nodes_circular_list(link first_node);

link insertion_sort(link headera);

void sortedInsert2(link* head_ref, link new_node);

void insertionSort2(link* head_ref);