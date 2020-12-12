#include <iostream>
#include "list_stl.h"


//destructor
node2::~node2() {
	//delete node2 object 
	std::cout << "current deleted node: " << this->item << std::endl;
};

node2::node2(Item2 val, node2* next_node) {
	item = val;
	next = next_node;
};

link2 newNode2(int i) {

	link2 created_node = new node2(i, 0);
	return created_node;
};

void deleteNode2(Node2 x) {
	delete x;
	x = nullptr;
};

