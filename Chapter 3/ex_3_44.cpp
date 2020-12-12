#include <iostream>
#include "Node.h"


//create a class that controls functionalities of singly linked list
class singly_list{

public:
	void insert(int item) {
		
		//insert a new node starting from head, update current node tracker
		current = (current->next = new node(item, 0));

		//the last node points back to itself
		current->next = current;

		//tail points to the last node
		tail = current;
	}

	void print_nodes() {
		//starting at the header node, print all nodes upto the tail node.
		node* t = head;

		while (t != tail) {
			std::cout << t->next->item << std::endl;
			t = t->next;
		}
	}
private:
	node* head = new node(0,0);
	node* tail;

	node* current = head;
};

int main_3_44() {

	singly_list* ll = new singly_list;

	ll->insert(1);
	ll->insert(2);
	ll->insert(3);
	ll->insert(4);
	ll->insert(5);

	ll->print_nodes();

	
	return 0;
}

