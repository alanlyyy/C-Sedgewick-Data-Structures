#pragma once
//interface for linked list to process nodes
typedef int Item;

struct node {
	Item item;
	node* next;
};

typedef node* link;
typedef link Node;

void construct(int);

Node newNode(int);

void deleteNode(Node);

void insert(Node, Node);

Node remove(Node);

Node next(Node);

Item item(Node);

void print_nodes(node** header_node);

void print_free_list();

void josephus_list_allocation(int, int);

int test();