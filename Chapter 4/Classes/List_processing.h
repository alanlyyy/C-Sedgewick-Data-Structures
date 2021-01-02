#pragma once
typedef int Item;

struct node {
	Item item; node* next;
};

class list_processing {
	//list processing ADT interface
public:

	void construct(int);
	node* newNode(int);
	void deleteNode(node*);
	void insert(node*, node*);
	node* remove(node*);
	node* next(node*);
	Item item(node*);

	//new functions for Linked List ADT
	node* get_current();
	void set_first_node(node*);
	void insert_linkedList(node*);	//insert node into linkedlist, tracked by current_node
	void insert_freeList(node*); //insert node into freeList, tracked by freeList
	void deleteNode_from_linked_list(node* x); //delete node from linked list and inserts into freelist
	node* remove_current_node(); //removes the current node, returned node is an argument for deleteNode_from_linked_list
	node* traverse_next_node(); //move to next node;
private:
	node* freelist; //freelist is managed in this interface
	node* current_node;
};
