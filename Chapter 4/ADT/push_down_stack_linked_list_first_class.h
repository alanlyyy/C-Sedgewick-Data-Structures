#pragma once
#include <iostream>
template <class Item>
class Push_down_stack_linked_list {

private:
	struct node
	{
		Item item;
		node* next;

		node(Item x, node* t) {
			item = x;
			next = t;
		}
	};
	typedef node* link;

private:
	link head;
	int size = 0;

	void clear_stack() {
		//clear content/ deallocate resources from s
		for (link t = head; t != 0; head = t) {
			t = head->next;
			delete head;
		}

		std::cout << "Destructor invoked!" << std::endl;
	}
public:
	Push_down_stack_linked_list(int); //default constructor initialize head pointer
	Push_down_stack_linked_list(const Push_down_stack_linked_list&); //copy constructor
	Push_down_stack_linked_list& operator=(const Push_down_stack_linked_list&); //copy operator
	~Push_down_stack_linked_list();	//destructor
	int empty();
	void push(Item);
	Item pop();
	void print_elements();
};

template <class Item>
Push_down_stack_linked_list<Item>::Push_down_stack_linked_list(int) {
	head = 0;
}

template <class Item>
Push_down_stack_linked_list<Item>::Push_down_stack_linked_list(const Push_down_stack_linked_list& other) {
	
	//deallocate existing memory
	clear_stack();

	//create a temp stack to push items into current stack in original order.
	Push_down_stack_linked_list<Item> temp_stack(1);

	//copy nodes from "other" list to current linked list
	link t = other.head;
	while (t != 0) {
		temp_stack.push(t->item);
		t =t->next;
	}


	t = temp_stack.head;
	while (t != 0) {
		push(t->item);
		t = t->next;
	}

}

template <class Item>
Push_down_stack_linked_list<Item>& Push_down_stack_linked_list<Item>::operator=(const Push_down_stack_linked_list& other) {
	//copy operator

	if (this == &other) {
		return *this;
	}

	//deallocate existing memory
	clear_stack();

	//create a temp stack to push items into current stack in original order.
	Push_down_stack_linked_list<Item> temp_stack(1);

	//copy nodes from "other" list to current linked list
	link t = other.head;
	while (t != 0) {
		temp_stack.push(t->item);
		t = t->next;
	}

	t = temp_stack.head;
	while (t != 0) {
		push(t->item);
		t = t->next;
	}

	return *this;

}

template <class Item>
Push_down_stack_linked_list<Item>::~Push_down_stack_linked_list(){

	//deallocate existing memory
	clear_stack();

}
template <class Item>
int Push_down_stack_linked_list<Item>::empty() {
	return head == 0;
}

template <class Item>
void Push_down_stack_linked_list<Item>::push(Item x) {

	try {
		head = new node(x, head);
		size += 1;
	}
	catch (std::bad_alloc& ba) {
		std::cout << "bad allocation caught " << ba.what() << std::endl;
	}
}

template <class Item>
Item Push_down_stack_linked_list<Item>::pop() {

	if (!empty()) {
		Item v = head->item; link t = head->next;
		delete head;
		head = t;
		size -= 1;
		return v;
	}
	else {
		return 0;
	}
}


template <class Item>
void Push_down_stack_linked_list<Item>::print_elements() {
	node* t = head;

	while (t != 0) {
		std::cout << t->item << " ";
		t = t->next;
	}
	std::cout << std::endl;
}