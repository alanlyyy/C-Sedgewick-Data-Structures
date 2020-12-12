#include <iostream>
#include "Node.h"


//create a class that controls functionalities of singly linked list
class singly_list_circular{

public:
	void insert(int item) {

		//insert a new node starting from head, update current node tracker
		current = (current->next = new node(item, head));
	}

	void print_nodes() {
		//starting at the header node, print all nodes upto the tail node.
		node* t = head->next;

		while (t!= tail) {
			std::cout << t->item << std::endl;
			t = t->next;
		}
	}
private:
	node* head = new node(0, 0);
	node* tail = head;

	node* current = head;
};

int main_ex_3_45() {

	singly_list_circular* ll = new singly_list_circular;

	ll->insert(1);
	ll->insert(2);
	ll->insert(3);
	ll->insert(4);
	ll->insert(5);

	ll->print_nodes();


	return 0;
}