#pragma once
//implement list processing interface for for exercise 3.49

typedef int Item2;
struct node2 {
	Item2 item;
	node2* next;

	//constructor object
	node2(Item2, node2*);

	//destructor object
	~node2();
};

typedef node2* link2;
typedef link2 Node2;

//void construct(int);

Node2 newNode2(int);
void deleteNode2(Node2);
//void insert(Node, Node);
//Node remove(Node);
//Node next(Node);
//Item item(Node);